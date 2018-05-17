#include "login.h"
#include "ui_login.h"
#include <QSettings>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QHBoxLayout>

Login::Login(QWidget *parent) :
    QDialog(parent)
{
    setupUi();
    m_users=new QMap<QString, QString>();

    m_userLineEdit->setText("ly");
    m_passLineEdit->setText("ly123.");
    if (loadusers()==0)
    {
        QMessageBox::warning(this, "warn", "没有用户信息");
    }
}

Login::~Login()
{
    delete m_users;
}

void Login::setupUi()
{
    QVBoxLayout *mainlayout = new QVBoxLayout(this);
    QHBoxLayout *hbox = new QHBoxLayout();
    QLabel *label = new QLabel("User:");
    m_userLineEdit = new QLineEdit(this);
    hbox->addWidget(label);
    hbox->addWidget(m_userLineEdit);
    mainlayout->addLayout(hbox);

    hbox = new QHBoxLayout();
    label = new QLabel("Pass:");
    m_passLineEdit = new QLineEdit(this);
    hbox->addWidget(label);
    hbox->addWidget(m_passLineEdit);
    mainlayout->addLayout(hbox);

    hbox = new QHBoxLayout();
    m_loginBtn = new QPushButton("Login", this);
    m_exitBtn = new QPushButton("Exit", this);
    hbox->addWidget(m_loginBtn);
    hbox->addWidget(m_exitBtn);
    mainlayout->addLayout(hbox);

    m_passLineEdit->setEchoMode(QLineEdit::Password);
    connect(m_loginBtn, SIGNAL(clicked()), this, SLOT(checkuserandpass()));
    connect(m_exitBtn, SIGNAL(clicked()), this, SLOT(reject()));
}

void Login::checkuserandpass()
{
    QString user=m_userLineEdit->text();
    QString pass=m_passLineEdit->text();
    if (m_users->size()==0 && user=="admin" && pass=="admin")
    {
        emit senduserandpass(user, pass);
        this->accept();
        return;
    }
    if (m_users->find(user)!= m_users->end() && m_users->find(user).value()==pass)
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
        m_users->insert(settings->value("user").toString(),settings->value("pass").toString());
    }
    settings->endArray();
    delete settings;
    return len;
}

