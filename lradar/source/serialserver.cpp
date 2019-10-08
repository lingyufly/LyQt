#include "serialserver.h"

SerialServer::SerialServer(QObject *parent):BaseServer(parent)
{
    m_serialPort=new QSerialPort(this);
    m_portName=QString::null;
    m_baudRate=QSerialPort::Baud115200;
    m_direction=QSerialPort::AllDirections;
    m_dataBits=QSerialPort::Data8;
    m_flowControl=QSerialPort::NoFlowControl;
    m_parity=QSerialPort::NoParity;
    m_stopBits=QSerialPort::OneStop;

    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialServer::slotReadNewMsg);
}

SerialServer::~SerialServer()
{
    if (m_serialPort->isOpen())
    {
        m_serialPort->clear();
        m_serialPort->close();
    }
}


void SerialServer::slotStart()
{
    if (m_serialPort->isOpen() || m_portName==QString::null)
    {
        return;
    }

    m_serialPort->setPortName(m_portName);
    bool ret=m_serialPort->open(QIODevice::ReadWrite);

    if (ret==false)
    {
        QString err=QString("Open port %1 error").arg(m_portName);
        emit signalErrMsg(err);
        return;
    }

    m_serialPort->setBaudRate(m_baudRate,m_direction);
    m_serialPort->setDataBits(m_dataBits);
    m_serialPort->setFlowControl(m_flowControl);
    m_serialPort->setParity(m_parity);
    m_serialPort->setStopBits(m_stopBits);
}

void SerialServer::slotStop()
{
}

void SerialServer::slotReadNewMsg()
{

}

