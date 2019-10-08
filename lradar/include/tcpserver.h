#ifndef _TCPSERVER_H_
#define _TCPSERVER_H_

#include "baseserver.h"
#include <QTcpServer>
#include <QTcpSocket>

class TcpServer:public BaseServer
{
    Q_OBJECT

public:
    TcpServer(QObject *parent=Q_NULLPTR);
    ~TcpServer();

    enum MODE{NONE, SERVER, CLIENT};

    void setMode(MODE mode);
    MODE getMode();

    void setHost(QString host);
    QString getHost();

    void setPort(int port);
    int getPort();

protected:

protected slots:
    void slotGetNewConnection();
    void slotReadNewMsg();
    void slotGetErrMsg(QAbstractSocket::SocketError socketError);
    virtual void slotStart();
    virtual void slotStop();

private:
    MODE m_mode;
    QTcpServer *m_server;
    QTcpSocket *m_socket;
    QString m_host;
    int m_port;
};


#endif