#ifndef MOUSE_H
#define MOUSE_H

#include <QWidget>
#include <QTime>

namespace Ui {
class Mouse;
}

class Mouse : public QWidget
{
    Q_OBJECT

public:
    explicit Mouse(QWidget *parent = 0);
    ~Mouse();
protected:
    void mousePressEvent(QMouseEvent *e);       //--鼠标按下事件
    void mouseMoveEvent(QMouseEvent *e);    //--鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *e); //--鼠标释放（松开）事件
    void mouseDoubleClickEvent(QMouseEvent *e); //--鼠标双击事件

protected slots:
    void changeMouseTrckState(bool stat);
private:
    QTime ct, pt;
    Ui::Mouse *ui;
};

#endif // MOUSE_H
