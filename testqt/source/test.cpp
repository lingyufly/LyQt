#include "test.h"

#include <QDateTimeEdit>
#include <QBoxLayout>

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
    m_datetime = new QDateTimeEdit(this);
    main_layout->addWidget(m_datetime);
}