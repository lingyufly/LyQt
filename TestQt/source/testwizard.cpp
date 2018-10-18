#include "testwizard.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>


TestWizard::TestWizard(QWidget *parent, Qt::WindowFlags fl)
    :QWizard(parent, fl)
{
    m_firstPage = NULL;
    m_secondPage = NULL;
    m_thirdPage = NULL;
    setupUi();
}


TestWizard::~TestWizard()
{

}


void TestWizard::setupUi()
{
    QHBoxLayout *hbox = NULL;
    QVBoxLayout *vbox = NULL;
    setWindowTitle("Test QWizard");
    setWizardStyle(QWizard::ClassicStyle);

    m_firstPage = new QWizardPage(this);
    vbox = new QVBoxLayout(m_firstPage);
    QLabel *label = new QLabel(m_firstPage);
    label->setText("This is the first page");
    vbox->addWidget(label);
    addPage(m_firstPage);
   
    m_secondPage = new QWizardPage(this);
    vbox = new QVBoxLayout(m_secondPage);
    label = new QLabel(m_secondPage);
    label->setText("This is the second page");
    vbox->addWidget(label);
    addPage(m_secondPage);

    m_thirdPage = new QWizardPage(this);
    vbox = new QVBoxLayout(m_thirdPage);
    label = new QLabel(m_thirdPage);
    label->setText("This is the third page");
    vbox->addWidget(label);
    addPage(m_thirdPage);
}

void TestWizard::init()
{

}