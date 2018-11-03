#ifndef _RCCAR_H_
#define _RCCAR_H_

#include <QWidget>
#include <QUrl>
#include <QNetworkRequest>
class QPushButton;
class QGridLayout;
class QVideoWidget;
class QMediaPlayer;
class QLabel;
class QNetworkReply;
class QNetworkAccessManager;

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

protected slots:
    void slot_showPic(QNetworkReply *reply);
private:
    QGridLayout *m_mainLayout;
    QLabel *m_picLabel;
    QPushButton *m_foreBtn;
    QPushButton *m_backBtn;
    QPushButton *m_leftBtn;
    QPushButton *m_rightBtn;
    QMediaPlayer *m_player;

    QUrl m_picUrl;
    QNetworkRequest m_picRequest;
    QNetworkAccessManager *m_picManager;
};

#endif
