#ifndef _LYRADAR_H_
#define _LYRADAR_H_


#include <QtWidgets/QWidget>

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

private:
    int m_width;
    int m_height;
    int m_radius;
    double m_rotate;
    double m_distance;
    bool m_dir;
    QPoint *m_point;
    QColor m_fontColor;
    QColor m_groudColor;

    QPixmap m_pix;
    void preDraw();
    void drawCircle(QPainter &painter);
    void drawArc(QPainter &painter);
    
};





#endif // !_LYRADAR_H_



