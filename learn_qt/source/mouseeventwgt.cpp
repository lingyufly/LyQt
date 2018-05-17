#include "mouseeventwgt.h"
#include <QtWidgets/QMainWindow>

MouseEventWgt::MouseEventWgt(QWidget *parent, Qt::WindowFlags f)
    :QWidget(parent, f)
{
    setupUi();
}

MouseEventWgt::~MouseEventWgt()
{

}

void MouseEventWgt::setupUi()
{
    QVBoxLayout *layoutMain = new QVBoxLayout(this);

    QHBoxLayout *hlayout = new QHBoxLayout();
    QLabel *label = new QLabel(this);
    label->setText("Mouse Position: ");
    m_labelMousePos = new QLabel(this);
    QSpacerItem *spacer = new QSpacerItem(100,20,QSizePolicy::Expanding);
    hlayout->addWidget(label);
    hlayout->addWidget(m_labelMousePos);
    hlayout->addItem(spacer);

    layoutMain->addLayout(hlayout);

    spacer = new QSpacerItem(20, 100, QSizePolicy::Expanding);
    layoutMain->addItem(spacer);

    m_cboxMouseTracking = new QCheckBox(this);
    m_cboxMouseTracking->setText("Tracking Mouse");
    layoutMain->addWidget(m_cboxMouseTracking);
    m_textLog = new QTextBrowser(this);
    layoutMain->addWidget(m_textLog);

    connect(m_cboxMouseTracking, SIGNAL(toggled(bool)), this, SLOT(slotMouseTrackingChanged(bool)));
}

void MouseEventWgt::mousePressEvent(QMouseEvent * e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_textLog->append("Left Button Press");
    }
    else if (e->button() == Qt::RightButton)
    {
        m_textLog->append("Right Button Press");
    }
    else if (e->button() == Qt::MiddleButton)
    {
        m_textLog->append("Middle Button Press");
    }
}

void MouseEventWgt::mouseMoveEvent(QMouseEvent * e)
{
    QString str = "X:" + QString::number(e->globalX()) + " Y:" + QString::number(e->globalY());
    m_labelMousePos->setText(str);
}

void MouseEventWgt::mouseReleaseEvent(QMouseEvent * e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_textLog->append("Left Button Release");
    }
    else if (e->button() == Qt::RightButton)
    {
        m_textLog->append("Right Button Release");
    }
    else if (e->button() == Qt::MiddleButton)
    {
        m_textLog->append("Middle Button Release");
    }
}

void MouseEventWgt::mouseDoubleClickEvent(QMouseEvent * e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_textLog->append("Left Button Double Click");
    }
    else if (e->button() == Qt::RightButton)
    {
        m_textLog->append("Right Button Double Click");
    }
    else if (e->button() == Qt::MiddleButton)
    {
        m_textLog->append("Middle Button Double Click");
    }
}


void MouseEventWgt::slotMouseTrackingChanged(bool state)
{
    setMouseTracking(state);
}