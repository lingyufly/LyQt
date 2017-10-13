#include "login.h"
#include "ui_login.h"
#include <QSettings>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->passledit->setEchoMode(QLineEdit::Password);
    connect(ui->loginbtn, SIGNAL(clicked()), this, SLOT(checkuserandpass()));
    connect(ui->exitbtn, SIGNAL(clicked()), this, SLOT(reject()));
    users=new QMap<QString, QString>();

    ui->userledit->setText("ly");
    ui->passledit->setText("ly123.");
    if (loadusers()==0)
    {
        QMessageBox::warning(this, "warn", "没有用户信息");
    }
}

Login::~Login()
{
    delete ui;
    delete users;
}

void Login::checkuserandpass()
{
    QString user=ui->userledit->text();
    QString pass=ui->passledit->text();
    if (users->size()==0 && user=="admin" && pass=="admin")
    {
        emit senduserandpass(user, pass);
        this->accept();
        return;
    }
    if (users->find(user)!=users->end() && users->find(user).value()==pass)
    {
        emit senduserandpass(user, pass);
        this->accept();
        return;
    }
    else
    {
        QMessageBox::warning(this, "error", "用户名或密码错误");
    }
}

int Login::loadusers()
{
    QSettings *settings=new QSettings("ini/settings.ini", QSettings::IniFormat);

    int len=settings->beginReadArray("login");
    for (int i=0; i<len; i++)
    {
        settings->setArrayIndex(i);
        qDebug()<<settings->value("user").toString()<<":"<<settings->value("pass").toString();
        users->insert(settings->value("user").toString(),settings->value("pass").toString());
    }
    settings->endArray();
    delete settings;
    return len;
}

