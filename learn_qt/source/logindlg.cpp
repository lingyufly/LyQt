#include "logindlg.h"

LogInDlg::LogInDlg(QWidget *parent, Qt::WindowFlags f)
    :QDialog(parent,f)
{
    setupUi();
}


LogInDlg::~LogInDlg()
{
}

void LogInDlg::slotVerifyUser()
{
    accept();
}

void LogInDlg::slotExit()
{
    reject();
}


void LogInDlg::setupUi()
{
    QVBoxLayout *layoutMain = new QVBoxLayout(this);
    
    QVBoxLayout *vlayout = new QVBoxLayout();

    //username
    QHBoxLayout *hlayout = new QHBoxLayout();
    QLabel *label = new QLabel(this);
    label->setText("Username");
    m_leditUserName = new QLineEdit(this);
    hlayout->addWidget(label);
    hlayout->addWidget(m_leditUserName);
    vlayout->addLayout(hlayout);

    //password
    hlayout = new QHBoxLayout();
    label = new QLabel(this);
    label->setText("Password");
    m_leditUserPasswd = new QLineEdit(this);
    hlayout->addWidget(label);
    hlayout->addWidget(m_leditUserPasswd);
    vlayout->addLayout(hlayout);

    layoutMain->addLayout(vlayout);

    // button
    hlayout = new QHBoxLayout();
    QSpacerItem *spacer = new QSpacerItem(100, 20, QSizePolicy::Expanding);
    hlayout->addItem(spacer);
    m_btnLogin = new QPushButton(this);
    m_btnLogin->setText("Login");
    m_btnExit = new QPushButton(this);
    m_btnExit->setText("Exit");
    hlayout->addWidget(m_btnLogin);
    hlayout->addWidget(m_btnExit);

    layoutMain->addLayout(hlayout);

    connect(m_btnLogin, SIGNAL(clicked()), this, SLOT(slotVerifyUser()));
    connect(m_btnExit, SIGNAL(clicked()), this, SLOT(slotExit()));

}



