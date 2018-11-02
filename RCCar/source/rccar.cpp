#include "rccar.h"
#include <QGridLayout>
#include <QPushButton>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaContent>
#include <QFile>
#include <QDebug>

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
    m_videoWgt = new QVideoWidget(this);
    m_mainLayout->addWidget(m_videoWgt);

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

    m_player=new QMediaPlayer(this);
    m_player->setVideoOutput(m_videoWgt);

    QFile file("movie.mp4");
    if (!file.open(QIODevice::ReadOnly))
        qDebug()<<"Could not open file";

    connect(m_player, &QMediaPlayer::videoAvailableChanged, this, &ControlWidget::readyPlay);
    m_player->setMedia(QUrl("http://www.w3school.com.cn/i/movie.mp4"));

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


void ControlWidget::readyPlay(bool ready)
{
    if (ready)
    {
        qDebug()<<"ready";
        m_player->play();
    }
}

