/********************************************************************************
** Form generated from reading UI file 'mouse.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUSE_H
#define UI_MOUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mouse
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *mouseposLabel;
    QSpacerItem *horizontalSpacer;
    QCheckBox *mouseTrackCbox;
    QSpacerItem *verticalSpacer;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Mouse)
    {
        if (Mouse->objectName().isEmpty())
            Mouse->setObjectName(QStringLiteral("Mouse"));
        Mouse->resize(724, 501);
        verticalLayout = new QVBoxLayout(Mouse);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Mouse);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label);

        mouseposLabel = new QLabel(Mouse);
        mouseposLabel->setObjectName(QStringLiteral("mouseposLabel"));
        mouseposLabel->setMinimumSize(QSize(0, 0));
        mouseposLabel->setBaseSize(QSize(0, 0));
        mouseposLabel->setStyleSheet(QStringLiteral(""));
        mouseposLabel->setMidLineWidth(0);

        horizontalLayout->addWidget(mouseposLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        mouseTrackCbox = new QCheckBox(Mouse);
        mouseTrackCbox->setObjectName(QStringLiteral("mouseTrackCbox"));

        verticalLayout->addWidget(mouseTrackCbox);

        verticalSpacer = new QSpacerItem(20, 226, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        textBrowser = new QTextBrowser(Mouse);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(Mouse);

        QMetaObject::connectSlotsByName(Mouse);
    } // setupUi

    void retranslateUi(QWidget *Mouse)
    {
        Mouse->setWindowTitle(QApplication::translate("Mouse", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Mouse", "\351\274\240\346\240\207\344\275\215\347\275\256:", Q_NULLPTR));
        mouseposLabel->setText(QString());
        mouseTrackCbox->setText(QApplication::translate("Mouse", "setMouseTracking", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Mouse: public Ui_Mouse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUSE_H
