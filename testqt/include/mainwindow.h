#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "logindlg.h"
#include "userinfowgt.h"
#include "mousewgt.h"
#include "testwgt.h"
#include "treewidgetwgt.h"
#include "dockwgt.h"
#include "testwizard.h"
#include "fileiowgt.h"

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
    QAction *m_wizardAction;
    QAction *m_filedialogAction;
    QMenuBar *m_menuBar;
    QMenu *m_fileMenu;
    QWidget *m_centerWidget;
    QTabWidget *m_tabWidget;
    LoginDialog *m_loginDlg;
    UserInfoWidget *m_userinfoWidget;
    MouseWidget *m_mouseWidget;
    TestQTreeWidgetWidget *m_qtreewidgettWidget;
    TestWidget *m_testWidget;
    TestDockWidget *m_dockWidget;
    TestWizard *m_wizard;
    FileIOWidget *m_fileioWidget;

protected slots:
    void slot_toggled(bool checked);
    void slot_triggered(bool checked = false);
    void slot_testDialog();
    void slot_testWizard();
    void slot_testFileDialog();
};

#endif // MAINWINDOW_H
