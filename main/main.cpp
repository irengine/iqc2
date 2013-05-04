#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

QCoreApplication* createApplication(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
        if (!qstrcmp(argv[i], "-debug"))
            return new QCoreApplication(argc, argv);
    return new QApplication(argc, argv);
}

int main(int argc, char* argv[])
{
    QScopedPointer<QCoreApplication> app(createApplication(argc, argv));

    if (qobject_cast<QApplication *>(app.data())) {
        qDebug() << "release version.";

        // entry point here
        MainWindow w;
        w.show();

        return app->exec();
    } else {
        qDebug() << "debug version.";
        return 0;
    }
}

