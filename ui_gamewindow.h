/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created: Fri 19. Oct 00:28:19 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(400, 300);
        centralWidget = new QWidget(GameWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 186, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 75 10pt \"Arial\";\n"
"	color: rgb(225, 225, 225);\n"
"	 background-color: qlineargradient(spread:pad, x1:0.517045, y1:1, x2:0.505, y2:0, stop:0.261364 rgba(0, 120, 14, 255), stop:1 rgba(75, 203, 0, 255));\n"
"	 border-color: rgb(255, 255, 255);\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 20px;\n"
"     border-color: rgb(155, 155, 155);\n"
"     font: bold 14px;\n"
"     min-width: 10em;\n"
"     padding: 6px;\n"
" }\n"
"\n"
" QPushButton:hover {\n"
"	color: rgb(255, 255, 255);\n"
"	border-color: grey;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.517045, y1:1, x2:0.505, y2:0, stop:0.261364 rgba(0, 93, 11, 255), stop:1 rgba(64, 174, 0, 255));\n"
"     border-style: inset;\n"
" }"));
        GameWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GameWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        GameWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GameWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GameWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GameWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GameWindow->setStatusBar(statusBar);

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "GameWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("GameWindow", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
