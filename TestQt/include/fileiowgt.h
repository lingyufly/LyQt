#ifndef _FILEIO_H_
#define _FILEIO_H_

#include <QWidget>
class QTextEdit;
class QPushButton;

class FileIOWidget :public QWidget
{
    Q_OBJECT
public:
    FileIOWidget(QWidget*parent = NULL, Qt::WindowFlags fl = Qt::WindowFlags());
    ~FileIOWidget();

protected:
    
protected slots :
    void slot_saveText();
    void slot_readText();

private:
    void setupUi();
    QTextEdit *m_textWrite;
    QTextEdit *m_textRead;
    QPushButton *m_saveBtn;
    QPushButton *m_readBtn;
};

#endif