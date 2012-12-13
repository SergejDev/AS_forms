#include "ship.h"

Ship::Ship()
{
    shipsPadding=50;
    ShipImage1 = new QImage(":/debug/Images/dk2.png");
    shipSize.setWidth(ShipImage1->width());
    shipSize.setHeight(ShipImage1->height());
}

void Ship::DrawShip(QPainter* painter)
{
    painter->drawImage(Position,*ShipImage1);
}

bool Ship::SetPosition(QPoint newPosition)
{
    Position.setX(newPosition.x()-shipSize.width()/2);
    Position.setY(newPosition.y()-shipSize.width()/2);
}

bool Ship::IsShipOwerlap(QPoint newShipPosition)
{
    int newShipX=newShipPosition.x()-shipSize.width()/2;
    int newShipY=newShipPosition.y()-shipSize.width()/2;
    if((abs(newShipX-Position.x())<shipSize.width()/2+shipsPadding)&&
        (abs(newShipY-Position.y())<shipSize.height()/2+shipsPadding))
    {
        return true;
    }
    else
    {
        return false;
    }
}

