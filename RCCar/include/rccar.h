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
class QButtonGroup;


class ControlWidget :public QWidget
{
    Q_OBJECT
public:
    ControlWidget(QWidget *parent = NULL, Qt::WindowFlags fl = Qt::WindowFlags());
    virtual ~ControlWidget();

    void setVideoUrl(QString url);
    void setControlUrl(QString url);
    void setShowInfo(bool shown);
    void setShowLog(bool shown);

    typedef enum 
    {
        NONE=0x00,
        GOFORE=0x01,
        GOBACK=0x02,
        TURNLEFT=0x04,
        TURNRIGHT=0x08,
        VIEWLEFT=0x10,
        VIEWRIGHT=0x20
    }CTRLACTION;

protected:
    void setupUi();
    void repaintCtl();
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

    bool readConfig();
    void writeConfig();

protected slots:
    void slot_showPic(QNetworkReply *reply);
    void slot_gofore();
    void slot_goback();
    void slot_turnleft();
    void slot_turnright();
    void slot_stop();

    void slot_showLog(QString msg);
    void slot_showinfo(QString msg);
    void slot_viewChanged(int angle);
    void slot_viewReset();
    void slot_viewTimer();
    void slot_openSetting();

signals:
    void signal_logmsg(QString msg);

private:
    QGridLayout *m_mainLayout;
    QLabel *m_picLabel;
    QPushButton *m_foreBtn;
    QPushButton *m_backBtn;
    QPushButton *m_leftBtn;
    QPushButton *m_rightBtn;
    QButtonGroup *m_drctBtnGroup;
    QPushButton *m_resetViewBtn;
    QSlider *m_viewSlider;
    QLabel *m_infoLabel;
    QLabel *m_logLabel;
    QPushButton *m_settingBtn;
    QTimer *m_viewTimer;

    QNetworkRequest m_picRequest;
    QNetworkAccessManager *m_picManager;

    QString m_controlUrl;
    QString m_videoUrl;
    bool m_showInfo;
    bool m_showLog;

    CTRLACTION m_viewAction;

    QSize m_size;
};

#endif
