#include "userinfo.h"
#include "ui_userinfo.h"
#include <QMap>
#include <QDebug>
#include <QList>

UserInfo::UserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfo)
{
    ui->setupUi(this);
    QStringList *headers=new QStringList;
    headers->push_back("Name");
    headers->push_back("Pass");
    headers->push_back("Info");
    ui->infotable->setColumnCount(3);
    ui->infotable->setHorizontalHeaderLabels(*headers);
    //设置表头背景色
    ui->infotable->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    ui->infotable->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

    // 设置列填充满宽度
    ui->infotable->horizontalHeader()->setStretchLastSection(true);

    //设置选中时为一行
    ui->infotable->setSelectionBehavior(QTableWidget::SelectRows);
    //设置只允许单行选中
    ui->infotable->setSelectionMode(QTableWidget::SingleSelection);

    delete headers;

    connect(ui->addBtn, SIGNAL(clicked(bool)), this, SLOT(additem()));
    connect(ui->saveBtn, SIGNAL(clicked(bool)), this, SLOT(savedata()));
    connect(ui->delBtn, SIGNAL(clicked(bool)), this, SLOT(deleteitem()));

    users=new QMap<QString, QString>();

    if ((itemSize=loaddata())==0)
    {
        return;
    }
    qDebug()<<itemSize;
    ui->infotable->setRowCount(itemSize);
    int i=0;
    for (QMap<QString,QString>::iterator p=users->begin(); p!=users->end(); p++,i++)
    {
        qDebug()<<p.key()<<p.value();

        ui->infotable->setItem(i,0,new QTableWidgetItem(p.key()));
        ui->infotable->setItem(i,1, new QTableWidgetItem(p.value()));
    }
}

UserInfo::~UserInfo()
{
    delete ui;
}

int UserInfo::loaddata()
{
    users->empty();
    QSettings *settings=new QSettings("ini/settings.ini", QSettings::IniFormat);

    int len=settings->beginReadArray("login");
    for (int i=0; i<len; i++)
    {
        settings->setArrayIndex(i);
        users->insert(settings->value("user").toString(), settings->value("pass").toString());
    }
    settings->endArray();
    delete settings;
    return users->size();
}

void UserInfo::savedata()
{
    users->empty();
    QSettings *settings=new QSettings("ini/settings.ini", QSettings::IniFormat);
    settings->beginWriteArray("login");
    for (int i=0; i<ui->infotable->rowCount(); i++)
    {
        if(ui->infotable->item(i,0)==0 || ui->infotable->item(i,1)==0)
            continue;
        qDebug()<<ui->infotable->item(i,0)->text()<<":"<<ui->infotable->item(i,1)->text();
        users->insert(ui->infotable->item(i,0)->text(), ui->infotable->item(i,1)->text());
        settings->setArrayIndex(i);
        settings->setValue("user", ui->infotable->item(i,0)->text());
        settings->setValue("pass", ui->infotable->item(i,1)->text());

    }
    settings->endArray();
    delete settings;
}

int UserInfo::deleteitem()
{
    if (itemSize<=0 || ui->infotable->currentRow()<0)
        return 0;

    itemSize-=1;
    ui->infotable->removeRow(ui->infotable->currentRow());
    ui->infotable->setFocus();
    ui->infotable->selectRow(itemSize-1);
    return 1;
}

int UserInfo::additem()
{
    itemSize+=1;
    ui->infotable->setRowCount(itemSize);
    // 不在新添加的行的第一个元素中写入内容，无法使其变为正在编辑状态
    //ui->infotable->setItem(itemSize-1,0,new QTableWidgetItem(" "));
    ui->infotable->setFocus();
    ui->infotable->selectRow(itemSize-1);
    ui->infotable->editItem(ui->infotable->item(itemSize-1, 0));
    return 1;
}
