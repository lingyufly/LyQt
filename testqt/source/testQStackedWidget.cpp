#include "testQStackedWidget.h"

#include <QPushButton>
#include <QVBoxLayout>

TestQStackedWidget::TestQStackedWidget(QWidget *parent, Qt::WindowFlags fl)
    :QMainWindow(parent, fl)
{
    setupUi();
}

TestQStackedWidget::~TestQStackedWidget()
{

}

void TestQStackedWidget::setupUi()
{
    QVBoxLayout *m_mainLayout = new QVBoxLayout(this);

    m_dockWidget = new QDockWidget(this);
    m_dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    m_mainLayout->addWidget(m_dockWidget);
    QPushButton *btn1 = new QPushButton("Button1", m_dockWidget);
    addDockWidget(Qt::LeftDockWidgetArea, m_dockWidget);

    m_dockWidget = new QDockWidget(this);
    m_dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    m_mainLayout->addWidget(m_dockWidget);
    btn1 = new QPushButton("Button2", m_dockWidget);
    addDockWidget(Qt::RightDockWidgetArea, m_dockWidget);


    m_dockWidget = new QDockWidget(this);
    m_dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    m_mainLayout->addWidget(m_dockWidget);
    btn1 = new QPushButton("Button3", m_dockWidget);
    addDockWidget(Qt::TopDockWidgetArea, m_dockWidget);

}