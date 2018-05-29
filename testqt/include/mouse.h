#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <QWidget>
#include <QTime>
class QLabel;
class QTextBrowser;
class QCheckBox;

class Mouse : public QWidget
{
    Q_OBJECT

public:
    explicit Mouse(QWidget *parent = 0);
    ~Mouse();
    void setupUi();
protected:
    void mousePressEvent(QMouseEvent *e);       //--��갴���¼�
    void mouseMoveEvent(QMouseEvent *e);    //--����ƶ��¼�
    void mouseReleaseEvent(QMouseEvent *e); //--����ͷţ��ɿ����¼�
    void mouseDoubleClickEvent(QMouseEvent *e); //--���˫���¼�

    protected slots:
    void changeMouseTrckState(bool stat);
private:
    QTime ct, pt;
    QLabel *m_mouseposLabel;
    QCheckBox *m_mouseTrackCbox;
    QTextBrowser *m_textBrowser;
};

#endif // MOUSE_H
