#include "main.h"
#include <QDebug>
#include <QApplication>
#include <QVBoxLayout>

MWork::MWork(QObject *parent) : QObject(nullptr)
{ }

MWork::~MWork()
{ }

void MWork::slot_work()
{
    QThread::currentThread()->sleep(10);
    emit finished();
}

MWidget::MWidget(QWidget *parent):QWidget(parent)
{
    QVBoxLayout *vbox=new QVBoxLayout(this);
    m_btn=new QPushButton("Click Me", this);
    m_label=new QLabel(this);

    vbox->addWidget(m_btn);
    vbox->addWidget(m_label);

    m_work=new MWork();
    connect(m_btn, &QPushButton::clicked, m_work, &MWork::slot_work);
    connect(m_work, &MWork::finished, this, &MWidget::slot_workFinished);

    m_thread=new QThread(this);
    m_work->moveToThread(m_thread);
    m_thread->start();
}

MWidget::~MWidget()
{

}

void MWidget::slot_workFinished()
{
    m_label->setText("Work Finished");
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MWidget *mw=new MWidget();
    mw->show();
    return app.exec();
}


