#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <QObject>
#include "ships.h"
#include "bullets.h"

class GameController: public QObject
{
    Q_OBJECT
private:
    int animationTimerFrequency;
    Ships *allShips;
    Bullets *allBullets;
    QTimer *animationsTimer;
    QString previousWord;

    QString GetWordForShip();
    bool IsSuccessfulShoot(QString word);

    int RandInt(int low, int high);//!!!!!!

public:
    GameController(int windowWidth, QObject *parrent=0);
    void AddShip();
    void Draw(QPainter *painter);
    void Shoot(QString word);
signals:
    void GameAreaUpdate();
private slots:
    void AnimationsTimerSlot();
};

#endif // GAMECONTROLLER_H
