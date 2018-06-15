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

class QToolBar;
class QAction;
class QMenuBar;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupUi();
    bool login();

private:
    QToolBar *m_toolbar;
    QAction *m_action1;
    QAction *m_action2;
    QAction *m_modalAction1;
    QAction *m_modalAction2;
    QAction *m_modalessAction;
    QMenuBar *m_menuBar;
    QMenu *m_fileMenu;
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
    void slot_TestDialog();
};

#endif // MAINWINDOW_H
