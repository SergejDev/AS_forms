#ifndef SHIP_H
#define SHIP_H
#include <QPoint>
#include <QPainter>

class Ship
{
private:
    int shipsPadding;
    QPoint Position;
    QSize shipSize;
    QImage *ShipImage1;

public:
    Ship();
    void DrawShip(QPainter* Painter);
    bool SetPosition(QPoint newPosition);
    bool IsShipOwerlap(QPoint newShipPosition);
};

#endif // SHIP_H
