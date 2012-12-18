#include "gamewindow.h"
#include "bullet.h"


GameWindow::GameWindow(int languageID, int topicID, QWidget *parent) :
    QMainWindow(parent)
{
    InitializeRandom();
    MakeInterface();
    gameController=new GameController(this->width(),0,languageID,topicID,this);

    connect(gameController,SIGNAL(GameAreaUpdate()),this, SLOT(update()));
    connect(this->menuPushButton,SIGNAL(clicked(bool)),this, SIGNAL(MenuButtonPressed(bool)));
    connect(this->menuPushButton,SIGNAL(clicked()),this, SLOT(PauseGame()));
    connect(this->inputField,SIGNAL(textChanged(QString)),this, SLOT(InputFieldTextChanged(QString)));
    connect(gameController,SIGNAL(ShipDestroyed(int)),this,SLOT(ShipDestroyedSlot(int)));
    connect(gameController,SIGNAL(ShipOwercomeBorder(int)),this,SLOT(EndGame()));
}

void GameWindow::PauseGame()
{
    gameController->PauseGame();
}

void GameWindow::ResumeGame()
{
    gameController->ResumeGame();
    inputField->setFocus();
}

void GameWindow::paintEvent(QPaintEvent */*arg*/)
{
    QPainter painter(this);
    gameController->Draw(&painter);
}

void GameWindow::EndGame()
{
//////////////////////////////////
    gameController->PauseGame();
    userNameDialog=new UserNameDialog(this);
    userNameDialog->setModal(true);
    if(userNameDialog->exec() == QDialog::Accepted)
    {
        if(userNameDialog->ui->lineEdit->text()!="")
        {
            //qDebug()<<gameController->GetScore()<<" - score";
            WriteResultToDB(userNameDialog->ui->lineEdit->text(), gameController->GetScore());
        }
    }
    ShowStatisticTable();
}

void GameWindow::InputFieldTextChanged(QString word)
{
    gameController->Shoot(word);
}

void GameWindow::ShipDestroyedSlot(int shipIndex)
{
    score->setText("Score: "+QString::number(gameController->GetScore()));
    inputField->setText("");
}

void GameWindow::ShowStatisticTable()
{
    if(!db.isOpen())
    {
        SQLConnectionOpen();
    }

    QSqlTableModel* model=new QSqlTableModel(this, db);
    model->setTable("Statistic");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    tableDialog->ui->tableView->setModel(model);
    tableDialog->ui->tableView->hideColumn(0);
    tableDialog->setModal(true);
    tableDialog->show();
}

void GameWindow::InitializeRandom()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

void GameWindow::WriteResultToDB(QString name, int scores)
{
    SQLConnectionOpen();
    QString query="INSERT INTO Statistic(Name, Scores) VALUES('"+name+"', "+QString::number(scores)+")";
    db.exec(query);
    qDebug()<<db.lastError().text();
}

void GameWindow::SQLConnectionOpen()
{
    db=QSqlDatabase::addDatabase("QSQLITE","Words.s3db");
    db.setHostName("Spirit-PC");
    db.setDatabaseName("Words.s3db");
    db.setUserName("root");
    db.setPassword("");
    bool ok=db.open();
    qDebug()<<ok;
}

void GameWindow::MakeInterface()
{
    if (this->objectName().isEmpty())
    {
        this->setObjectName(QString::fromUtf8("GameWindow"));
    }
    this->resize(1000, 700);
    this->setWindowTitle("Awesome ships");
    QFont font;
    font.setKerning(true);
    this->setFont(font);

    SetWindowStyle();

    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    verticalLayout = new QVBoxLayout(centralWidget);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    score = new QLabel("Score: 0", centralWidget);
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

    tableDialog=new TableDialog(this);

    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    inputField->setFocus();
}

void GameWindow::SetWindowStyle()
{
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
}

GameWindow::~GameWindow()
{

}
