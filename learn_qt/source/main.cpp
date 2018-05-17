#include <QtWidgets/qapplication.h>

#include "mainwindow.h"
#include "logindlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LogInDlg *login = new LogInDlg();
    if (login->exec()==QDialog::Rejected)
    {
    return 1;
    }
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
    return a.exec();
}
