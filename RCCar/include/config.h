#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <QDialog>

class QLabel;
class QLineEdit;
class QCheckBox;
class QPushButton;
class QGridLayout;

class ConfigWidget :public QDialog
{
    Q_OBJECT
public:
    ConfigWidget(QWidget *parent = NULL, Qt::WindowFlags fl = Qt::WindowFlags());
    virtual ~ConfigWidget();
    void setControlUrl(QString url);
    QString getControlUrl();
    void setVideoUrl(QString url);
    QString getVideoUrl();
    void setShowInfo(bool check);
    bool getShowInfo();
    void setShowLog(bool check);
    bool getShowLog();

protected slots:
    void slot_save();
    void slot_cancle();

private:
    QGridLayout *m_mainLayout;
    QLabel *m_controlUrlLabel;
    QLineEdit *m_controlUrlEdit;
    QLabel *m_videoUrlLabel;
    QLineEdit *m_videoUrlEdit;
    QCheckBox *m_showInfoCBox;
    QCheckBox *m_showLogCBox;
    QPushButton *m_saveBtn;
    QPushButton *m_cancleBtn;
    void setupUi();
};
#endif