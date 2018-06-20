#include "test.h"

#include <QDateTimeEdit>
#include <QBoxLayout>
#include <QGroupBox>
#include <QButtonGroup>
#include <QRadioButton>

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

    spacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    main_layout->addSpacerItem(spacer);
}