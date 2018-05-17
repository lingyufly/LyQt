/********************************************************************************
** Form generated from reading UI file 'userinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInfo
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *infotable;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QPushButton *saveBtn;

    void setupUi(QWidget *UserInfo)
    {
        if (UserInfo->objectName().isEmpty())
            UserInfo->setObjectName(QStringLiteral("UserInfo"));
        UserInfo->resize(819, 541);
        verticalLayout = new QVBoxLayout(UserInfo);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        infotable = new QTableWidget(UserInfo);
        infotable->setObjectName(QStringLiteral("infotable"));

        verticalLayout->addWidget(infotable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        addBtn = new QPushButton(UserInfo);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        horizontalLayout->addWidget(addBtn);

        delBtn = new QPushButton(UserInfo);
        delBtn->setObjectName(QStringLiteral("delBtn"));

        horizontalLayout->addWidget(delBtn);

        saveBtn = new QPushButton(UserInfo);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));

        horizontalLayout->addWidget(saveBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UserInfo);

        QMetaObject::connectSlotsByName(UserInfo);
    } // setupUi

    void retranslateUi(QWidget *UserInfo)
    {
        UserInfo->setWindowTitle(QApplication::translate("UserInfo", "Form", Q_NULLPTR));
        addBtn->setText(QApplication::translate("UserInfo", "Add", Q_NULLPTR));
        delBtn->setText(QApplication::translate("UserInfo", "Del", Q_NULLPTR));
        saveBtn->setText(QApplication::translate("UserInfo", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserInfo: public Ui_UserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
