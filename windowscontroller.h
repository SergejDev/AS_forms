#ifndef WINDOWSCONTROLLER_H
#define WINDOWSCONTROLLER_H
#include <QObject>
#include "gamewindow.h"
#include "menuwindow.h"
#include "WINDOW.h"

class WindowsController: public QObject
{
    Q_OBJECT
private:
    MenuWindow *menuWindow;
    GameWindow *gameWindow;
    ToolsWindow *settingsWindow;
    bool onApplicationStart;

public:
    WindowsController(QObject *parent=0);
    ~WindowsController();

public slots:
    void ShowMenuWindow(bool isGameWindowActive=false);
private slots:
    void StartGameSlot();
    void SettingsSlot();
    void QuitGameSlot();
    void ReturnToMenuSlot();
};

#endif // WINDOWSCONTROLLER_H
