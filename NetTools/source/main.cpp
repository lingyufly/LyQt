#include <QApplication>
#include <QMainWindow>
#include <QNetworkInterface>
#include <QDialog>
#include <QtCore/QList>
#include <iostream>
#include <QDebug>
#include "scanip.h"

using namespace std;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    ScanIPWidget *scanip = new ScanIPWidget(NULL);
    scanip->show();
    return app.exec();
}