/********************************************************************************
** Form generated from reading UI file 'LyRadar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYRADAR_H
#define UI_LYRADAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LyRadarClass
{
public:

    void setupUi(QWidget *LyRadarClass)
    {
        if (LyRadarClass->objectName().isEmpty())
            LyRadarClass->setObjectName(QStringLiteral("LyRadarClass"));
        LyRadarClass->resize(600, 400);

        retranslateUi(LyRadarClass);

        QMetaObject::connectSlotsByName(LyRadarClass);
    } // setupUi

    void retranslateUi(QWidget *LyRadarClass)
    {
        LyRadarClass->setWindowTitle(QApplication::translate("LyRadarClass", "LyRadar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LyRadarClass: public Ui_LyRadarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYRADAR_H
