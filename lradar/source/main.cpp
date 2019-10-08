#include "radar.h"
#include "baseserver.h"
#include "tcpserver.h"
#include "serialserver.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TcpServer *s=new TcpServer(nullptr);

    s->setMode(TcpServer::SERVER);
    s->setPort(9090);
    s->start();

    SerialServer *ss=new SerialServer(NULL);
    ss->start();

    // Radar w;
    // w.show();
    return a.exec();
}
