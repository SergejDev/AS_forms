#ifndef SHIP_H
#define SHIP_H
#include <QPoint>
#include <QSize>
#include <QImage>

class Ship
{
private:
    int shipsPadding;
    int speed;

    QPoint position;
    QSize shipSize;
    QImage *ShipImage1;
    QString word;

public:
    Ship(QString word);
    int GetSpeed();
    void DrawShip(QPainter* Painter);
    void SetPosition(QPoint newPosition);
    QPoint GetPosition();
    QString GetWord();
    bool IsShipOwerlap(QPoint newShipPosition);

//signals:
//    void ShipOwercomeBorder();
};

#endif // SHIP_H
