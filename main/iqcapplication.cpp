#include "iqcapplication.h"

IqcApplication::IqcApplication(int & argc, char ** argv)
    :QApplication(argc, argv)
{
}

IqcApplication::~IqcApplication()
{
}

bool IqcApplication::notify(QObject* receiver, QEvent* event)
{
    try {
        return QApplication::notify(receiver, event);
    } catch (std::exception &e) {
        qFatal("Error %s sending event %s to object %s (%s)",
            e.what(), typeid(*event).name(), qPrintable(receiver->objectName()),
            typeid(*receiver).name());
    } catch (...) {
        qFatal("Error <unknown> sending event %s to object %s (%s)",
            typeid(*event).name(), qPrintable(receiver->objectName()),
            typeid(*receiver).name());
    }

    // qFatal aborts, so this isn't really necessary
    // but you might continue if you use a different logging lib
    return false;
}

QSqlDatabase& IqcApplication::getConnection()
{
    if (!db.isOpen() || !db.isValid())
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("iqc.dat");

        if (!db.open()) {
//            QMessageBox::warning(0, QObject::tr("Database Error"),
//                                 db.lastError().text());
            throw;
        }
    }
    return db;
}
