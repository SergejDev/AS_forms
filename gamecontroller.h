#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <QObject>
#include "ships.h"
#include "bullets.h"
#include "gun.h"

class GameController: public QObject
{
    Q_OBJECT
private:
    int currentLevel;
    int scoresPerLevel;
    int animationTimerFrequency;
    int addShipTimerFrequencyOnLevels[5];
    int addShipTimerFrequency;
    Ships *allShips;
    Bullets *allBullets;
    Gun *gun;
    QTimer *animationsTimer;
    QTimer *addShipTimer;
    QString previousWord;

    int currentScore;
    int scorePointsForDestroyingShip;

    QString GetWordForShip();
    bool IsSuccessfulShoot(QString word);
    void NextLevel();

    int RandInt(int low, int high);//!!!!!!

public:
    GameController(int windowWidth,int level, QObject *parrent=0);
    ~GameController();
    void AddShip();
    void Draw(QPainter *painter);
    void Shoot(QString word);
    void SetLevel(int level);
    int GetScore();

signals:
    void GameAreaUpdate();
    void ShipOwercomeBorder(int shipIndex);
    void ShipDestroyed(int shipIndex);
private slots:
    void AnimationsTimerSlot();
    void AddShipTimerSlot();
    void ShipHitedSlot(int bulletIndex, int shipIndex);
    void ShipDestroyedSlot(int shipIndex);
};

#endif // GAMECONTROLLER_H
