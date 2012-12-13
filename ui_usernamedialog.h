/********************************************************************************
** Form generated from reading UI file 'usernamedialog.ui'
**
** Created: Thu 13. Dec 02:22:34 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERNAMEDIALOG_H
#define UI_USERNAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UserNameDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *UserNameDialog)
    {
        if (UserNameDialog->objectName().isEmpty())
            UserNameDialog->setObjectName(QString::fromUtf8("UserNameDialog"));
        UserNameDialog->resize(400, 148);
        UserNameDialog->setStyleSheet(QString::fromUtf8("Style.txt"));
        verticalLayout = new QVBoxLayout(UserNameDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(UserNameDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("Style.txt"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(UserNameDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(21, 32));
        lineEdit->setStyleSheet(QString::fromUtf8("Style.txt"));

        verticalLayout->addWidget(lineEdit);

        verticalSpacer = new QSpacerItem(20, 39, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okPushButton = new QPushButton(UserNameDialog);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));
        okPushButton->setStyleSheet(QString::fromUtf8("Style.txt"));

        horizontalLayout->addWidget(okPushButton);

        cancelPushButton = new QPushButton(UserNameDialog);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));
        cancelPushButton->setStyleSheet(QString::fromUtf8("Style.txt"));

        horizontalLayout->addWidget(cancelPushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UserNameDialog);
        QObject::connect(okPushButton, SIGNAL(clicked()), UserNameDialog, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), UserNameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(UserNameDialog);
    } // setupUi

    void retranslateUi(QDialog *UserNameDialog)
    {
        UserNameDialog->setWindowTitle(QApplication::translate("UserNameDialog", "Enter your name", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UserNameDialog", "Enter your name", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("UserNameDialog", "    Ok    ", 0, QApplication::UnicodeUTF8));
        cancelPushButton->setText(QApplication::translate("UserNameDialog", "   Cancel   ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserNameDialog: public Ui_UserNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERNAMEDIALOG_H
