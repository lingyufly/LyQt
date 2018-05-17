#include "LyRadar.h"

#include <QBrush>
#include <QPoint>
#include <QPainter>
#include <QPalette>
#include <QEvent>
#include <QDebug>

LyRadar::LyRadar(QWidget *parent, Qt::WindowFlags fl)
    : QWidget(parent, fl)
{

}


LyRadar::~LyRadar()
{

}

void LyRadar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(10, 10, 1000, 1000);
}
