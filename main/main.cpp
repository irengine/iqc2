#include "iqcapplication.h"
#include "iqcmainwindow.h"
#include "../lib/qslog/QsLog.h"
#include "../lib/qslog/QsLogDest.h"
#include <QDir>
#include <QDebug>
#include <QSplashScreen>

QCoreApplication* createApplication(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
        if (!qstrcmp(argv[i], "-debug"))
            return new QCoreApplication(argc, argv);
    return new IqcApplication(argc, argv);
}

void testLog()
{
    // init the logging mechanism
    QsLogging::Logger& logger = QsLogging::Logger::instance();
    logger.setLoggingLevel(QsLogging::TraceLevel);
    const QString sLogPath(QDir(qApp->applicationDirPath()).filePath("iqc.log"));
    QsLogging::DestinationPtr fileDestination(
       QsLogging::DestinationFactory::MakeFileDestination(sLogPath) );
    QsLogging::DestinationPtr debugDestination(
       QsLogging::DestinationFactory::MakeDebugOutputDestination() );
    logger.addDestination(debugDestination.get());
    logger.addDestination(fileDestination.get());
//    logger.setLoggingLevel(QsLogging::InfoLevel);

    QLOG_INFO() << "Built with Qt" << QT_VERSION_STR << "running on" << qVersion();

    QLOG_TRACE() << "Here's a" << QString("trace") << "message";
    QLOG_DEBUG() << "Here's a" << static_cast<int>(QsLogging::DebugLevel) << "message";
    QLOG_WARN()  << "Uh-oh!";
    qDebug() << "This message won't be picked up by the logger";
    QLOG_ERROR() << "An error has occurred";
    qWarning() << "Neither will this one";
    QLOG_FATAL() << "Fatal error!";
}

int main(int argc, char* argv[])
{
    QScopedPointer<QCoreApplication> app(createApplication(argc, argv));

    testLog();

    if (qobject_cast<IqcApplication *>(app.data())) {
        qDebug() << "release version.";

        // splash screen
        QSplashScreen *splash = new QSplashScreen;
        splash->setPixmap(QPixmap(":/images/splash.png"));
        splash->show();

        app->processEvents();
        sleep(1);

        Qt::Alignment bc = Qt::AlignBottom | Qt::AlignCenter;

        splash->showMessage(QObject::tr("Initializing..."), bc, Qt::white);
        IqcMainWindow w;

        splash->showMessage(QObject::tr("Loading data..."), bc, Qt::white);

        splash->showMessage(QObject::tr("Loading plugins..."), bc, Qt::white);

        w.showMaximized();
        splash->finish(&w);
        delete splash;

        return app->exec();
    } else {
        qDebug() << "debug version.";
        return 0;
    }
}

