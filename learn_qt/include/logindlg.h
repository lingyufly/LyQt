#ifndef _LOGINDLG_H_
#define _LOGINDLG_H_

#include <QtWidgets/qdialog.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qpushbutton.h>
#include <QtCore/qstring.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlayout.h>


class LogInDlg : public QDialog
{
    Q_OBJECT
public:
    LogInDlg(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~LogInDlg();
    void setupUi();

protected slots:
    void slotVerifyUser();
    void slotExit();

private:
    QString m_userName;
    QString m_userPasswd;

    QLineEdit *m_leditUserName;
    QLineEdit *m_leditUserPasswd;
    QPushButton *m_btnLogin;
    QPushButton *m_btnExit;

};


#endif
