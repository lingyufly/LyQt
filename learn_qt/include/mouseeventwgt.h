#ifndef _MOUSEEVENTWGT_H_
#define _MOUSEEVENTWGT_H_


#include <QtWidgets/qwidget.h>
#include <QtWidgets/qcheckbox.h>
#include <QtWidgets/qtextbrowser.h>
#include <QtCore/qdatetime.h>
#include <Qtgui/qevent.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qlabel.h>


class MouseEventWgt : public QWidget
{
    Q_OBJECT
public:
    MouseEventWgt(QWidget *parent=Q_NULLPTR, Qt::WindowFlags f=Qt::WindowFlags());
    ~MouseEventWgt();
    void setupUi();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);

protected slots:
    void slotMouseTrackingChanged(bool state);

private:
    QLabel * m_labelMousePos;
    QCheckBox *m_cboxMouseTracking;
    QTextBrowser *m_textLog;
};


#endif // !_MOUSEEVENTDLG_H_

