#include "baseserver.h"
#include <QDebug>
#include <QTimerEvent>

BaseServer::BaseServer(QObject *parent):QObject(parent)
{
    connect(this, &BaseServer::signalErrMsg, this, &BaseServer::slotErrMsg);
    connect(this, &BaseServer::signalNewMsg, this, &BaseServer::slotErrMsg);
    connect(this, &BaseServer::signalStart, this, &BaseServer::slotStart);
    connect(this, &BaseServer::signalStop, this, &BaseServer::slotStop);

    m_thread=new QThread(NULL);
    m_thread->start();
}


BaseServer::~BaseServer()
{
}


void BaseServer::run()
{
    // exec();
}

void BaseServer::start()
{
    moveToThread(m_thread);
    emit signalStart();
}

void BaseServer::slotStart()
{
}

void BaseServer::quit()
{
    emit signalStop();
}

void BaseServer::slotStop()
{

}

void BaseServer::slotErrMsg(QString err)
{
    qDebug()<<err;
}