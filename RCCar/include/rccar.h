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
class QTcpSocket;

#define STOP 0x00
#define GOFORE 0x01
#define GOBACK 0x02
#define TURNLEFT 0x04
#define TURNRIGHT 0x08
#define VIEWACTION 0x10

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
        VIEWNONE = 0x00,
        VIEWLEFT = 0x01,
        VIEWRIGHT = 0x02,
        VIEWUP = 0x04,
        VIEWDOWN = 0x08
    }VIEWDIRECTION;

protected:
    void setupUi();
    void init();
    void repaintUi();
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

    bool readConfig();
    void writeConfig();

protected slots:
    void slot_showPicture(QNetworkReply *reply);
    void slot_sendMsg(QString msg);
    void slot_readMsg();
    void slot_ctrlConnect();
    void slot_ctrlDisconnect();

    void slot_goFore();
    void slot_goBack();
    void slot_turnLeft();
    void slot_turnRight();
    void slot_stop();

    void slot_showLog(QString msg);
    void slot_showInfo(QString msg);

    void slot_viewChanged(int angle);
    void slot_viewReset();
    void slot_viewTimer();

    void slot_settingDlg();

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

    QTcpSocket *m_ctrlSocket;

    QString m_controlUrl;
    QString m_videoUrl;
    bool m_showInfo;
    bool m_showLog;

    VIEWDIRECTION m_viewAction;

    QSize m_size;
};

#endif
