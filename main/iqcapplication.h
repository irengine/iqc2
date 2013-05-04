#ifndef IQCAPPLICATION_H
#define IQCAPPLICATION_H

#include <QApplication>

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
};

#endif // IQCAPPLICATION_H
