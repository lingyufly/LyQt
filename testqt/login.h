#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QVector>
#include <QString>
#include <QMap>
using namespace std;
namespace Ui {
class login;
}

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
    Ui::login *ui;
    QMap<QString, QString> *users;
    int loadusers();
};

#endif // LOGIN_H
