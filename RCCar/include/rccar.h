#ifndef _RCCAR_H_
#define _RCCAR_H_

#include <QWidget>
class QPushButton;
class QGridLayout;
class QVideoWidget;
class QMediaPlayer;

class ControlWidget :public QWidget
{
    Q_OBJECT
public:
    ControlWidget(QWidget *parent = NULL, Qt::WindowFlags fl = Qt::WindowFlags());
    virtual ~ControlWidget();

protected:
    void setupUi();
    void repaintCtl();
    virtual void paintEvent(QPaintEvent *event);

private:
    QGridLayout *m_mainLayout;
    QVideoWidget *m_videoWgt;
    QPushButton *m_foreBtn;
    QPushButton *m_backBtn;
    QPushButton *m_leftBtn;
    QPushButton *m_rightBtn;
    QMediaPlayer *m_player;
};

#endif