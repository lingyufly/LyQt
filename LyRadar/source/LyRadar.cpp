#include "LyRadar.h"

#include <QBrush>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QPen>
#include <QPainter>
#include <QPalette>
#include <QEvent>
#include <QDebug>
#include <QTimer>
#include <QTimerEvent>
#include <QPaintEvent>
#include <QPixmap>

LyRadar::LyRadar(QWidget *parent, Qt::WindowFlags fl)
    : QWidget(parent, fl)
{
    resize(800, 400);
    m_groudColor = QColor(15, 45, 188);
    m_fontColor = Qt::white;
    m_dir = true;
    m_pix = new QPixmap(size());
    m_maxDistance = 100;
    startTimer(50);
}


LyRadar::~LyRadar()
{

}
//定时器，测试使用

static double m_rotate = 0.0;
void LyRadar::timerEvent(QTimerEvent *event)
{
    qDebug() << "timerEvent, id=" << event->timerId();
    
    if (m_dir)
        m_rotate += 1.0;
    else
        m_rotate -= 1.0;
    if (m_rotate > 180.0)
        m_dir = false;
    if (m_rotate < 0)
        m_dir = true;
    pushPoint(m_rotate, rand()%100);
}


void LyRadar::pushPoint(double angle, double distance)
{
    addPoint(angle, distance);

    if (m_pix != NULL)
    {
        delete m_pix;
        m_pix = NULL;
    }
    m_pix = new QPixmap(size());
    QPainter painter(m_pix);
    painter.setRenderHint(QPainter::Antialiasing);
    preDraw();
    //draw background
    drawArc(painter);
    //draw scan line
    drawScan(painter, angle);
    //draw points
    drawPoints(painter);
    if (angle > 180 || angle < 0)
        m_points.clear();

    update();
}


void LyRadar::paintEvent(QPaintEvent *event)
{
    qDebug() << "paintEvent";
    QPainter p(this);
    p.drawPixmap(0, 0, *m_pix);
}

void LyRadar::addPoint(double angle, double distance)
{
    if (distance >= m_maxDistance)
        return;

    //获得点坐标

    double d=m_radius*(distance / m_maxDistance);
    qreal px = m_center.x() + d * cos(angle*3.14 / 180);
    qreal py = m_center.y() - d * sin(angle*3.14 / 180);
    m_points.push_back(QPointF(px, py));

    return;
}

void LyRadar::preDraw()
{
    m_width = size().width();
    m_height = size().height();

    int w = m_width <= m_height * 2 ? m_width : m_height * 2;
    int sx = (m_width - w) / 2;
    int sy = m_height - w + w / 2;
    m_radius = w / 2;
    m_center.setX(m_width / 2);
    m_center.setY(m_height);
    m_rect=QRect(sx, sy, w, w);
}

void LyRadar::drawCircle(QPainter &painter)
{
    painter.setBrush(QBrush(m_groudColor));
    painter.drawEllipse(m_center, m_radius, m_radius);

    painter.setBrush(QBrush());
    painter.setPen(QPen(m_fontColor));
    painter.drawEllipse(m_center, m_radius, m_radius);
    painter.drawEllipse(m_center, m_radius * 2 / 3, m_radius * 2 / 3);
    painter.drawEllipse(m_center, m_radius * 1 / 3, m_radius * 1 / 3);
    painter.drawEllipse(m_center, 1, 1);
}

void LyRadar::drawArc(QPainter & painter)
{
    painter.setBrush(QBrush(m_groudColor));
    painter.setPen(QPen(m_fontColor));
    painter.drawPie(m_rect, 0*16, 180*16);

    int w = m_width <= m_height * 2 ? m_width : m_height * 2;
    int sx = (m_width - w) / 2;
    int sy = m_height - w + w / 2;

    painter.setBrush(QBrush());
    QRect rect1(sx + w / 6, sy + w / 6, w * 2 / 3, w * 2 / 3);
    painter.drawPie(rect1, 0 * 16, 180 * 16);
    QRect rect2(sx + w / 3, sy + w / 3, w * 1 / 3, w * 1 / 3);
    painter.drawPie(rect2, 0 * 16, 180 * 16);

    qreal px = m_center.x() + m_radius * cos(0*3.14 / 180);
    qreal py = m_center.y() - m_radius * sin(0 *3.14 / 180);
    painter.drawLine(m_center, QPointF(px, py));
    px = m_center.x() + m_radius * cos(45*3.14 / 180);
    py = m_center.y() - m_radius * sin(45*3.14 / 180);
    painter.drawLine(m_center, QPointF(px, py));
    px = m_center.x() + m_radius * cos(90*3.14 / 180);
    py = m_center.y() - m_radius * sin(90*3.14 / 180);
    painter.drawLine(m_center, QPointF(px, py));
    px = m_center.x() + m_radius * cos(135*3.14 / 180);
    py = m_center.y() - m_radius * sin(135*3.14 / 180);
    painter.drawLine(m_center, QPointF(px, py));
    px = m_center.x() + m_radius * cos(180*3.14 / 180);
    py = m_center.y() - m_radius * sin(180*3.14 / 180);
    painter.drawLine(m_center, QPointF(px, py));
}

void LyRadar::drawScan(QPainter & painter, double angle)
{
    qreal px = m_center.x() + m_radius * cos(angle*3.14 / 180);
    qreal py = m_center.y() - m_radius * sin(angle*3.14 / 180);
    painter.drawLine(m_center, QPointF(px, py));

    QConicalGradient gradient;
    gradient.setCenter(m_rect.center());
    gradient.setColorAt(0.4, QColor(255, 255, 255, 100));
    gradient.setColorAt(0.8, QColor(255, 255, 255, 0));
    painter.setBrush(QBrush(gradient));
    painter.setPen(Qt::NoPen);
    if (m_dir)
        painter.drawPie(m_rect, (angle - 30) * 16, 30 * 16);
    else
        painter.drawPie(m_rect, angle * 16, 30 * 16);
}

void LyRadar::drawPoints(QPainter & painter)
{
    for each (QPointF point in m_points)
    {
        painter.drawEllipse(point, 1, 1);
    }
}