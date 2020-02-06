#include "dockwgt.h"
#include "fileiowgt.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QTextEdit>

TestDockWidget::TestDockWidget(QWidget *parent, Qt::WindowFlags fl)
    :QMainWindow(parent, fl)
{
    setupUi();
}

TestDockWidget::~TestDockWidget()
{

}

void TestDockWidget::setupUi()
{
    QWidget *m_centralWidget = new QWidget(this);
    setCentralWidget(m_centralWidget);
    QVBoxLayout *m_mainLayout = new QVBoxLayout(m_centralWidget);
    QTextEdit *m_textEdit = new QTextEdit(m_centralWidget);
    m_mainLayout->addWidget(m_textEdit);

    QHBoxLayout *hbox = NULL;
    QVBoxLayout *vbox = NULL;

    m_dockWidget = new QDockWidget("Dock1", this);
    m_dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QPushButton *btn = new QPushButton("Button1", m_dockWidget);
    m_dockWidget->setWidget(btn);
    addDockWidget(Qt::LeftDockWidgetArea, m_dockWidget);

    m_dockWidget = new QDockWidget("Dock2", this);
    m_dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    btn = new QPushButton("Button2", m_dockWidget);
    m_dockWidget->setWidget(btn);
    addDockWidget(Qt::RightDockWidgetArea, m_dockWidget);

    m_dockWidget = new QDockWidget("Dock3", this);
    m_dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    btn = new QPushButton("Button3", m_dockWidget);
    m_dockWidget->setWidget(btn);
    addDockWidget(Qt::TopDockWidgetArea, m_dockWidget);

    m_dockWidget = new QDockWidget("Dock4", this);
    m_dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    btn = new QPushButton("Button4", m_dockWidget);
    m_dockWidget->setWidget(btn);
    addDockWidget(Qt::BottomDockWidgetArea, m_dockWidget);
}