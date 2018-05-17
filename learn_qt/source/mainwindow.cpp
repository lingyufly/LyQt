#include <QtWidgets/qlayoutitem.h>
#include <QtCore/qdebug.h>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget * parent, Qt::WindowFlags flags)
    :QMainWindow(parent,flags)
{
    setupUi();
}



MainWindow::~MainWindow()
{

}

void MainWindow::setupUi()
{
    this->resize(700, 400);
    
    m_widgetCentral = new QWidget(this);
    
    QVBoxLayout *layoutMain = new QVBoxLayout(m_widgetCentral);
    layoutMain->setContentsMargins(11, 11, 11, 11);

    m_tabWidget = new QTabWidget(this);
    layoutMain->addWidget(m_tabWidget);
    
    QHBoxLayout *layoutButtons = new QHBoxLayout();
    m_btnExit = new QPushButton("Exit", this);
    m_btnRestart = new QPushButton("Restart", this);
    QSpacerItem *spaceritem = new QSpacerItem(100, 20, QSizePolicy::Expanding);
    layoutButtons->addItem(spaceritem);
    layoutButtons->addWidget(m_btnExit);
    layoutButtons->addWidget(m_btnRestart);
    layoutMain->addLayout(layoutButtons);

    this->setCentralWidget(m_widgetCentral);

    m_widgetMouseEvent = new MouseEventWgt(this);
    m_tabWidget->addTab(m_widgetMouseEvent, "MouseEvent");
}