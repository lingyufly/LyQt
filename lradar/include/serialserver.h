#ifndef _SERIALSERVER_H_
#define _SERIALSERVER_H_
#include "baseserver.h"
#include <QSerialPort>


class SerialServer:public BaseServer
{
    Q_OBJECT
public:
    SerialServer(QObject *parent=Q_NULLPTR);
    ~SerialServer();

protected:
    // void run();

protected slots:
    void slotReadNewMsg();
    virtual void slotStart();
    virtual void slotStop();

private:
    QString m_portName;
    QSerialPort *m_serialPort;
    QSerialPort::BaudRate m_baudRate;
    QSerialPort::Direction m_direction;
    QSerialPort::DataBits m_dataBits;
    QSerialPort::FlowControl m_flowControl;
    QSerialPort::Parity m_parity;
    QSerialPort::StopBits m_stopBits;

};
#endif