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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *BinaryButton;
    QPushButton *OcatlButton;
    QPushButton *HexButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *answerLabel;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *quitButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        BinaryButton = new QPushButton(Dialog);
        BinaryButton->setObjectName(QString::fromUtf8("BinaryButton"));

        horizontalLayout_2->addWidget(BinaryButton);

        OcatlButton = new QPushButton(Dialog);
        OcatlButton->setObjectName(QString::fromUtf8("OcatlButton"));

        horizontalLayout_2->addWidget(OcatlButton);

        HexButton = new QPushButton(Dialog);
        HexButton->setObjectName(QString::fromUtf8("HexButton"));

        horizontalLayout_2->addWidget(HexButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        answerLabel = new QLabel(Dialog);
        answerLabel->setObjectName(QString::fromUtf8("answerLabel"));
        answerLabel->setFrameShape(QFrame::Box);

        horizontalLayout_3->addWidget(answerLabel);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        clearButton = new QPushButton(Dialog);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout_4->addWidget(clearButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        quitButton = new QPushButton(Dialog);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout_4->addWidget(quitButton);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("Dialog", "Enter Base 10 Integer Here", nullptr));
        BinaryButton->setText(QApplication::translate("Dialog", "Binary", nullptr));
        OcatlButton->setText(QApplication::translate("Dialog", "Octal", nullptr));
        HexButton->setText(QApplication::translate("Dialog", "Hex", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Conerted Integer:", nullptr));
        answerLabel->setText(QString());
        clearButton->setText(QApplication::translate("Dialog", "Clear", nullptr));
        quitButton->setText(QApplication::translate("Dialog", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
