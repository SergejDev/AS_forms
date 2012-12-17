#include "ship.h"
#include <QPainter>

Ship::Ship(QString word)
{
    shipsPadding=50;
    speed=1;

    this->word=word;
    ShipImage1 = new QImage(":/debug/Images/dk2_darker.png");
    shipSize.setWidth(ShipImage1->width());
    shipSize.setHeight(ShipImage1->height());
}

int Ship::GetSpeed()
{
    return speed;
}

void Ship::DrawShip(QPainter* painter)
{
    QPoint shipPosition(position.x()-shipSize.width()/2,position.y()-shipSize.height()/2);
    painter->drawImage(shipPosition,*ShipImage1);

    QPoint textPosition(position.x()-shipSize.width()/2,position.y()-shipSize.height()/2-10);
    int textWhidth=shipSize.width();
    int textHeight=30;
    painter->setPen(QColor(255,255,255));
    painter->setFont(QFont("Calibri",13));
    painter->drawText(textPosition.x(),textPosition.y(),textWhidth,textHeight,Qt::AlignCenter,word);
}

void Ship::SetPosition(QPoint newPosition)
{
    position=newPosition;

}

QPoint Ship::GetPosition()
{
    return position;
}

QString Ship::GetWord()
{
    return word;
}

bool Ship::IsShipOwerlap(QPoint newShipPosition)
{
//    int newShipX=newShipPosition.x()-shipSize.width()/2;
//    int newShipY=newShipPosition.y()-shipSize.width()/2;
    int newShipX=newShipPosition.x();
    int newShipY=newShipPosition.y();
    if((abs(newShipX-position.x())<shipSize.width()/2+shipsPadding) &&
            (abs(newShipY-position.y())<shipSize.height()/2+shipsPadding))
    {
        return true;
    }
    else
    {
        return false;
    }
}

