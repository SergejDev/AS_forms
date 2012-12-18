#ifndef WINDOWSCONTROLLER_H
#define WINDOWSCONTROLLER_H
#include <QObject>
#include "gamewindow.h"
#include "menuwindow.h"

class WindowsController: public QObject
{
    Q_OBJECT
private:
    MenuWindow *menuWindow;
    GameWindow *gameWindow;

public:
    WindowsController(QObject *parent=0);
    ~WindowsController();

public slots:
    void ShowMenuWindow();
private slots:
    void StartGameSlot();
    void SettingsSlot();
    void QuitGameSlot();
};

#endif // WINDOWSCONTROLLER_H
