#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qtabwidget.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qwidget.h>

#include "mouseeventwgt.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = Q_NULLPTR, Qt::WindowFlags flags = Qt::WindowFlags());
    ~MainWindow();
    void setupUi();


private:
    QWidget * m_widgetCentral;
    QTabWidget * m_tabWidget;
    QPushButton *m_btnExit;
    QPushButton *m_btnRestart;

    MouseEventWgt *m_widgetMouseEvent;
};
#endif // !_MAINWINDOW_H_

