#include "gamecontroller.h"
#include <QStringList>
#include <QDebug>

GameController::GameController(int windowWidth, QObject *parrent):QObject(parrent)
{
    allShips=new Ships(windowWidth,parrent);
    allBullets=new Bullets(windowWidth,parrent);
    animationTimerFrequency=25;
    animationsTimer=new QTimer();
    QObject::connect(animationsTimer,SIGNAL(timeout()),this,SLOT(AnimationsTimerSlot()));
    animationsTimer->start(animationTimerFrequency);
}

void GameController::AddShip()
{
    allShips->AddShip(new Ship(GetWordForShip()));
}

void GameController::Draw(QPainter *painter)
{
    allShips->DrawShips(painter);
    allBullets->DrawBullets(painter);
}

void GameController::Shoot(QString word)
{
    if(IsSuccessfulShoot(word))
    {
        int aimIndex=allShips->ShipIndexFromWord(word);
        QPoint aimPosition=allShips->ShipPositionFromWord(word);
        allBullets->AddBullet(new Bullet(aimPosition,aimIndex));
    }
}

void GameController::AnimationsTimerSlot()
{
    emit GameAreaUpdate();
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
