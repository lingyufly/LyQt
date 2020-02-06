#include "fileiowgt.h"

#include <QPushButton>
#include <QTextEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QFile>
#include <QTextStream>

FileIOWidget::FileIOWidget(QWidget *parent, Qt::WindowFlags fl)
    : QWidget(parent, fl)
{
    setupUi();
}

FileIOWidget::~FileIOWidget()
{

}

void FileIOWidget::setupUi()
{
    QGridLayout *m_mainLayout = new QGridLayout(this);
    QVBoxLayout *vbox = NULL;
    QHBoxLayout *hbox = NULL;

    m_textWrite = new QTextEdit(this);
    m_saveBtn = new QPushButton(this);
    m_saveBtn->setText("Save");
    connect(m_saveBtn, &QPushButton::clicked, this, &FileIOWidget::slot_saveText);
    hbox = new QHBoxLayout();
    hbox->addWidget(m_textWrite);
    hbox->addWidget(m_saveBtn);
    m_mainLayout->addLayout(hbox, 0, 0);
    
    m_textRead = new QTextEdit(this);
    m_textRead->setReadOnly(true);
    m_readBtn = new QPushButton(this);
    m_readBtn->setText("Read");
    connect(m_readBtn, &QPushButton::clicked, this, &FileIOWidget::slot_readText);
    hbox = new QHBoxLayout();
    hbox->addWidget(m_textRead);
    hbox->addWidget(m_readBtn);
    m_mainLayout->addLayout(hbox, 1, 0);
}

void FileIOWidget::slot_saveText()
{
    QFile f("text.txt");
    f.open(QIODevice::WriteOnly);
    QString txt = m_textWrite->toPlainText();
    QTextStream stream(&f);
    stream << txt;
    f.close();
}
void FileIOWidget::slot_readText()
{
    m_textRead->clear();
    QFile f("text.txt");
    f.open(QIODevice::ReadOnly);
    QTextStream stream(&f);
    QString txt;
    while (!stream.atEnd())
    {
        txt = f.readLine().trimmed();
        m_textRead->append(txt);
    }
    f.close();
}