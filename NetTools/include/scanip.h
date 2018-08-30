#ifndef _SCANIP_H_
#define _SCANIP_H_

#include <QWidget>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QTreeWidget>
#include <QList>
#include <QNetworkInterface>
#include <QRegExp>
#include <QThread>
#include <QProcess>
#include <QDebug>
#include <QProgressBar>
#include <QMetaType>

typedef struct
{
    QString ip;
    QString mac;
    QString hostname;
}ipinfo_t;

class GetOnlineIP :public QThread
{
    Q_OBJECT
public:
    GetOnlineIP(QString ip = QString::null, QString mask = QString::null)
    {
        qRegisterMetaType<ipinfo_t>("ipinfo_t");
        m_ipStr = ip;
        m_maskStr = mask;
        ifRun = true;
    }
    ~GetOnlineIP()
    {
    }

    void setIpInfo(QString ip, QString mask)
    {
        m_ipStr = ip;
        m_maskStr = mask;
    }

    bool checkAddress()
    {
        QRegExp rx2("([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])(\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])){3}");
        if (rx2.exactMatch(m_ipStr) && rx2.exactMatch(m_maskStr))
            return true;
        else
            return false;
    }

    int getAllIP()
    {
        m_allIPList.clear();
        if (!checkAddress())
            return -1;

        sscanf(m_ipStr.toStdString().c_str(), "%d.%d.%d.%d", m_ip, m_ip + 1, m_ip + 2, m_ip + 3);
        sscanf(m_maskStr.toStdString().c_str(), "%d.%d.%d.%d", m_mask, m_mask + 1, m_mask + 2, m_mask + 3);
        int flag0 = 0, flag1 = 0, flag2 = 0, flag3 = 0;
        int base0 = 0, base1 = 0, base2 = 0, base3 = 0;

        base0 = m_ip[0] & m_mask[0];
        base1 = m_ip[1] & m_mask[1];
        base2 = m_ip[2] & m_mask[2];
        base3 = m_ip[3] & m_mask[3];

        flag0 = m_mask[0] ^ 0XFF;
        flag1 = m_mask[1] ^ 0XFF;
        flag2 = m_mask[2] ^ 0XFF;
        flag3 = m_mask[3] ^ 0XFF;

        int i0, i1, i2, i3;
        int ip0 = 0, ip1 = 0, ip2 = 0, ip3 = 0;
        for (i0 = 0; i0 <= flag0; i0++)
        {
            for (i1 = 0; i1 <= flag1; i1++)
            {
                for (i2 = 0; i2 <= flag2; i2++)
                {
                    for (i3 = 0; i3 <= flag3; i3++)
                    {
                        ip0 = base0 + i0;
                        ip1 = base1 + i1;
                        ip2 = base2 + i2;
                        ip3 = base3 + i3;
                        if (ip3 == 0X00 || ip3 == 0XFF)
                            continue;
                        QString ipinfo = QString("%1.%2.%3.%4").arg(ip0).arg(ip1).arg(ip2).arg(ip3);
                        m_allIPList.append(ipinfo);
                    }
                }
            }
        }
        return m_allIPList.size();
    }

    void run()
    {
        if (getAllIP() <= 0)
            return;
        for (int i = 0; i < m_allIPList.size() && ifRun; i++)
        {
            ipinfo_t ipinfo;
            ipinfo.ip = QString::null;
            if (pingIP(m_allIPList.at(i)))
            {
                ipinfo.ip = m_allIPList.at(i);
            }
            emit getNewIP(i, ipinfo);
        }
        ifRun = true;
    }

    void stop()
    {
        ifRun = false;
        quit();
        wait();
    }

signals:
    void getNewIP(int num, ipinfo_t ipinfo);

protected:

private:
    bool ifRun;
    QString m_ipStr;
    QString m_maskStr;
    int m_ip[4];
    int m_mask[4];
    QStringList m_allIPList;
    QList<ipinfo_t> m_onlineIPList;

    bool pingIP(QString ip)
    {
        QProcess *cmd = new QProcess();
#ifdef _linux_
        QString strArg = "ping -s 1 -c 1 " + ip;        //linux平台下的格式
#else
        QString strArg = "ping " + ip + " -n 1 -w " + QString::number(1);  //windows下的格式
#endif
        cmd->start(strArg);
        cmd->waitForReadyRead();
        cmd->waitForFinished();
        QString retStr = cmd->readAll();
        if (retStr.indexOf("TTL") != -1 || retStr.indexOf("ttl") != -1)
            return true;
        else
            return false;
    }
};

class ScanIPWidget :public QWidget
{
    Q_OBJECT
public:
    ScanIPWidget(QWidget *parent = NULL, Qt::WindowFlags fl = Qt::WindowFlags());
    ~ScanIPWidget();

    void setTotalIPCount(int count)
    {
        m_scanProgressBar->setMinimum(0);
        m_scanProgressBar->setMaximum(count);
        m_scanProgressBar->setValue(0);
    }

protected:

    //protected slots :
    void getInterfaceList();
    void changeAdapter();
    void scanIP();
    void addIP(int num, ipinfo_t ipinfo);

private:
    QGridLayout *m_mainLayout;
    QComboBox *m_InterfaceCombobox;
    QPushButton *m_scanBtn;
    QTreeWidget *m_addressTreeWidget;
    QTreeWidget *m_scanResultTreeWidget;
    QProgressBar *m_scanProgressBar;
    QPushButton *m_stopScanBtn;
    QPushButton *m_startScanBtn;
    void setupUi();

    QList<QNetworkInterface> m_interfaceList;

    GetOnlineIP *m_scanIP;
};

#endif