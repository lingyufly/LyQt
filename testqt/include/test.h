#ifndef _TEST_H_
#define _TEST_H_

#include <QWidget>

class QDateTimeEdit;
class TestWidget :public QWidget
{
    Q_OBJECT
public:
    TestWidget(QWidget *parent = NULL, Qt::WindowFlags fl = Qt::WindowFlags());
    ~TestWidget();

protected:
protected slots:

private:
    void setupUi();
    QDateTimeEdit *m_datetime;
};
#endif