#include "dockwgt.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QTextEdit>

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
    QWidget *m_centralWidget = new QWidget(this);
    setCentralWidget(m_centralWidget);
    QVBoxLayout *m_mainLayout = new QVBoxLayout(m_centralWidget);
    QTextEdit *m_textEdit = new QTextEdit(m_centralWidget);
    m_mainLayout->addWidget(m_textEdit);

    QHBoxLayout *hbox = NULL;
    QVBoxLayout *vbox = NULL;

    m_dockWidget = new QDockWidget(this);
    m_dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QPushButton *btn = new QPushButton("Button1", m_dockWidget);
    m_dockWidget->setWidget(btn);
    addDockWidget(Qt::LeftDockWidgetArea, m_dockWidget);

    m_dockWidget = new QDockWidget(this);
    m_dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    btn = new QPushButton("Button2", m_dockWidget);
    m_dockWidget->setWidget(btn);
    addDockWidget(Qt::RightDockWidgetArea, m_dockWidget);

    m_dockWidget = new QDockWidget(this);
    m_dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    btn = new QPushButton("Button3", m_dockWidget);
    m_dockWidget->setWidget(btn);
    addDockWidget(Qt::TopDockWidgetArea, m_dockWidget);
}