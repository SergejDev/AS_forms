#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
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
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QtSql>
#include <QSqlTableModel>
#include <QPainter>
#include "usernamedialog.h"
#include "ui_usernamedialog.h"
#include "tabledialog.h"
#include "ui_tabledialog.h"
#include "ships.h"


namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    

private:

    UserNameDialog* userNameDialog;
    TableDialog* tableDialog;
//    QSqlTableModel* model;


    QSqlDatabase db;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *score;
    QSpacerItem *horizontalSpacer;
    QPushButton *menuPushButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *inputField;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    /////////
    Ships *AllShips;

    void paintEvent(QPaintEvent *arg);

    void MakeInterface();
    void SQLConnectionOpen();
    void WriteResultToDB(QString name, QString scores);
    void ShowStatisticTable();
    void InitializeRandom();
private slots:
    void EndGame();
};

#endif // GAMEWINDOW_H
