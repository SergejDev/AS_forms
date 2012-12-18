#include "gamecontroller.h"
#include <QStringList>
#include <QDebug>

GameController::GameController(int windowWidth,int level, QObject *parrent):QObject(parrent)
{
    currentScore=0;
    scorePointsForDestroyingShip=10;

    currentLevel=level;
    scoresPerLevel=30;

    allShips=new Ships(windowWidth,parrent);
    allBullets=new Bullets(windowWidth,parrent);
    gun=new Gun(windowWidth);

    animationTimerFrequency=25;
    animationsTimer=new QTimer();
    QObject::connect(animationsTimer,SIGNAL(timeout()),this,SLOT(AnimationsTimerSlot()));

    addShipTimerFrequencyOnLevels[0]=6000;
    addShipTimerFrequencyOnLevels[1]=5000;
    addShipTimerFrequencyOnLevels[2]=4000;
    addShipTimerFrequencyOnLevels[3]=3000;
    addShipTimerFrequencyOnLevels[4]=2000;
    addShipTimerFrequency=addShipTimerFrequencyOnLevels[currentLevel];
    addShipTimer=new QTimer();
    QObject::connect(addShipTimer,SIGNAL(timeout()),this,SLOT(AddShipTimerSlot()));

    QObject::connect(allBullets,SIGNAL(AimHit(int,int)),this,SLOT(ShipHitedSlot(int,int)));

    QObject::connect(allShips,SIGNAL(ShipDestroyed(int)),this,SLOT(ShipDestroyedSlot(int)));
    QObject::connect(allShips,SIGNAL(ShipDestroyed(int)),this,SIGNAL(ShipDestroyed(int)));

    QObject::connect(allShips,SIGNAL(ShipOwercomeBorder(int)),this,SIGNAL(ShipOwercomeBorder(int)));

    animationsTimer->start(animationTimerFrequency);
    addShipTimer->start(addShipTimerFrequency);
}

void GameController::AddShip()
{
    allShips->AddShip(new Ship(GetWordForShip(),currentLevel));
}

void GameController::Draw(QPainter *painter)
{
    allShips->DrawShips(painter);
    allBullets->DrawBullets(painter);
    gun->DrawGun(painter);
}

void GameController::Shoot(QString word)
{
    if(IsSuccessfulShoot(word))
    {
        int aimIndex=allShips->ShipIndexFromWord(word);
        QPoint aimPosition=allShips->ShipPositionFromWord(word);
        allBullets->AddBullet(new Bullet(aimPosition,aimIndex));
        gun->SetAim(aimPosition);
    }
}

void GameController::SetLevel(int level)
{
    currentLevel=level;
}

int GameController::GetScore()
{
    return currentScore;
}

void GameController::PauseGame()
{
    allShips->PauseShips();
    allBullets->PauseBullets();
    addShipTimer->stop();
}

void GameController::ResumeGame()
{
    allShips->ResumeShips();
    allBullets->ResumeBullets();
    addShipTimer->start();
}

void GameController::NextLevel()
{
    currentLevel+=1;
}

void GameController::AnimationsTimerSlot()
{
    emit GameAreaUpdate();
}

void GameController::AddShipTimerSlot()
{
    AddShip();
}

void GameController::ShipHitedSlot(int bulletIndex, int shipIndex)
{
    allShips->ShipHited(bulletIndex,shipIndex);
}

void GameController::ShipDestroyedSlot(int shipIndex)
{
    currentScore+=scorePointsForDestroyingShip;
    if(currentScore>=(currentLevel+1)*scoresPerLevel)
    {
        NextLevel();
        addShipTimerFrequency=addShipTimerFrequencyOnLevels[currentLevel];
        addShipTimer->setInterval(addShipTimerFrequency);
    }
}


int GameController::RandInt(int low, int high)//!!!!!!
{
    return qrand() % ((high + 1) - low) + low;
}

QString GameController::GetWordForShip()//TO DO: Get words from DB (don't forget about RandInt)
{
    QStringList words;
    words<<"bye"<<"hello"<<"word"<<"example"<<"peace";
    int index=RandInt(0,words.size()-1);
    return words[index];
}

bool GameController::IsSuccessfulShoot(QString word)
{
    QPoint aimPosition=allShips->ShipPositionFromWord(word);
    if((aimPosition!=QPoint(-1,-1))&&(aimPosition!=QPoint(-2,-2))&&(previousWord.size()<word.size()))
    {
        previousWord=word;
        return true;
    }
    else
    {
        previousWord=word;
        return false;
    }
}

GameController::~GameController()
{
    delete gun;
}
