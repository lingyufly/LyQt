#ifndef _LYRADAR_H_
#define _LYRADAR_H_


#include <QtWidgets/QWidget>

class LyRadar : public QWidget
{
    Q_OBJECT

public:
    LyRadar(QWidget *parent = Q_NULLPTR, Qt::WindowFlags fl=Qt::WindowFlags());
    ~LyRadar();

    void paintEvent(QPaintEvent * event);

private:

};





#endif // !_LYRADAR_H_



