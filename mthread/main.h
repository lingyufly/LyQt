#ifndef _MAIN_H_
#define _MAIN_H_

#include <QThread>
#include <QObject>

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class MWork : public QObject
{
    Q_OBJECT
public:
    MWork(QObject *parent=nullptr);
    ~MWork();

public slots:
    void slot_work();

signals:
    void finished();
};

class MWidget : public QWidget
{
    Q_OBJECT
public:
    MWidget(QWidget *parent=nullptr);
    ~MWidget();

public slots:
    void slot_workFinished();

private:
    QPushButton *m_btn;
    QLabel *m_label;

    MWork *m_work;
    QThread *m_thread;
};


#endif