#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "login.h"
#include "userinfo.h"
#include "mouse.h"
#include "test.h"
#include "testQTreeWidget.h"
#include "testQStackedWidget.h"


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
    Login *m_loginDlg;
    UserInfo *m_userinfoWidget;
    Mouse *m_mouseWidget;
    TestQTreeWidgetWidget *m_qtreewidgettWidget;
    TestWidget *m_testWidget;
    TestQStackedWidget *m_qstackedwidgetWidget;

protected slots:
    void slot_toggled(bool checked);
    void slot_triggered(bool checked = false);
};

#endif // MAINWINDOW_H
