#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include <QMap>
#include <QString>
#include <QSettings>

namespace Ui {
class UserInfo;
}

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = 0);
    ~UserInfo();
    int loaddata();
protected slots:
    void savedata();
    int deleteitem();
    int additem();

private:
    QMap<QString, QString> *users;
    int itemSize;
    Ui::UserInfo *ui;
};

#endif // USERINFO_H
