#include "test.h"

#include <QDateTimeEdit>
#include <QBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QButtonGroup>
#include <QRadioButton>
#include <QColor>
#include <QPalette>

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
    m_colorBtn->setPalette(pal);
    m_colorBtn->setAutoFillBackground(true);
    m_colorBtn->setFlat(true);
    m_colorBtn->setBackgroundRole(QPalette::Window);
    main_layout->addWidget(m_colorBtn);

    spacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    main_layout->addSpacerItem(spacer);
}