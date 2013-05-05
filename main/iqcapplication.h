#ifndef IQCAPPLICATION_H
#define IQCAPPLICATION_H

#include <QApplication>
#include <QtSql>

// Exception handling
// Database access
// Global setting
class IqcApplication : public QApplication
{
    Q_OBJECT

public:
    IqcApplication(int & argc, char ** argv);
    ~IqcApplication();

    bool notify(QObject * receiver, QEvent * event);

    QSqlDatabase& getConnection();
private:
    QSqlDatabase db;
};

#endif // IQCAPPLICATION_H
