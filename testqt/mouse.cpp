#include "mouse.h"
#include "ui_mouse.h"
#include <QMouseEvent>
#include <QDebug>
#include <QCheckBox>

Mouse::Mouse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mouse)
{
    ui->setupUi(this);
    // 默认鼠标移动事件是在鼠标按下时才可以被捕获，通过设置setMouseTracking(true)可以在鼠标不按下时也被捕获
    setMouseTracking(false);
    ui->mouseposLabel->setAlignment(Qt::AlignCenter);

    connect(ui->mouseTrackCbox, SIGNAL(toggled(bool)), this, SLOT(changeMouseTrckState(bool)));

    pt=QTime::currentTime();
}

Mouse::~Mouse()
{
    delete ui;
}


void Mouse::mousePressEvent(QMouseEvent *e)
{
    if (e->button()==Qt::LeftButton)
        ui->textBrowser->append("Mouse left button press");
    else
        ui->textBrowser->append("Mouse right button press");
}

void Mouse::mouseMoveEvent(QMouseEvent *e)
{
    // 防抖动
    ct=QTime::currentTime();
    if (pt.msecsTo(ct)<=100)
        return;
    pt=ct;

    ui->mouseposLabel->setText("X:"+QString::number(e->globalX())+" Y:"+QString::number(e->globalY()));
    ui->textBrowser->append("Mouse move");
}

void Mouse::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button()==Qt::LeftButton)
        ui->textBrowser->append("Mouse left button release");
    else
        ui->textBrowser->append("Mouse right button release");
}

void Mouse::mouseDoubleClickEvent(QMouseEvent *)
{
    ui->textBrowser->append("Mouse double click");
}

void Mouse::changeMouseTrckState(bool stat)
{
    setMouseTracking(stat);
}
