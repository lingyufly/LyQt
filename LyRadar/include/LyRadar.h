#ifndef _LYRADAR_H_
#define _LYRADAR_H_


#include <QtWidgets/QWidget>
#include <QtCore/QVector>

class QTimerEvent;
class QPoint;
class QColor;

class LyRadar : public QWidget
{
    Q_OBJECT

public:
    LyRadar(QWidget *parent = Q_NULLPTR, Qt::WindowFlags fl=Qt::WindowFlags());
    ~LyRadar();

    void paintEvent(QPaintEvent * event);
    void timerEvent(QTimerEvent *evet);

    void pushPoint(double angle, double distance);

private:
    int m_width;
    int m_height;
    int m_radius;
    double m_maxDistance;
    bool m_dir;
    QRect m_rect;
    QPoint m_center;
    QColor m_fontColor;
    QColor m_groudColor;

    QVector<QPointF> m_points;

    QPixmap *m_pix;
    void preDraw();
    void drawCircle(QPainter &painter);
    void drawArc(QPainter &painter);
    void drawScan(QPainter & painter, double angle);
    void addPoint(double angle, double distance);
    void drawPoints(QPainter & painter);
    
};





#endif // !_LYRADAR_H_



