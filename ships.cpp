#include "ships.h"

Ships::Ships(int windowWidth)
{
    this->windowWidth=windowWidth;
    gameAreaPadding=100;
}

void Ships::DrawShips(QPainter* painter)
{
    for(int i = 0; i < AllShips.size(); i++)
    {
        AllShips[i]->DrawShip(painter);
    }
}

void Ships::AddShip(Ship* newShip)
{
    QPoint newPosition;
    do
    {
        int newX=RandInt(gameAreaPadding,windowWidth-gameAreaPadding);
        int newY=RandInt(0,500);
        newPosition.setX(newX);
        newPosition.setY(newY);
    }
    while(IsShipsOwerlap(newPosition));

    newShip->SetPosition(newPosition);
    AllShips.append(newShip);
}

int Ships::RandInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

bool Ships::IsShipsOwerlap(QPoint newShipPosition)
{
    for(int i = 0; i < AllShips.size(); i++)
    {
        if(AllShips[i]->IsShipOwerlap(newShipPosition))
        {
            return true;
        }
    }
    return false;
}
