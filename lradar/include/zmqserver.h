#ifndef _ZMQSERVER_H_
#define _ZMQSERVER_H_

#include "baseserver.h"


class ZmqServer:public BaseServer
{
    Q_OBJECT
public:
    ZmqServer(QObject *parent=Q_NULLPTR);
    ~ZmqServer();

protected:
    virtual void run();

protected slots:
    virtual void slotStart();
    virtual void slotStop();

private:

};


#endif