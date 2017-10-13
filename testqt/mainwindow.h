#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "login.h"
#include "userinfo.h"
#include "mouse.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void show();

private:
    Login *login;
    Ui::MainWindow *ui;
    UserInfo *userinfoTab;
    Mouse *mouseTab;
};

#endif // MAINWINDOW_H
