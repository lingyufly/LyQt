#ifndef _TESTQSTACKEDWIDGET_H_
#define _TESTQSTACKEDWIDGET_H_

#include <QDockWidget>
#include <QMainWindow>

class TestQStackedWidget :public QMainWindow
{
    Q_OBJECT
public:
    TestQStackedWidget(QWidget *parent = NULL, Qt::WindowFlags fl = Qt::WindowFlags());
    ~TestQStackedWidget();
protected:
private:
    QDockWidget *m_dockWidget;
    void setupUi();
};

#endif