#include "LyRadar.h"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LyRadar w;
    w.show();
    return a.exec();
}
