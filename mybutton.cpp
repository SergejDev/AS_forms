#include "mybutton.h"
#include <QPainter>


MyButton::MyButton(QWidget* parent=0):QPushButton(parent)
{
}


void MyButton::paintEvent(QPaintEvent *e)
{
    QPainter* painter=new QPainter(this);

    painter->drawLine(0,0,30,30);
    //painter->

}
