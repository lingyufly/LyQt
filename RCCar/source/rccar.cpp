#include "rccar.h"
#include <QGridLayout>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QUrl>
#include <QNetworkReply>
#include <QResizeEvent>
#include <QPaintEvent>
#include <QTimer>
#include <QSlider>

LSlider::LSlider(QWidget *parent)
    :QSlider(parent)
{

}

LSlider::LSlider(Qt::Orientation orientation, QWidget *parent)
    :QSlider(orientation, parent)
{

}

LSlider::~LSlider()
{

}

void LSlider::mousePressEvent(QMouseEvent *event)
{
    QSlider::mousePressEvent(event);
    return;
}

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
    m_mainLayout->setMargin(0);
    m_mainLayout->setSpacing(0);
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
    m_viewSlider=new LSlider(this);
    m_viewSlider->show();
    m_viewSlider->setOrientation(Qt::Horizontal);
    m_viewSlider->setMinimum(0);
    m_viewSlider->setMaximum(180);
    m_viewSlider->setValue(90);

    m_viewTimer=new QTimer(this);
    m_viewTimer->setInterval(20);

    connect(m_foreBtn, &QPushButton::pressed, this, &ControlWidget::slot_gofore);
    connect(m_foreBtn, &QPushButton::released, this, &ControlWidget::slot_stop);
    connect(m_backBtn, &QPushButton::pressed, this, &ControlWidget::slot_goback);
    connect(m_backBtn, &QPushButton::released, this, &ControlWidget::slot_stop);
    connect(m_leftBtn, &QPushButton::pressed, this, &ControlWidget::slot_turnleft);
    connect(m_leftBtn, &QPushButton::released, this, &ControlWidget::slot_stop);
    connect(m_rightBtn, &QPushButton::pressed, this, &ControlWidget::slot_turnright);
    connect(m_rightBtn, &QPushButton::released, this, &ControlWidget::slot_stop);
    connect(m_viewSlider, &LSlider::valueChanged, this, &ControlWidget::slot_viewChanged);
    connect(m_viewSlider, &LSlider::sliderReleased, this, &ControlWidget::slot_viewReset);

    connect(m_viewTimer, &QTimer::timeout, this, &ControlWidget::slot_viewTimer);
    connect(this, &ControlWidget::signal_logmsg, this, &ControlWidget::slot_showinfo);
    m_foreBtn->setFocusPolicy(Qt::NoFocus);
    m_backBtn->setFocusPolicy(Qt::NoFocus);
    m_leftBtn->setFocusPolicy(Qt::NoFocus);
    m_rightBtn->setFocusPolicy(Qt::NoFocus);
    m_viewSlider->setFocusPolicy(Qt::NoFocus);

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

    m_viewSlider->resize(200,10);
    x=w-200-mng;
    y=h-mng-10;
    m_viewSlider->move(x,y);
}

void ControlWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    repaintCtl();
}

void ControlWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
}

void ControlWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;
    QWidget::keyPressEvent(event);
    if (event->key()==Qt::Key_W || event->key()==Qt::Key_Up)
        slot_gofore();
    else if (event->key()==Qt::Key_A || event->key()==Qt::Key_Left)
        slot_turnleft();
    else if (event->key()==Qt::Key_S || event->key()==Qt::Key_Down)
        slot_goback();
    else if (event->key()==Qt::Key_D || event->key()==Qt::Key_Right)
        slot_turnright();
    if (event->key()==Qt::Key_Q)
    {
        m_ctrlaction&=0x0F;
        m_ctrlaction|=VIEWLEFT;
        if (!m_viewTimer->isActive()) 
            m_viewTimer->start();
    }
    else if (event->key()==Qt::Key_E)
    {
        m_ctrlaction&=0x0F;
        m_ctrlaction|=VIEWRIGHT;
        if (!m_viewTimer->isActive()) 
            m_viewTimer->start();
    }
}

void ControlWidget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;
    QWidget::keyReleaseEvent(event);
    if (event->key()==Qt::Key_W || event->key()==Qt::Key_A || event->key()==Qt::Key_S || event->key()==Qt::Key_D)
        slot_stop();
    else if (event->key()==Qt::Key_Q || event->key()==Qt::Key_E)
    {
        m_viewTimer->stop();
        m_viewSlider->setValue(90);
    }
}

void ControlWidget::slot_showPic(QNetworkReply *reply)
{
    if (reply->error()!=QNetworkReply::NoError)
   {
       m_picLabel->setText("Connection error");
        m_picManager->get(m_picRequest);
       return;
   }
    QByteArray jpgdata=reply->readAll();
    QPixmap pix;
    pix.loadFromData(jpgdata);
    pix=pix.scaled(m_picLabel->size());

    m_picLabel->setPixmap(pix);
    
    m_picManager->get(m_picRequest);
}

void ControlWidget::slot_gofore()
{
    emit signal_logmsg("Go fore");
}

void ControlWidget::slot_goback()
{
    emit signal_logmsg("Go back");
}

void ControlWidget::slot_turnleft()
{
    emit signal_logmsg("Turn left");
}

void ControlWidget::slot_turnright()
{
    emit signal_logmsg("Turn right");
}

void ControlWidget::slot_stop()
{
    emit signal_logmsg("Stop");
}

void ControlWidget::slot_viewleft()
{
    emit signal_logmsg("View left");
}

void ControlWidget::slot_viewright()
{
    emit signal_logmsg("View right");
}

void ControlWidget::slot_viewChanged(int angle)
{
    emit signal_logmsg(QString("View %1").arg(angle));
}

void ControlWidget::slot_viewReset()
{
    m_viewTimer->stop();
    m_viewSlider->setValue(90);
}

void ControlWidget::slot_viewTimer()
{
    int angle=m_viewSlider->value();
    if (m_ctrlaction&VIEWLEFT && angle>0)
        angle-=1;
    else if (m_ctrlaction&VIEWRIGHT && angle<180)
        angle+=1;
    else
        m_viewTimer->stop();
    m_viewSlider->setValue(angle);
}

void ControlWidget::slot_showinfo(QString msg)
{
    qDebug()<<msg;
}