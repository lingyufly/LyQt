#include "tcpserver.h"
#include <QHostAddress>
#include <QDebug>
#include <QAbstractSocket>
#include <QWidget>

TcpServer::TcpServer(QObject *parent):BaseServer(parent)
{
    m_server=NULL;
    m_socket=NULL;
    m_mode=NONE;
    m_port=8899;
    m_msg="";
}

TcpServer::~TcpServer()
{
}

void TcpServer::slotStart()
{
    bool ret;
    if (m_mode==SERVER)
    {
        m_server=new QTcpServer(this);
        connect(m_server, &QTcpServer::newConnection, this, &TcpServer::slotGetNewConnection);
        connect(m_server, &QTcpServer::acceptError, this, &TcpServer::slotGetErrMsg);
        m_server->setMaxPendingConnections(1);
        ret=m_server->listen(QHostAddress::Any, m_port);
        if (ret==false)
        {
            QString err=QString("Listen port %1 error").arg(m_port);
            emit signalErrMsg(err);
        }
    }
    else if (m_mode==CLIENT)
    {
        m_socket=new QTcpSocket(this);
        connect(m_socket, &QTcpSocket::readyRead, this, &TcpServer::slotReadNewMsg);
        connect(m_socket, QOverload<QTcpSocket::SocketError>::of(&QTcpSocket::error), this, &TcpServer::slotGetErrMsg);
        ret=m_socket->bind(QHostAddress(m_port), m_port);
        if (ret==false)
        {
            QString err=QString("Bind host %1 port %2 error").arg(m_host).arg(m_port);
            emit signalErrMsg(err);
        }
    }
    else
    {
        emit signalErrMsg("Server Mode error");
    }
}

void TcpServer::slotStop()
{
}

void TcpServer::setMode(TcpServer::MODE mode)
{
    m_mode=mode;
}

TcpServer::MODE TcpServer::getMode()
{
    return m_mode;
}

void TcpServer::setHost(QString host)
{
    m_host=host;
}

QString TcpServer::getHost()
{
    return m_host;
}

void TcpServer::setPort(int port)
{
    m_port=port;
}

int TcpServer::getPort()
{
    return m_port;
}

void TcpServer::slotGetNewConnection()
{
    if (m_socket!=NULL && m_socket->state()==QTcpSocket::ConnectedState)
    {
        QTcpSocket *s=m_server->nextPendingConnection();
        s->close();
        return;
    }
    if (m_socket!=NULL)
    {
        m_socket->close();
        delete m_socket;
    }
    m_socket=m_server->nextPendingConnection();
    m_host=m_socket->peerAddress().toString();
    connect(m_socket, &QTcpSocket::readyRead, this, &TcpServer::slotReadNewMsg);
    connect(m_socket, QOverload<QTcpSocket::SocketError>::of(&QTcpSocket::error), this, &TcpServer::slotGetErrMsg);
}


void TcpServer::slotReadNewMsg()
{
    QString msg=m_socket->readAll();
    // 解析报文
    qDebug()<<msg;
}

void TcpServer::slotGetErrMsg(QAbstractSocket::SocketError socketError)
{
    QString err=QString("Server accept error %1").arg(socketError);
    emit signalErrMsg(err);
}