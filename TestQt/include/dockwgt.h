#ifndef _TESTQSTACKEDWIDGET_H_
#define _TESTQSTACKEDWIDGET_H_

#include <QDockWidget>
#include <QMainWindow>

class TestDockWidget :public QMainWindow
{
    Q_OBJECT
public:
    TestDockWidget(QWidget *parent = NULL, Qt::WindowFlags fl = Qt::WindowFlags());
    ~TestDockWidget();
protected:
private:
    QDockWidget *m_dockWidget;
    void setupUi();
};

#endif