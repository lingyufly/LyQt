#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "login.h"
#include "userinfo.h"
#include "mouse.h"
#include "testQTreeWidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupUi();
    bool login();

private:
    QWidget *m_centerWidget;
    QTabWidget *m_tabWidget;
    Login *m_login;
    UserInfo *m_userinfoTab;
    Mouse *m_mouseTab;
    TestQTreeWidgetWidget *m_qtreewidgettwgt;
};

#endif // MAINWINDOW_H
