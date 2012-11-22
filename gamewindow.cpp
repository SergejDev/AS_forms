#include "gamewindow.h"
#include <QString>
#include <QTextStream>
#include <QFile>
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
#include <QUrl>
#include <QMessageBox>
#include <QDebug>


GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent)
{
    MakeInterface();
    connect(this->menuPushButton,SIGNAL(clicked()),this, SLOT(EndGame()));

}

void GameWindow::EndGame()
{
    qDebug()<<"ssssss";
}

void GameWindow::MakeInterface()
{

        if (this->objectName().isEmpty())
        {
            this->setObjectName(QString::fromUtf8("GameWindow"));
        }
        this->resize(1000, 700);
        QFont font;
        font.setKerning(true);
        this->setFont(font);

        QString str;
        QString fileName=":/Style.txt";
        QFile inputFile(fileName);
        QTextStream ts(&inputFile);
        if(!inputFile.open(QFile::ReadOnly | QFile::Text))
        {
            return;
        }
        str=ts.readAll();
        inputFile.close();

        this->setStyleSheet(str);
        centralWidget = new QWidget(this);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        score = new QLabel("Score:", centralWidget);
        score->setObjectName(QString::fromUtf8("score"));
        score->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(score);

        horizontalSpacer = new QSpacerItem(598, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        menuPushButton = new QPushButton("Menu",centralWidget);
        menuPushButton->setObjectName(QString::fromUtf8("menuPushButton"));
        menuPushButton->setMinimumSize(QSize(68, 0));
        menuPushButton->setMaximumSize(QSize(16777215, 32));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        menuPushButton->setFont(font1);
        menuPushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(menuPushButton);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 560, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        inputField = new QLineEdit(centralWidget);
        inputField->setObjectName(QString::fromUtf8("inputField"));
        inputField->setMinimumSize(QSize(450, 34));

        horizontalLayout_2->addWidget(inputField);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        this->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(this);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        this->setMenuBar(menuBar);
        statusBar = new QStatusBar(this);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        this->setStatusBar(statusBar);
}

GameWindow::~GameWindow()
{

}
