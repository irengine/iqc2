#ifndef IQCMAINWINDOW_H
#define IQCMAINWINDOW_H

#include <QMainWindow>

class IqcMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    IqcMainWindow(QWidget *parent = 0);
    ~IqcMainWindow();
};

#endif // IQCMAINWINDOW_H
