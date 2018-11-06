#include "config.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QSpacerItem>

ConfigWidget::ConfigWidget(QWidget *parent /* = NULL */, Qt::WindowFlags fl /* = Qt::WindowFlags() */)
    :QDialog(parent, fl)
{
    setupUi();
}

ConfigWidget::~ConfigWidget()
{

}

void ConfigWidget::setupUi()
{
    m_mainLayout = new QGridLayout(this);
    
    m_controlUrlLabel = new QLabel("Control Url:", this);
    m_controlUrlEdit = new QLineEdit(this);
    m_mainLayout->addWidget(m_controlUrlLabel, 0, 0);
    m_mainLayout->addWidget(m_controlUrlEdit, 0, 1);

    m_videoUrlLabel = new QLabel("Video Url:", this);
    m_videoUrlEdit = new QLineEdit(this);
    m_mainLayout->addWidget(m_videoUrlLabel, 1, 0);
    m_mainLayout->addWidget(m_videoUrlEdit, 1, 1);

    m_showInfoCBox = new QCheckBox("Show Raspberry Pi Infomation", this);

    m_showLogCBox = new QCheckBox("Show Log Infomation", this);

    m_mainLayout->addWidget(m_showInfoCBox, 2, 0, 1, 2);
    m_mainLayout->addWidget(m_showLogCBox, 3, 0, 1, 2);

    QHBoxLayout *hbox = new QHBoxLayout();
    QSpacerItem *spacer = new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_saveBtn = new QPushButton("Save", this);
    m_cancleBtn = new QPushButton("Cancle", this);
    hbox->addSpacerItem(spacer);
    hbox->addWidget(m_saveBtn);
    hbox->addWidget(m_cancleBtn);
    m_mainLayout->addLayout(hbox, 4, 0, 1, 2);

    connect(m_saveBtn, &QPushButton::clicked, this, &ConfigWidget::slot_save);
    connect(m_cancleBtn, &QPushButton::clicked, this, &ConfigWidget::slot_cancle);
}


void ConfigWidget::setControlUrl(QString url)
{
    m_controlUrlEdit->setText(url);
}

QString ConfigWidget::getControlUrl()
{
    return m_controlUrlEdit->text();
}

void ConfigWidget::setVideoUrl(QString url)
{
    m_videoUrlEdit->setText(url);
}

QString ConfigWidget::getVideoUrl()
{
    return m_videoUrlEdit->text();
}

void ConfigWidget::setShowInfo(bool check)
{
    m_showInfoCBox->setChecked(check ? Qt::Checked : Qt::Unchecked);
}

bool ConfigWidget::getShowInfo()
{
    return m_showInfoCBox->checkState() == Qt::Checked ? true : false;
}

void ConfigWidget::setShowLog(bool check)
{
    m_showLogCBox->setChecked(check ? Qt::Checked : Qt::Unchecked);
}

bool ConfigWidget::getShowLog()
{
    return m_showLogCBox->checkState() == Qt::Checked ? true : false;
}

void ConfigWidget::slot_save()
{
    accept();
}

void ConfigWidget::slot_cancle()
{
    reject();
}