#ifndef _RCCAR_H_
#define _RCCAR_H_

#include <QWidget>
#include <QUrl>
#include <QNetworkRequest>
#include <QSlider>
class QPushButton;
class QGridLayout;
class QVideoWidget;
class QMediaPlayer;
class QLabel;
class QNetworkReply;
class QNetworkAccessManager;
class QTimer;

class LSlider : public QSlider
{
    Q_OBJECT
public:
    LSlider(QWidget *parent=NULL);
    LSlider(Qt::Orientation orientation, QWidget *parent=NULL);
    virtual ~LSlider();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
};


class ControlWidget :public QWidget
{
    Q_OBJECT
public:
    ControlWidget(QWidget *parent = NULL, Qt::WindowFlags fl = Qt::WindowFlags());
    virtual ~ControlWidget();

    typedef enum 
    {
        NONE=0x00000000,
        GOFORE=0x00000001,
        GOBACK=0x00000010,
        TURNLEFT=0x00000100,
        TURNRIGHT=0x00001000,
        VIEWLEFT=0x00010000,
        VIEWRIGHT=0x00100000
    }CTRLACTION;

protected:
    void setupUi();
    void repaintCtl();
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

protected slots:
    void slot_showPic(QNetworkReply *reply);
    void slot_gofore();
    void slot_goback();
    void slot_turnleft();
    void slot_turnright();
    void slot_stop();
    void slot_viewleft();
    void slot_viewright();
    void slot_showinfo(QString msg);
    void slot_viewChanged(int angle);
    void slot_viewReset();
    void slot_viewTimer();

signals:
    void signal_logmsg(QString msg);

private:
    QGridLayout *m_mainLayout;
    QLabel *m_picLabel;
    QPushButton *m_foreBtn;
    QPushButton *m_backBtn;
    QPushButton *m_leftBtn;
    QPushButton *m_rightBtn;
    LSlider *m_viewSlider;

    QTimer *m_viewTimer;

    QUrl m_picUrl;
    QNetworkRequest m_picRequest;
    QNetworkAccessManager *m_picManager;

    int m_ctrlaction;
};

#endif
