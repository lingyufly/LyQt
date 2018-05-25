#include "mainwindow.h"
#include "login.h"
#include "userinfo.h"
#include <QHBoxLayout>
#include <QTabWidget>
#include <QWidget>
#include <QApplication>

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
    m_login = new Login(this);
    if (m_login->exec() == QDialog::Accepted)
    {
        delete m_login;
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
    m_centerWidget = new QWidget(this);
    setCentralWidget(m_centerWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(m_centerWidget);
    m_tabWidget = new QTabWidget(m_centerWidget);
    mainLayout->addWidget(m_tabWidget);

    m_userinfoTab = new UserInfo();
    m_tabWidget->addTab(m_userinfoTab, QString("UserInfo"));

    m_mouseTab = new Mouse();
    m_tabWidget->addTab(m_mouseTab, QString("Mouse"));

    m_qtreewidgettwgt = new TestQTreeWidgetWidget();
    m_tabWidget->addTab(m_qtreewidgettwgt, QString("QTreeWidget"));
}