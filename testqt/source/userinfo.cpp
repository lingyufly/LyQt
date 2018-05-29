#include "userinfo.h"
#include <QMap>
#include <QDebug>
#include <QList>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>

UserInfo::UserInfo(QWidget *parent) :
QWidget(parent)
{
    setupUi();

    m_users = new QMap<QString, QString>();

    if ((m_itemSize = loaddata()) == 0)
    {
        return;
    }
    qDebug() << m_itemSize;
    m_infoTable->setRowCount(m_itemSize);
    int i = 0;
    for (QMap<QString, QString>::iterator p = m_users->begin(); p != m_users->end(); p++, i++)
    {
        qDebug() << p.key() << p.value();

        m_infoTable->setItem(i, 0, new QTableWidgetItem(p.key()));
        m_infoTable->setItem(i, 1, new QTableWidgetItem(p.value()));
    }
}

UserInfo::~UserInfo()
{
}

void UserInfo::setupUi()
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    setLayout(mainLayout);
    m_infoTable = new QTableWidget(this);
    QStringList *headers = new QStringList;
    headers->push_back("Name");
    headers->push_back("Pass");
    headers->push_back("Info");
    m_infoTable->setColumnCount(3);
    m_infoTable->setHorizontalHeaderLabels(*headers);
    //设置表头背景色
    m_infoTable->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    m_infoTable->verticalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    // 设置列填充满宽度
    m_infoTable->horizontalHeader()->setStretchLastSection(true);
    //设置选中时为一行
    m_infoTable->setSelectionBehavior(QTableWidget::SelectRows);
    //设置只允许单行选中
    m_infoTable->setSelectionMode(QTableWidget::SingleSelection);
    delete headers;

    mainLayout->addWidget(m_infoTable);

    QSpacerItem *spacer = new QSpacerItem(120, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QHBoxLayout *hbox = new QHBoxLayout();
    m_addBtn = new QPushButton("Add", this);
    m_delBtn = new QPushButton("Delete", this);
    m_saveBtn = new QPushButton("Save", this);
    hbox->addItem(spacer);
    hbox->addWidget(m_addBtn);
    hbox->addWidget(m_delBtn);
    hbox->addWidget(m_saveBtn);
    mainLayout->addLayout(hbox);

    connect(m_addBtn, SIGNAL(clicked(bool)), this, SLOT(additem()));
    connect(m_saveBtn, SIGNAL(clicked(bool)), this, SLOT(savedata()));
    connect(m_delBtn, SIGNAL(clicked(bool)), this, SLOT(deleteitem()));
}

int UserInfo::loaddata()
{
    m_users->empty();
    QSettings *settings = new QSettings("ini/settings.ini", QSettings::IniFormat);

    int len = settings->beginReadArray("login");
    for (int i = 0; i < len; i++)
    {
        settings->setArrayIndex(i);
        m_users->insert(settings->value("user").toString(), settings->value("pass").toString());
    }
    settings->endArray();
    delete settings;
    return m_users->size();
}

void UserInfo::savedata()
{
    m_users->empty();
    QSettings *settings = new QSettings("ini/settings.ini", QSettings::IniFormat);
    settings->beginWriteArray("login");
    for (int i = 0; i < m_infoTable->rowCount(); i++)
    {
        if (m_infoTable->item(i, 0) == 0 || m_infoTable->item(i, 1) == 0)
            continue;
        qDebug() << m_infoTable->item(i, 0)->text() << ":" << m_infoTable->item(i, 1)->text();
        m_users->insert(m_infoTable->item(i, 0)->text(), m_infoTable->item(i, 1)->text());
        settings->setArrayIndex(i);
        settings->setValue("user", m_infoTable->item(i, 0)->text());
        settings->setValue("pass", m_infoTable->item(i, 1)->text());

    }
    settings->endArray();
    delete settings;
}

int UserInfo::deleteitem()
{
    if (m_itemSize <= 0 || m_infoTable->currentRow() < 0)
        return 0;

    m_itemSize -= 1;
    m_infoTable->removeRow(m_infoTable->currentRow());
    m_infoTable->setFocus();
    m_infoTable->selectRow(m_itemSize - 1);
    return 1;
}

int UserInfo::additem()
{
    m_itemSize += 1;
    m_infoTable->setRowCount(m_itemSize);
    // 不在新添加的行的第一个元素中写入内容，无法使其变为正在编辑状态
    //m_infoTable->setItem(itemSize-1,0,new QTableWidgetItem(" "));
    m_infoTable->setFocus();
    m_infoTable->selectRow(m_itemSize - 1);
    m_infoTable->editItem(m_infoTable->item(m_itemSize - 1, 0));
    return 1;
}
