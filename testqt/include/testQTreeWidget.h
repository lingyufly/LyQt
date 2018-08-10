#ifndef _TESTQTTREEWIDGET_H_
#define _TESTQTTREEWIDGET_H_
#include <QWidget>
class QTreeWidget;
class QTreeWidgetItem;

class TestQTreeWidgetWidget : public QWidget
{
    Q_OBJECT

public:
    TestQTreeWidgetWidget(QWidget *parent = NULL, Qt::WindowFlags fl = Qt::WindowFlags());
    ~TestQTreeWidgetWidget();

protected:

protected slots :
    void slot_ContextMenu();
    void slot_CurrentChanged();
    void slot_SelectedChanged();


private:
    QTreeWidget *m_treeWidget;

};




#endif
