#ifndef SHIPS_H
#define SHIPS_H
#include "ship.h"

class Ships
{
private:
    int gameAreaPadding;
    QList<Ship*> AllShips;
    QPainter* Painter;
    int windowWidth;

    int RandInt(int low, int high);
    bool IsShipsOwerlap(QPoint newShipPosition);

public:
    Ships(int windowWidth);
    void DrawShips(QPainter* painter);
    void AddShip(Ship* newShip);

};

#endif // SHIPS_H
