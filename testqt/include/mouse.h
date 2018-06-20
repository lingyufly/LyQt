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
    void mousePressEvent(QMouseEvent *e);       //--鼠标按下事件
    void mouseMoveEvent(QMouseEvent *e);        //--鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *e);     //--鼠标释放事件
    void mouseDoubleClickEvent(QMouseEvent *e); //--鼠标双击事件

    protected slots:
    void changeMouseTrckState(bool stat);
private:
    QTime ct, pt;
    QLabel *m_mouseposLabel;
    QCheckBox *m_mouseTrackCbox;
    QTextBrowser *m_textBrowser;
};

#endif // MOUSE_H
