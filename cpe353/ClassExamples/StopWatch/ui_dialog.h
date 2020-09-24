/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *hourLabel;
    QLabel *label_2;
    QLabel *minuteLabel;
    QLabel *label_3;
    QLabel *secondLabel;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *start;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pause;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *clear;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *quit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(549, 242);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hourLabel = new QLabel(Dialog);
        hourLabel->setObjectName(QString::fromUtf8("hourLabel"));
        QFont font;
        font.setPointSize(25);
        hourLabel->setFont(font);
        hourLabel->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(hourLabel);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        minuteLabel = new QLabel(Dialog);
        minuteLabel->setObjectName(QString::fromUtf8("minuteLabel"));
        minuteLabel->setFont(font);
        minuteLabel->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(minuteLabel);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        secondLabel = new QLabel(Dialog);
        secondLabel->setObjectName(QString::fromUtf8("secondLabel"));
        secondLabel->setFont(font);
        secondLabel->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(secondLabel);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        start = new QPushButton(Dialog);
        start->setObjectName(QString::fromUtf8("start"));

        horizontalLayout_2->addWidget(start);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pause = new QPushButton(Dialog);
        pause->setObjectName(QString::fromUtf8("pause"));

        horizontalLayout_2->addWidget(pause);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        clear = new QPushButton(Dialog);
        clear->setObjectName(QString::fromUtf8("clear"));

        horizontalLayout_2->addWidget(clear);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        quit = new QPushButton(Dialog);
        quit->setObjectName(QString::fromUtf8("quit"));

        horizontalLayout_2->addWidget(quit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        hourLabel->setText(QApplication::translate("Dialog", "0", nullptr));
        label_2->setText(QApplication::translate("Dialog", ":", nullptr));
        minuteLabel->setText(QApplication::translate("Dialog", "0", nullptr));
        label_3->setText(QApplication::translate("Dialog", ":", nullptr));
        secondLabel->setText(QApplication::translate("Dialog", "0", nullptr));
        start->setText(QApplication::translate("Dialog", "Start", nullptr));
        pause->setText(QApplication::translate("Dialog", "Pause", nullptr));
        clear->setText(QApplication::translate("Dialog", "Clear", nullptr));
        quit->setText(QApplication::translate("Dialog", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
