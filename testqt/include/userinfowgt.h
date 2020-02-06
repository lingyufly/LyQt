#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include <QMap>
#include <QString>
#include <QSettings>

class QTableWidget;
class QPushButton;

class UserInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfoWidget(QWidget *parent = 0);
    ~UserInfoWidget();
    int loaddata();
protected slots:
    void savedata();
    int deleteitem();
    int additem();
    void slot_itemChanged();

private:
    QMap<QString, QString> *m_users;
    int m_itemSize;

private:
    void setupUi();
    QTableWidget *m_infoTable;
    QPushButton *m_addBtn;
    QPushButton *m_delBtn;
    QPushButton *m_saveBtn;
};

#endif // USERINFO_H
