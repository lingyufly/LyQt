#include "testQTreeWidget.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QGridLayout>
#include <QStringList>
#include <QPushButton>
#include <QDebug>

TestQTreeWidgetWidget::TestQTreeWidgetWidget(QWidget *parent, Qt::WindowFlags fl)
    :QWidget(parent, fl)
{
    QGridLayout *mainLayout = new QGridLayout(this);
    QTreeWidget *treeWidget = new QTreeWidget(this);
    treeWidget->setObjectName("treeWidget");
    mainLayout->addWidget(treeWidget);
    
    treeWidget->setColumnCount(3);
    treeWidget->setHeaderLabels(QStringList() << "AAA" << "BBB" << "CCC");
    QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget);
    item->setText(0, "1");
    item->setText(1, "2");
    item->setText(2, "3");
}

TestQTreeWidgetWidget::~TestQTreeWidgetWidget()
{
}