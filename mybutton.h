#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT

public:
    MyButton(QWidget*);
    void paintEvent(QPaintEvent *);
};

#endif // MYBUTTON_H
