#include "rccar.h"
#include "config.h"
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
#include <QBitMap>
#include <QJsonDocument>
#include <QJsonObject>

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
    m_picLabel = new QLabel(this);
    m_mainLayout->addWidget(m_picLabel);

    m_leftBtn = new QPushButton(this);
    m_leftBtn->setCheckable(true);
    m_leftBtn->setFlat(true);
    m_leftBtn->show();
    m_backBtn = new QPushButton(this);
    m_backBtn->setCheckable(true);
    m_backBtn->setFlat(true);
    m_backBtn->show();
    m_rightBtn = new QPushButton(this);
    m_rightBtn->setCheckable(true);
    m_rightBtn->setFlat(true);
    m_rightBtn->show();
    m_foreBtn = new QPushButton(this);
    m_foreBtn->setCheckable(true);
    m_foreBtn->setFlat(true);
    m_foreBtn->show(); 

    m_viewSlider = new QSlider(this);
    m_viewSlider->show();
    m_viewSlider->setOrientation(Qt::Horizontal);
    m_viewSlider->setMinimum(0);
    m_viewSlider->setMaximum(180);
    m_viewSlider->setValue(90);

    m_settingBtn = new QPushButton(this);
    m_settingBtn->setFlat(true);
    m_settingBtn->show();

    m_infoLabel = new QLabel(this);
    //m_infoLabel->setFrameShape(QFrame::Box);
    m_infoLabel->show();

    m_logLabel = new QLabel(this);
    //m_logLabel->setFrameShape(QFrame::Box);
    m_logLabel->show();

    m_viewTimer = new QTimer(this);
    m_viewTimer->setInterval(20);

    connect(m_foreBtn, &QPushButton::pressed, this, &ControlWidget::slot_gofore);
    connect(m_foreBtn, &QPushButton::released, this, &ControlWidget::slot_stop);
    connect(m_backBtn, &QPushButton::pressed, this, &ControlWidget::slot_goback);
    connect(m_backBtn, &QPushButton::released, this, &ControlWidget::slot_stop);
    connect(m_leftBtn, &QPushButton::pressed, this, &ControlWidget::slot_turnleft);
    connect(m_leftBtn, &QPushButton::released, this, &ControlWidget::slot_stop);
    connect(m_rightBtn, &QPushButton::pressed, this, &ControlWidget::slot_turnright);
    connect(m_rightBtn, &QPushButton::released, this, &ControlWidget::slot_stop);
    connect(m_viewSlider, &QSlider::valueChanged, this, &ControlWidget::slot_viewChanged);
    connect(m_viewSlider, &QSlider::sliderReleased, this, &ControlWidget::slot_viewReset);
    connect(m_settingBtn, &QPushButton::clicked, this, &ControlWidget::slot_openSetting);

    connect(m_viewTimer, &QTimer::timeout, this, &ControlWidget::slot_viewTimer);
    connect(this, &ControlWidget::signal_logmsg, this, &ControlWidget::slot_showLog);
    m_foreBtn->setFocusPolicy(Qt::NoFocus);
    m_backBtn->setFocusPolicy(Qt::NoFocus);
    m_leftBtn->setFocusPolicy(Qt::NoFocus);
    m_rightBtn->setFocusPolicy(Qt::NoFocus);
    m_viewSlider->setFocusPolicy(Qt::NoFocus);

    m_picManager = new QNetworkAccessManager(this);
    connect(m_picManager, &QNetworkAccessManager::finished, this, &ControlWidget::slot_showPic);

    m_size = size();
}

void ControlWidget::setVideoUrl(QString url)
{
    //m_picUrl = QUrl("http://192.168.2.199:8080/?action=snapshot");
    m_picRequest = QNetworkRequest(url);
    m_picManager->get(m_picRequest);
}

void ControlWidget::setControlUrl(QString url)
{

}

void ControlWidget::setShowInfo(bool shown)
{
    if (shown)
    {
        m_infoLabel->show();
    }
    else
    {
        m_infoLabel->setText("");
        m_infoLabel->hide();
    }
}

void ControlWidget::setShowLog(bool shown)
{
    if (shown)
    {
        m_logLabel->show();
    }
    else
    {
        m_logLabel->setText("");
        m_logLabel->hide();
    }
}

void ControlWidget::repaintCtl()
{
    int w = width();
    int h = height();

    int lth = 30;// The width and height of Btn
    int mng = 30;
    int space = 10;// The margin between btns

    int x = 0, y = 0;
    QPixmap pixmap;

    x = mng;
    y = h - (mng + lth + space + lth);
    m_leftBtn->resize(lth, lth);
    pixmap = QPixmap(":/image/turnleft.png").scaled(m_leftBtn->size());
    m_leftBtn->setIcon(pixmap);
    m_leftBtn->move(x, y);

    x = mng + lth + space;
    y = h - (mng + lth);
    m_backBtn->resize(lth, lth);
    pixmap = QPixmap(":/image/goback.png").scaled(m_backBtn->size());
    m_backBtn->setIcon(pixmap);
    m_backBtn->move(x, y);

    x = mng + lth + space + lth + space;
    y = h - (mng + lth + space + lth);
    m_rightBtn->resize(lth, lth);
    pixmap = QPixmap(":/image/turnright.png").scaled(m_rightBtn->size());
    m_rightBtn->setIcon(pixmap);
    m_rightBtn->move(x, y);

    x = mng + lth + space;
    y = h - (mng + lth + space + lth + space + lth);
    m_foreBtn->resize(lth, lth);
    pixmap = QPixmap(":/image/gofore.png").scaled(m_foreBtn->size());
    m_foreBtn->setIcon(pixmap);
    m_foreBtn->move(x, y);

    m_settingBtn->resize(lth, lth);
    pixmap = QPixmap(":/image/setting.png").scaled(m_settingBtn->size());
    m_settingBtn->setIcon(pixmap);
    m_settingBtn->move(10, 10);

    m_infoLabel->resize(100, 100);
    m_infoLabel->move(w - (100 + 10), 10);

    m_logLabel->resize(100, 50);
    m_logLabel->move(10, 60);

    m_viewSlider->resize(200, 10);
    x = w - 200 - mng;
    y = h - mng - 10;
    m_viewSlider->move(x, y);
}

void ControlWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    if (m_size != size())
    {
        repaintCtl();
        m_size = size();
    }
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
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up)
    {
        slot_gofore();
        m_foreBtn->setChecked(true);
    }
    else if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left)
    {
        slot_turnleft();
        m_leftBtn->setChecked(true);
    }
    else if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down)
    {
        slot_goback();
        m_backBtn->setChecked(true);
    }
    else if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right)
    {
        slot_turnright();
        m_rightBtn->setChecked(true);
    }

    if (event->key() == Qt::Key_Q)
    {
        m_ctrlaction &= 0x0F;
        m_ctrlaction |= VIEWLEFT;
        if (!m_viewTimer->isActive())
            m_viewTimer->start();
    }
    else if (event->key() == Qt::Key_E)
    {
        m_ctrlaction &= 0x0F;
        m_ctrlaction |= VIEWRIGHT;
        if (!m_viewTimer->isActive())
            m_viewTimer->start();
    }
}

void ControlWidget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;
    QWidget::keyReleaseEvent(event);
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_A || event->key() == Qt::Key_S || event->key() == Qt::Key_D)
        slot_stop();
    else if (event->key() == Qt::Key_Q || event->key() == Qt::Key_E)
    {
        m_viewTimer->stop();
        m_viewSlider->setValue(90);
    }
}

void ControlWidget::slot_showPic(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        m_picLabel->setText("Connection error");
        m_picManager->get(m_picRequest);
        return;
    }
    QByteArray jpgdata = reply->readAll();
    QPixmap pix;
    pix.loadFromData(jpgdata);
    pix = pix.scaled(m_picLabel->size());

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
    int angle = m_viewSlider->value();
    if (m_ctrlaction&VIEWLEFT && angle > 0)
        angle -= 1;
    else if (m_ctrlaction&VIEWRIGHT && angle < 180)
        angle += 1;
    else
        m_viewTimer->stop();
    m_viewSlider->setValue(angle);
}

void ControlWidget::slot_showinfo(QString msg)
{
    if (!m_showInfo)
        return;
    m_logLabel->setText(msg);
    qDebug() << msg.toLocal8Bit().data();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(msg.toLocal8Bit().data());
    QJsonObject jsonObj = jsonDoc.object();
    QStringList keys= jsonObj.keys();
    for (QList<QString>::iterator key = keys.begin(); key != keys.end(); key++)
        m_infoLabel->setText((*key) + ":" + jsonObj.value(*key).toString() + "\n");
}

void ControlWidget::slot_showLog(QString msg)
{
    if (!m_showLog)
        return;
    QString logmsg = msg + "\n" + m_logLabel->text();
    m_logLabel->setText(logmsg);
}

void ControlWidget::slot_openSetting()
{
    ConfigWidget config(this);
    config.setControlUrl(m_controlUrl);
    config.setVideoUrl(m_videoUrl);
    config.setShowInfo(m_showInfo);
    config.setShowLog(m_showLog);
    if (config.exec() == QDialog::Accepted)
    {
        m_controlUrl = config.getControlUrl();
        m_videoUrl = config.getVideoUrl();
        m_showInfo = config.getShowInfo();
        m_showLog = config.getShowLog();

        setVideoUrl(m_videoUrl);
        setControlUrl(m_controlUrl);
        setShowInfo(m_showInfo);
        setShowLog(m_showLog);
    }
}