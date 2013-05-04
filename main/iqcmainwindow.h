#ifndef IQCMAINWINDOW_H
#define IQCMAINWINDOW_H

#include <QMainWindow>

class QAction;
class QMenu;
class QToolBar;
class QLabel;

class IqcMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    IqcMainWindow(QWidget *parent = 0);
    ~IqcMainWindow();

//protected:
//    void closeEvent(QCloseEvent *event);

private slots:
    void newTest();
    void openTest();
    void moreTest();
    void about();

private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();

    QLabel *userLabel;

    QMenu *testMenu;
    QMenu *helpMenu;

    QToolBar *testToolBar;

    QAction *separatorAction;

    QAction *newTestAction;
    QAction *openTestAction;
    QAction *moreTestAction;
    QAction *aboutAction;
    QAction *aboutQtAction;
};

#endif // IQCMAINWINDOW_H
