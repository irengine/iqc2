#include "iqcapplication.h"
#include "iqcmainwindow.h"
#include <QDebug>
#include <QSplashScreen>

QCoreApplication* createApplication(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
        if (!qstrcmp(argv[i], "-debug"))
            return new QCoreApplication(argc, argv);
    return new IqcApplication(argc, argv);
}

int main(int argc, char* argv[])
{
    QScopedPointer<QCoreApplication> app(createApplication(argc, argv));

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

