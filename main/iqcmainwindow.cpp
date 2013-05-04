#include <QtWidgets>
#include "iqcmainwindow.h"

IqcMainWindow::IqcMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    setWindowIcon(QIcon(":/images/icon.png"));
}

IqcMainWindow::~IqcMainWindow()
{
}

void IqcMainWindow::createActions()
{
    newTestAction = new QAction(tr("&New"), this);
    newTestAction->setIcon(QIcon(":/images/new.png"));
    newTestAction->setShortcut(QKeySequence::New);
    newTestAction->setStatusTip(tr("Create a new test"));
    connect(newTestAction, SIGNAL(triggered()), this, SLOT(newTest()));

    openTestAction = new QAction(tr("&Open..."), this);
    openTestAction->setIcon(QIcon(":/images/open.png"));
    openTestAction->setShortcut(QKeySequence::Open);
    openTestAction->setStatusTip(tr("Open an existing test"));
    connect(openTestAction, SIGNAL(triggered()), this, SLOT(openTest()));

    moreTestAction = new QAction(tr("......"), this);
    moreTestAction->setStatusTip(tr("More test......"));
    connect(moreTestAction, SIGNAL(triggered()), this, SLOT(moreTest()));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show the application's About box"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void IqcMainWindow::createMenus()
{
    testMenu = menuBar()->addMenu(tr("&Test"));
    testMenu->addAction(newTestAction);
    testMenu->addAction(openTestAction);
    testMenu->addSeparator();
    testMenu->addAction(moreTestAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void IqcMainWindow::createContextMenu()
{

}

void IqcMainWindow::createToolBars()
{
    testToolBar = addToolBar(tr("&Test"));
    testToolBar->addAction(newTestAction);
    testToolBar->addAction(openTestAction);
}

void IqcMainWindow::createStatusBar()
{
    userLabel = new QLabel(" Alex Tang ");
    userLabel->setAlignment(Qt::AlignHCenter);
    userLabel->setMinimumSize(userLabel->sizeHint());

    statusBar()->addWidget(userLabel);
}

void IqcMainWindow::newTest()
{

}

void IqcMainWindow::openTest()
{

}

void IqcMainWindow::moreTest()
{

}

void IqcMainWindow::about()
{
    QMessageBox::about(this, tr("About IQC System"),
            tr("<h2>IQC System 1.0</h2>"
               "<p>Copyright &copy; 2013 TAO Software Inc."));
}

