#ifndef _WIZARD_H_
#define _WIZARD_H_

#include <QWizard>
#include <QWizardPage>

class MyWizard : public QWizard
{
public:
    MyWizard(QWidget *parent = NULL, Qt::WindowFlags flags = Qt::WindowFlags());
    ~MyWizard();

private:
    void setupUi();
    void init();
    QWizardPage *m_firstPage;
    QWizardPage *m_secondPage;
    QWizardPage *m_thirdPage;
};

#endif