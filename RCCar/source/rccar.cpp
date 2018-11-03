#include "rccar.h"
#include <QGridLayout>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QUrl>
#include <QNetworkReply>

ControlWidget::ControlWidget(QWidget *parent /*= NULL*/, Qt::WindowFlags fl/*= Qt::windowFlags()*/)
{
    setupUi();
}

ControlWidget::~ControlWidget()
{

}

void ControlWidget::setupUi()
{
    m_mainLayout = new QGridLayout(this);
    m_picLabel=new QLabel(this);
    m_mainLayout->addWidget(m_picLabel);

    int lth = 30;
    m_leftBtn = new QPushButton(this);
    m_leftBtn->resize(lth, lth);
    m_leftBtn->show();
    m_backBtn = new QPushButton(this);
    m_backBtn->resize(lth, lth);
    m_backBtn->show();
    m_rightBtn = new QPushButton(this);
    m_rightBtn->resize(lth, lth);
    m_rightBtn->show();
    m_foreBtn = new QPushButton(this);
    m_foreBtn->resize(lth, lth);
    m_foreBtn->show();

    m_picManager=new QNetworkAccessManager(this);
    connect(m_picManager, &QNetworkAccessManager::finished, this, &ControlWidget::slot_showPic);
    m_picUrl=QUrl("http://192.168.2.199:8080/?action=snapshot");
    m_picRequest=QNetworkRequest(m_picUrl);
    m_picManager->get(m_picRequest);
}

void ControlWidget::repaintCtl()
{
    int w = width();
    int h = height();

    int lth = 30;// The width and height of Btn
    int mng = 30;
    int space = 10;// The margin between btns

    int x = 0, y = 0;

    x = mng;
    y = h - (mng + lth + space + lth);
    m_leftBtn->move(x, y);
    
    x = mng + lth + space;
    y = h - (mng + lth);
    m_backBtn->move(x, y);
    
    x = mng + lth + space + lth + space;
    y = h - (mng + lth + space + lth);
    m_rightBtn->move(x, y);
    
    x = mng + lth + space;
    y = h - (mng + lth + space + lth + space + lth);
    m_foreBtn->move(x, y);
}

void ControlWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    repaintCtl();
}


void ControlWidget::slot_showPic(QNetworkReply *reply)
{
    QByteArray jpgdata=reply->readAll();
    QPixmap pix;
    pix.loadFromData(jpgdata);
    pix=pix.scaled(m_picLabel->size());

    m_picLabel->setPixmap(pix);

    m_picManager->get(m_picRequest);
}

