#include "testQTreeWidget.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QGridLayout>
#include <QStringList>
#include <QPushButton>
#include <QList>
#include <QDebug>

TestQTreeWidgetWidget::TestQTreeWidgetWidget(QWidget *parent, Qt::WindowFlags fl)
    :QWidget(parent, fl)
{
    QGridLayout *mainLayout = new QGridLayout(this);
    m_treeWidget = new QTreeWidget(this);
    m_treeWidget->setObjectName("m_treeWidget");
    mainLayout->addWidget(m_treeWidget);
    
    m_treeWidget->setColumnCount(3);
    m_treeWidget->setHeaderLabels(QStringList() << "AAA" << "BBB" << "CCC");
    m_treeWidget->headerItem()->setText(0, "000");

    connect(m_treeWidget, &QTreeWidget::currentItemChanged, this, &TestQTreeWidgetWidget::slot_CurrentChanged);
    connect(m_treeWidget, &QTreeWidget::itemSelectionChanged, this, &TestQTreeWidgetWidget::slot_SelectedChanged);

    QTreeWidgetItem *item = new QTreeWidgetItem(m_treeWidget);
    item->setText(0, "11");
    item->setText(1, "12");
    item->setText(2, "13");

    item = new QTreeWidgetItem(m_treeWidget);
    item->setText(0, "21");
    item->setText(1, "22");
    item->setText(2, "23");

    item = new QTreeWidgetItem(m_treeWidget);
    item->setText(0, "31");
    item->setText(1, "32");
    item->setText(2, "33");

    item = new QTreeWidgetItem(m_treeWidget);
    item->setText(0, "41");
    item->setText(1, "42");
    item->setText(2, "43");

    item = new QTreeWidgetItem(m_treeWidget);
    item->setText(0, "51");
    item->setText(1, "52");
    item->setText(2, "53");

    item = new QTreeWidgetItem(item);
    item->setText(0, "531");
    item->setText(1, "532");
    item->setText(2, "533");

    if (m_treeWidget->indexOfTopLevelItem(item)!=-1)
        qDebug() << item->treeWidget()->objectName();
}

TestQTreeWidgetWidget::~TestQTreeWidgetWidget()
{
}

void TestQTreeWidgetWidget::slot_CurrentChanged()
{
    QTreeWidgetItem *item = m_treeWidget->currentItem();
    int index=m_treeWidget->indexOfTopLevelItem(item);
    qDebug() << "slot_CurrentChanged, index="<<index;
}

void TestQTreeWidgetWidget::slot_SelectedChanged()
{
    QList<QTreeWidgetItem*> items = m_treeWidget->selectedItems();
    QString indexStr;
    for (int i = 0; i < items.count(); i++)
    {
        QTreeWidgetItem *item = items.at(i);
        int index = m_treeWidget->indexOfTopLevelItem(item);
        indexStr += QString::number(index) + " ";
    }
    qDebug() << "slot_SelectedChanged, count=" << items.count() << " index=" << qPrintable(indexStr);
}