#ifndef _BASESERVER_H_
#define _BASESERVER_H_

#include <QThread>
#include <QString>
#include <QDebug>

class BaseServer:public QObject
{
    Q_OBJECT

public:
    BaseServer(QObject *parent=Q_NULLPTR);
    virtual ~BaseServer();
    virtual void start();
    virtual void quit();

protected:
    virtual void run();

protected slots:
    void slotErrMsg(QString msg);
    virtual void slotStart();
    virtual void slotStop();

signals:
    void signalStart();
    void signalStop();
    void signalNewMsg(QString msg);
    void signalErrMsg(QString err);

private:
    QThread *m_thread;
};


#endif