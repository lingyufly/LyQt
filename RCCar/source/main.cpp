#include "rccar.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControlWidget w;
    w.show();
    w.resize(600, 300);
    return a.exec();
}


