#include "mainwindow.h"
#include <QHBoxLayout>
#include <QTabWidget>
#include <QWidget>
#include <QApplication>
#include <QAction>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi();
}



MainWindow::~MainWindow()
{
}


bool MainWindow::login()
{
    m_loginDlg = new Login(NULL);
    if (m_loginDlg->exec() == QDialog::Accepted)
    {
        delete m_loginDlg;
        return true;
    }
    else
    {
        close();
        qApp->quit();
        return false;
    }
}

void MainWindow::setupUi()
{
    resize(800, 600);

    QToolBar *toolbar = new QToolBar(this);
    addToolBar(toolbar);
    QAction *action1 = new QAction("Action1", this);
    action1->setObjectName("action1");
    toolbar->addAction(action1);
    connect(action1, &QAction::toggled, this, &MainWindow::slot_toggled);
    connect(action1, &QAction::triggered, this, &MainWindow::slot_triggered);

    QAction *action2 = new QAction("Action2", this);
    action2->setObjectName("action2");
    toolbar->addAction(action2);
    action2->setCheckable(true);
    connect(action2, &QAction::toggled, this, &MainWindow::slot_toggled);
    connect(action2, &QAction::triggered, this, &MainWindow::slot_triggered);

    QMenuBar *m_menuBar = menuBar();
    QMenu *m_fileMenu = new QMenu("File", this);
    m_fileMenu->addAction(action1);
    m_fileMenu->addAction(action2);
    m_menuBar->addMenu(m_fileMenu);

    toolbar->addAction(m_fileMenu->menuAction());

    m_centerWidget = new QWidget(this);
    setCentralWidget(m_centerWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(m_centerWidget);
    m_tabWidget = new QTabWidget(m_centerWidget);
    mainLayout->addWidget(m_tabWidget);

    m_userinfoWidget = new UserInfo();
    m_tabWidget->addTab(m_userinfoWidget, QString("UserInfo"));

    m_mouseWidget = new Mouse();
    m_tabWidget->addTab(m_mouseWidget, QString("Mouse"));

    m_qtreewidgettWidget = new TestQTreeWidgetWidget();
    m_tabWidget->addTab(m_qtreewidgettWidget, QString("QTreeWidget"));

    m_testWidget = new TestWidget();
    m_tabWidget->addTab(m_testWidget, QString("TestWidget"));

    m_qstackedwidgetWidget = new TestQStackedWidget();
    m_tabWidget->addTab(m_qstackedwidgetWidget, QString("TestQStackedWidget"));
}

void MainWindow::slot_toggled(bool state)
{
    qDebug() << "toggled   render:" << sender()->objectName() << "\t state:" << state;
}

void MainWindow::slot_triggered(bool state)
{
    qDebug() << "triggered render:" << sender()->objectName() << "\t state:" << state;
}