/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created: Fri 19. Oct 14:10:43 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(1000, 700);
        QFont font;
        font.setKerning(true);
        GameWindow->setFont(font);
        GameWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: qradialgradient(spread:pad, cx:0.415, cy:0.624682, radius:0.875, fx:0.352, fy:0.7, stop:0 rgba(34, 36, 59, 255), stop:1 rgba(0, 0, 0, 255));\n"
"}\n"
"\n"
"\n"
"QPushButton {\n"
"	color: rgb(225, 225, 225);\n"
"	font: bold 14px \"Arial\";\n"
"	 background-color: qlineargradient(spread:pad, x1:0.517045, y1:1, x2:0.505, y2:0, stop:0.261364 rgba(0, 120, 14, 255), stop:1 rgba(75, 203, 0, 255));\n"
"	 border-color: rgb(255, 255, 255);\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: rgb(155, 155, 155);\n"
"     min-width: 3em;\n"
"     padding: 3px;\n"
" }\n"
" QPushButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	border-color: grey;\n"
" }\n"
" QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.517045, y1:1, x2:0.505, y2:0, stop:0.261364 rgba(0, 93, 11, 255), stop:1 rgba(64, 174, 0, 255));\n"
"     border-style: inset;\n"
" }\n"
"\n"
"\n"
"QLineEdit {\n"
"	 font: bold 16px \"Arial\";\n"
""
                        "	color: rgb(255, 255, 255);\n"
"	 background-color: qlineargradient(spread:pad, x1:0.517045, y1:1, x2:0.505, y2:0, stop:0.261364 rgba(0, 120, 14, 255), stop:1 rgba(75, 203, 0, 255));\n"
"	 border-color: rgb(255, 255, 255);\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 17px;\n"
"     border-color: rgb(155, 155, 155);\n"
"     padding: 6px;\n"
"}\n"
"\n"
"\n"
"QLabel {\n"
"	color: rgb(225, 225, 225);\n"
"     font: bold 16px \"Arial\";\n"
"     padding: 4px;\n"
"}"));
        centralWidget = new QWidget(GameWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(598, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(58, 0));
        pushButton->setMaximumSize(QSize(16777215, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 558, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(450, 34));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        GameWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GameWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        GameWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(GameWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GameWindow->setStatusBar(statusBar);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "GameWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GameWindow", "Score:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("GameWindow", "MENU", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
