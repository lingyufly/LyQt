#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "userinfo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    login=new Login(this);

    userinfoTab=new UserInfo();
    ui->tabWidget->addTab(userinfoTab,QString("UserInfo"));

    mouseTab=new Mouse();
    ui->tabWidget->addTab(mouseTab, QString("Mouse"));
}

void MainWindow::show()
{
    QMainWindow::show();
    if (login->exec()==QDialog::Accepted)
    {
        return;
    }
    else
    {
        this->close();
    }

    return;
}

MainWindow::~MainWindow()
{
    delete ui;
}
