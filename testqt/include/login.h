#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
class QString;
class QLabel;
class QLineEdit;
class QPushButton;

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

protected slots:
    void checkuserandpass();

signals:
    void senduserandpass(QString user, QString pass);

private:
    int loadusers();
    void setupUi();
    QMap<QString, QString> *m_users;
    

    QLineEdit *m_userLineEdit;
    QLineEdit *m_passLineEdit;
    QPushButton *m_loginBtn;
    QPushButton *m_exitBtn;

};

#endif // LOGIN_H
