#include "scanip.h"
#include <QNetworkInterface>
#include <QList>
#include <QLayout>
#include <QGridLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QSizePolicy>

ScanIPWidget::ScanIPWidget(QWidget *parent, Qt::WindowFlags fl)
    : QWidget(parent, fl)
{
    setupUi();
    m_scanInterfaceBtn->click();
}

ScanIPWidget::~ScanIPWidget()
{

}

void ScanIPWidget::setupUi()
{
    m_scanIP = new GetOnlineIP(this);
    connect(m_scanIP, &GetOnlineIP::getNewIP, this, &ScanIPWidget::addIPToTreeWidget);
    connect(m_scanIP, &GetOnlineIP::getAllTPCount, this, &ScanIPWidget::scanAllIPCount);
    connect(m_scanIP, &GetOnlineIP::finishedScan, this, &ScanIPWidget::scanFinished);

    QHBoxLayout *hbox = NULL;
    QVBoxLayout *vbox = NULL;
    m_mainLayout = new QGridLayout(this);
    m_InterfaceCombobox = new QComboBox(this);
    m_InterfaceCombobox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    connect(m_InterfaceCombobox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &ScanIPWidget::changeAdapter);
    m_scanInterfaceBtn = new QPushButton("Scan", this);
    connect(m_scanInterfaceBtn, &QPushButton::clicked, this, &ScanIPWidget::getInterfaceList);
    hbox = new QHBoxLayout(NULL);
    hbox->addWidget(m_InterfaceCombobox);
    hbox->addWidget(m_scanInterfaceBtn);
    m_mainLayout->addLayout(hbox, 0, 0);

    m_addressTreeWidget = new QTreeWidget(this);
    m_addressTreeWidget->setHeaderLabels(QStringList() << "IP Address" << "IP Mask");
    m_addressTreeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
    m_addressTreeWidget->setIndentation(0);
    m_mainLayout->addWidget(m_addressTreeWidget);

    m_scanResultTreeWidget = new QTreeWidget(this);
    m_scanResultTreeWidget->setHeaderLabels(QStringList() << "IP Address" << "Mac Address" << "Host Name");
    m_scanResultTreeWidget->header()->setSectionResizeMode(QHeaderView::Stretch);
    m_scanResultTreeWidget->setIndentation(0);
    m_mainLayout->addWidget(m_scanResultTreeWidget);

    m_scanProgressBar = new QProgressBar(this);
    m_startScanBtn = new QPushButton("Start", this);
    connect(m_startScanBtn, &QPushButton::clicked, this, &ScanIPWidget::scanCtrl);
    m_stopScanBtn = new QPushButton("Stop", this);
    m_stopScanBtn->setEnabled(false);
    connect(m_stopScanBtn, &QPushButton::clicked, m_scanIP, &GetOnlineIP::stop);
    hbox = new QHBoxLayout(NULL);
    hbox->addWidget(m_scanProgressBar);
    hbox->addWidget(m_startScanBtn);
    hbox->addWidget(m_stopScanBtn);
    m_mainLayout->addLayout(hbox, 3, 0);
    resize(400, 600);
}

void ScanIPWidget::getInterfaceList()
{
    QList<QNetworkInterface> items = QNetworkInterface::allInterfaces();
    m_interfaceList.clear();
    for (QNetworkInterface item : items)
    {
        if (item.flags().testFlag(QNetworkInterface::IsUp)
            && item.flags().testFlag(QNetworkInterface::IsRunning)
            && item.flags().testFlag(QNetworkInterface::CanBroadcast)
            && item.flags().testFlag(QNetworkInterface::CanMulticast)
            && !item.flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            m_interfaceList.append(item);
        }
    }

    m_InterfaceCombobox->clear();
    for (QNetworkInterface item : m_interfaceList)
    {
        m_InterfaceCombobox->addItem(item.name());
    }
}

void ScanIPWidget::changeAdapter()
{
    int index = m_InterfaceCombobox->currentIndex();
    m_addressTreeWidget->clear();
    if (index<0 || index>m_interfaceList.length())
        return;

    QTreeWidgetItem *item = NULL;
    QNetworkInterface interface = m_interfaceList.at(index);
    qDebug() << "------------------------------------------------------------";
    qDebug() << "Adapter Name:" << interface.name();
    qDebug() << "Adapter Address:" << interface.hardwareAddress();

    QList<QNetworkAddressEntry> addressEntryList = interface.addressEntries();
    for (QNetworkAddressEntry addressEntryItem : addressEntryList)
    {
        if (addressEntryItem.ip().protocol() == QAbstractSocket::IPv4Protocol)
        {
            qDebug() << "IP Address:" << addressEntryItem.ip().toString() << "    IP Mask:" << addressEntryItem.netmask().toString();
            item = new QTreeWidgetItem(m_addressTreeWidget);
            item->setText(0, addressEntryItem.ip().toString());
            item->setText(1, addressEntryItem.netmask().toString());
        }
    }
}

void ScanIPWidget::scanCtrl()
{
    if (m_startScanBtn->text().compare("Start") == 0)
    {
        QTreeWidgetItem *item = m_addressTreeWidget->currentItem();
        if (item == NULL)
            return;

        m_scanResultTreeWidget->clear();
        m_scanProgressBar->setValue(0);
        
        m_scanIP->setIpInfo(item->text(0), item->text(1));
        m_scanIP->start();
        m_startScanBtn->setText("Pause");

        m_InterfaceCombobox->setEnabled(false);
        m_scanInterfaceBtn->setEnabled(false);
        m_addressTreeWidget->setEnabled(false);
        //m_scanResultTreeWidget->setEnabled(false);
        m_stopScanBtn->setEnabled(true);
    }
    else if (m_startScanBtn->text().compare("Pause") == 0)
    {
        m_scanIP->pause();
        m_startScanBtn->setText("Go On");
    }
    else if (m_startScanBtn->text().compare("Go On") == 0)
    {
        m_scanIP->goon();
        m_startScanBtn->setText("Pause");
    }
}

void ScanIPWidget::scanAllIPCount(int count)
{
    if (count < 0)
        return;
    else if (count == 0)
        m_scanProgressBar->setMaximum(0);
    else
        m_scanProgressBar->setMaximum(count - 1);
}
void ScanIPWidget::scanFinished()
{
    m_startScanBtn->setText("Start");
    m_InterfaceCombobox->setEnabled(true);
    m_scanInterfaceBtn->setEnabled(true);
    m_addressTreeWidget->setEnabled(true);
    //m_scanResultTreeWidget->setEnabled(true);
    m_stopScanBtn->setEnabled(false);
}

void ScanIPWidget::addIPToTreeWidget(int num, ipinfo_t ipinfo)
{
    m_scanProgressBar->setValue(num);
    if (ipinfo.ip == QString::null)
        return;
    QTreeWidgetItem *item = new QTreeWidgetItem(m_scanResultTreeWidget);
    item->setText(0, ipinfo.ip);
}