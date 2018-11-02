#include "rccar.h"
#include <QtWidgets/QApplication>

#include <QGridLayout>
#include <QPushButton>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaContent>
#include <QMediaPlayList>
#include <QFile>
#include <QDebug>
/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ControlWidget w;
    w.show();
    w.resize(600, 300);
    return a.exec();
}

*/


int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    QWidget *widget =new QWidget();
    widget->resize(400,300);
    QGridLayout *layout=new QGridLayout();
    QMediaPlayer *player =new QMediaPlayer();
    QVideoWidget *vw=new QVideoWidget();

    layout->addWidget(vw);
    widget->setLayout(layout);

    player->setVideoOutput(vw);
    widget->show();

    player->setMedia(QUrl::fromLocalFile("e:/code/Qt/QtDemo/build/movie.mp4"));
    player->setVolume(50);
    player->play();


    return a.exec();
}