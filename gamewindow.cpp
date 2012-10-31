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
#include <QMessageBox>


GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent)
{
    MakeInterface();
}

void GameWindow::MakeInterface()
{
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

        if (this->objectName().isEmpty())
        {
            this->setObjectName(QString::fromUtf8("GameWindow"));
        }
        this->resize(1000, 700);
        QFont font;
        font.setKerning(true);
        this->setFont(font);


        QString str;
        QString fileName="e:\\Programming\\Qt prog's\\AS_forms\\styles.txt";
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
        label = new QLabel("Score:", centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(598, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton("MENU",centralWidget);
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

        verticalSpacer = new QSpacerItem(20, 560, QSizePolicy::Minimum, QSizePolicy::Expanding);

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
