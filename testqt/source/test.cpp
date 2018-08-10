#include "test.h"

#include <QDateTimeEdit>
#include <QBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QButtonGroup>
#include <QRadioButton>
#include <QColor>
#include <QPalette>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDebug>
#include <QComboBox>
#include <QLineEdit>

TestWidget::TestWidget(QWidget *parent, Qt::WindowFlags fl)
    :QWidget(parent, fl)
{
    setupUi();
}

TestWidget::~TestWidget()
{

}

void TestWidget::setupUi()
{
    QVBoxLayout *main_layout = new QVBoxLayout(this);
    QSpacerItem *spacer = NULL;
    QHBoxLayout *hbox = NULL;
    m_datetime = new QDateTimeEdit(this);
    main_layout->addWidget(m_datetime);

    QGroupBox *groupbox = new QGroupBox(this);
    QRadioButton *m_rbtn1 = new QRadioButton("Radio 1", groupbox);
    QRadioButton *m_rbtn2 = new QRadioButton("Radio 2", groupbox);
    spacer = new QSpacerItem(20, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);
    hbox = new QHBoxLayout(groupbox);
    hbox->addWidget(m_rbtn1);
    hbox->addWidget(m_rbtn2);
    hbox->addSpacerItem(spacer);
    m_rbtn2->setChecked(true);
    groupbox->setEnabled(false);
    main_layout->addWidget(groupbox);

    QPushButton *m_colorBtn = new QPushButton(this);
    QPalette pal = m_colorBtn->palette();
    pal.setColor(QPalette::Window, Qt::blue);
    m_colorBtn->setAutoFillBackground(true);
    m_colorBtn->setFlat(true);
    m_colorBtn->setBackgroundRole(QPalette::Window);
    main_layout->addWidget(m_colorBtn);

    QListWidget *m_listWidget = new QListWidget(this);
    connect(m_listWidget, &QListWidget::currentTextChanged, this, &TestWidget::slot_test);
    QListWidgetItem *item = NULL;
    for (int i = 0; i < 40; i++)
    {
        item = new QListWidgetItem(m_listWidget);
        item->setText(QString::number(i));
    }
    main_layout->addWidget(m_listWidget);

    QComboBox *m_combobox = new QComboBox(this);
    m_combobox->setEditable(true);
    m_combobox->addItem("aaa");
    connect(m_combobox->lineEdit(), &QLineEdit::returnPressed, this, &TestWidget::slot_test);
    main_layout->addWidget(m_combobox);

    spacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    main_layout->addSpacerItem(spacer);
}

void TestWidget::slot_test()
{
    qDebug() << "slot_test";
}