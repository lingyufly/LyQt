#include "mainwindow.h"
#include <QHBoxLayout>
#include <QTabWidget>
#include <QWidget>
#include <QApplication>
#include <QAction>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QDebug>
#include <QDialog>
#include <QLabel>
#include <QFont>
#include <QFileDialog>
#include <QMimeData>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi();
}



MainWindow::~MainWindow()
{
}


bool MainWindow::login()
{
    m_loginDlg = new Login(NULL);
    if (m_loginDlg->exec() == QDialog::Accepted)
    {
        delete m_loginDlg;
        return true;
    }
    else
    {
        close();
        qApp->quit();
        return false;
    }
}

void MainWindow::setupUi()
{
    resize(800, 600);

    m_action1 = new QAction("Action1", this);
    m_action1->setObjectName("m_action1");
    connect(m_action1, &QAction::toggled, this, &MainWindow::slot_toggled);
    connect(m_action1, &QAction::triggered, this, &MainWindow::slot_triggered);

    m_action2 = new QAction("Action2", this);
    m_action2->setObjectName("m_action2");
    m_action2->setCheckable(true);
    connect(m_action2, &QAction::toggled, this, &MainWindow::slot_toggled);
    connect(m_action2, &QAction::triggered, this, &MainWindow::slot_triggered);

    m_modalAction1 = new QAction("Modal1 Action", this);
    m_modalAction1->setObjectName("m_modalAction1");
    connect(m_modalAction1, &QAction::triggered, this, &MainWindow::slot_testDialog);
    m_modalAction2 = new QAction("Modal2 Action", this);
    m_modalAction2->setObjectName("m_modalAction2");
    connect(m_modalAction2, &QAction::triggered, this, &MainWindow::slot_testDialog);
    m_modalessAction = new QAction("Modaless Action", this);
    m_modalessAction->setObjectName("m_modalessAction");
    connect(m_modalessAction, &QAction::triggered, this, &MainWindow::slot_testDialog);

    m_wizardAction = new QAction("Wizard Action", this);
    m_wizardAction->setObjectName("m_wizardAction");
    connect(m_wizardAction, &QAction::triggered, this, &MainWindow::slot_testWizard);

    m_filedialogAction = new QAction("FileDialog Action", this);
    m_filedialogAction->setObjectName("m_filedialogAction");
    connect(m_filedialogAction, &QAction::triggered, this, &MainWindow::slot_testFileDialog);

    m_menuBar = menuBar();
    m_fileMenu = new QMenu("File", this);
    m_fileMenu->addAction(m_action1);
    m_fileMenu->addAction(m_action2);
    m_menuBar->addMenu(m_fileMenu);

    m_toolbar = new QToolBar(this);
    addToolBar(m_toolbar);
    m_toolbar->addAction(m_action1);
    m_toolbar->addAction(m_action2);
    m_toolbar->addAction(m_fileMenu->menuAction());
    m_toolbar->addAction(m_modalAction1);
    m_toolbar->addAction(m_modalAction2);
    m_toolbar->addAction(m_modalessAction);
    m_toolbar->addAction(m_wizardAction);
    m_toolbar->addAction(m_filedialogAction);

    m_centerWidget = new QWidget(this);
    setCentralWidget(m_centerWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(m_centerWidget);
    m_tabWidget = new QTabWidget(m_centerWidget);
    mainLayout->addWidget(m_tabWidget);

    m_userinfoWidget = new UserInfo();
    m_tabWidget->addTab(m_userinfoWidget, QString("UserInfo"));

    m_mouseWidget = new Mouse();
    m_tabWidget->addTab(m_mouseWidget, QString("Mouse"));

    m_qtreewidgettWidget = new TestQTreeWidgetWidget();
    m_tabWidget->addTab(m_qtreewidgettWidget, QString("QTreeWidget"));

    m_testWidget = new TestWidget();
    m_tabWidget->addTab(m_testWidget, QString("TestWidget"));

    m_qstackedwidgetWidget = new TestQStackedWidget();
    m_tabWidget->addTab(m_qstackedwidgetWidget, QString("TestQStackedWidget"));

    m_fileioWidget = new FileIOWidget();
    m_tabWidget->addTab(m_fileioWidget, QString("TestFileIoWidget"));
}

void MainWindow::slot_toggled(bool state)
{
    qDebug() << "toggled   render:" << sender()->objectName() << "\t state:" << state;
}

void MainWindow::slot_triggered(bool state)
{
    qDebug() << "triggered render:" << sender()->objectName() << "\t state:" << state;
}


void MainWindow::slot_testDialog()
{
    QString objName = sender()->objectName();
    QDialog *dialog = new QDialog(this);
    QVBoxLayout *vbox = new QVBoxLayout(dialog);
    QLabel *label = new QLabel(dialog);
    vbox->addWidget(label);
    dialog->resize(300, 150);
    QFont font;
    font.setPointSize(14);
    dialog->setFont(font);
    dialog->setAttribute(Qt::WA_DeleteOnClose, true);

    if (objName.compare("m_modalAction1") == 0)
    {
        label->setText("This is a modal dailog,\n dialog->exec().");
        dialog->exec();
    }
    else if (objName.compare("m_modalAction2") == 0)
    {
        label->setText("This is a modal dailog,\n dialog->setModal(true)\n dialog->show().");
        dialog->setModal(true);
        dialog->show();
    }
    else if (objName.compare("m_modalessAction") == 0)
    {
        label->setText("This is a modal dailog,\n dialog->show().");
        dialog->show();
    }
}


void MainWindow::slot_testWizard()
{
    m_wizard = new MyWizard(this);
    m_wizard->show();
}


class MFileDialog : public QFileDialog
{
public:
    MFileDialog(QWidget *parent = Q_NULLPTR, const QString &caption = QString(), const QString &directory = QString(), const QString &filter = QString())
        :QFileDialog(parent, caption, directory, filter)
    {

        //init();
    }
    MFileDialog(QWidget *parent, Qt::WindowFlags flags)
        : QFileDialog(parent, flags)
    {

        //init();
    }
    void init()
    {
        QPushButton *test = new QPushButton(this);
        test->setText("TTTTTTT");
        //QLayout *ll = QFileDialog::layout();
        //layout()->addWidget(test);
        QObjectList widgets =  children();
        for (int i = 0; i < widgets.length(); i++)
        {
            QObject *btn = widgets.at(i);
            qDebug() << btn->objectName();
        }
    }
protected:
private:
};



void MainWindow::slot_testFileDialog()
{
    QString start = getenv("RUNHOME");
    MFileDialog *m_fileDialog = new MFileDialog(this, "AAAAAAAAAAA", start);
    m_fileDialog->setFileMode(QFileDialog::Directory);
    
    m_fileDialog->selectFile(start);
    if (m_fileDialog->exec() == QDialog::Accepted)
    {
        QStringList files = m_fileDialog->selectedFiles();
        for (QStringList::iterator it = files.begin(); it != files.end(); it++)
            qDebug() << *it;
    }
    m_fileDialog->init();
}