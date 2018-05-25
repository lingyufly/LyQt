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
    m_point = new QPoint();
    m_groudColor = QColor(15, 45, 188);
    m_fontColor = Qt::white;
    m_rotate = 0;
    m_dir = true;
    m_pix = QPixmap(size());
    m_pix.fill(this, 0, 0);
    setMode(ArcMode);
    startTimer(50);
}


LyRadar::~LyRadar()
{

}


void LyRadar::timerEvent(QTimerEvent *event)
{
    qDebug() << "timerEvent, id=" << event->timerId();
    //定时器，测试使用
    if (m_mode == CircleMode)
    {
        m_rotate += 1;
    }
    else
    {
        if (m_rotate >= 180.0)
        {
            m_dir = false;
            m_rotate = 180.0;
        }
        else if (m_rotate<=0.0)
        {
            m_dir = true;
            m_rotate = 0.0;
        }
            
        m_rotate += m_dir ? 1 : -1;
    }

    preDraw();
    update();
}


void LyRadar::paintEvent(QPaintEvent *event)
{
    qDebug() << "paintEvent";
    QPainter p(this);
    p.drawPixmap(0, 0, m_pix);
}


void LyRadar::preDraw()
{
    m_pix = QPixmap(size());
    QPainter painter(&m_pix);
    painter.setRenderHint(QPainter::Antialiasing);
    if (m_mode==CircleMode)
        drawCircle(painter);
    else
        drawArc(painter);
}


void LyRadar::drawCircle(QPainter &painter)
{
    m_width = size().width();
    m_height = size().height();

    int w = m_width <= m_height? m_width : m_height;
    int sx = (m_width - w) / 2;
    int sy = (m_height - w) / 2;
    m_radius = w / 2;
    m_point->setX(m_width / 2);
    m_point->setY(m_height / 2);
    QRect rect(sx, sy, w, w);

    painter.setBrush(QBrush(m_groudColor));
    painter.drawEllipse(*m_point, m_radius, m_radius);

    painter.setBrush(QBrush());
    painter.setPen(QPen(m_fontColor));
    painter.drawEllipse(*m_point, m_radius, m_radius);
    painter.drawEllipse(*m_point, m_radius * 2 / 3, m_radius * 2 / 3);
    painter.drawEllipse(*m_point, m_radius * 1 / 3, m_radius * 1 / 3);
    painter.drawEllipse(*m_point, 1, 1);

    qreal px = m_point->x() + m_radius * cos(0 * 3.14 / 180);
    qreal py = m_point->y() - m_radius * sin(0 * 3.14 / 180);
    px = m_point->x() + m_radius * cos(m_rotate*3.14 / 180);
    py = m_point->y() - m_radius * sin(m_rotate*3.14 / 180);
    painter.drawLine(*m_point, QPointF(px, py));

    QConicalGradient gradient;
    gradient.setCenter(rect.center());
    gradient.setColorAt(0.4, QColor(255, 255, 255, 100)); //从渐变角度开始0.5 - 0.75为扇形区域，由于Int类型计算不精确，将范围扩大到0.4-0.8
    gradient.setColorAt(0.8, QColor(255, 255, 255, 0));
    painter.setBrush(QBrush(gradient));
    painter.setPen(Qt::NoPen);
    if (m_dir)
        painter.drawPie(rect, (m_rotate - 30) * 16, 30 * 16);
    else
        painter.drawPie(rect, m_rotate * 16, 30 * 16);
}

void LyRadar::drawArc(QPainter & painter)
{
    m_width = size().width();
    m_height = size().height();

    int w = m_width<=m_height*2? m_width:m_height*2;
    int sx = (m_width - w) / 2;
    int sy = m_height - w + w / 2;
    m_radius = w / 2;
    m_point->setX(m_width / 2);
    m_point->setY(m_height);
    QRect rect(sx, sy, w, w);
    painter.setBrush(QBrush(m_groudColor));
    painter.setPen(QPen(m_fontColor));
    painter.drawPie(rect, 0*16, 180*16);

    painter.setBrush(QBrush());
    QRect rect1(sx + w / 6, sy + w / 6, w * 2 / 3, w * 2 / 3);
    painter.drawPie(rect1, 0 * 16, 180 * 16);
    QRect rect2(sx + w / 3, sy + w / 3, w * 1 / 3, w * 1 / 3);
    painter.drawPie(rect2, 0 * 16, 180 * 16);

    qreal px = m_point->x() + m_radius * cos(0*3.14 / 180);
    qreal py = m_point->y() - m_radius * sin(0 *3.14 / 180);
    painter.drawLine(*m_point, QPointF(px, py));
    px = m_point->x() + m_radius * cos(45*3.14 / 180);
    py = m_point->y() - m_radius * sin(45*3.14 / 180);
    painter.drawLine(*m_point, QPointF(px, py));
    px = m_point->x() + m_radius * cos(90*3.14 / 180);
    py = m_point->y() - m_radius * sin(90*3.14 / 180);
    painter.drawLine(*m_point, QPointF(px, py));
    px = m_point->x() + m_radius * cos(135*3.14 / 180);
    py = m_point->y() - m_radius * sin(135*3.14 / 180);
    painter.drawLine(*m_point, QPointF(px, py));
    px = m_point->x() + m_radius * cos(180*3.14 / 180);
    py = m_point->y() - m_radius * sin(180*3.14 / 180);
    painter.drawLine(*m_point, QPointF(px, py));

    px = m_point->x() + m_radius * cos(m_rotate*3.14 / 180);
    py = m_point->y() - m_radius * sin(m_rotate*3.14 / 180);
    painter.drawLine(*m_point, QPointF(px, py));

    QConicalGradient gradient;
    gradient.setCenter(rect.center());
    //gradient.setAngle(m_rotate + 180); //渐变与旋转方向恰好相反，以扇形相反的边作为渐变角度。
    gradient.setColorAt(0.4, QColor(255, 255, 255, 100)); //从渐变角度开始0.5 - 0.75为扇形区域，由于Int类型计算不精确，将范围扩大到0.4-0.8
    gradient.setColorAt(0.8, QColor(255, 255, 255, 0));
    painter.setBrush(QBrush(gradient));
    painter.setPen(Qt::NoPen);
    if (m_dir)
        painter.drawPie(rect, (m_rotate-30) * 16, 30 * 16);
    else
        painter.drawPie(rect, m_rotate* 16, 30 * 16);
}


