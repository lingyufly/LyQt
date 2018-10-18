#ifndef _WIZARD_H_
#define _WIZARD_H_

#include <QWizard>
#include <QWizardPage>

class TestWizard : public QWizard
{
public:
    TestWizard(QWidget *parent = NULL, Qt::WindowFlags flags = Qt::WindowFlags());
    ~TestWizard();

private:
    void setupUi();
    void init();
    QWizardPage *m_firstPage;
    QWizardPage *m_secondPage;
    QWizardPage *m_thirdPage;
};

#endif