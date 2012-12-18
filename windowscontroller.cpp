#include "windowscontroller.h"

WindowsController::WindowsController(QObject *parent):QObject(parent)
{
    onApplicationStart=true;
    //gameWindow=new GameWindow();

}

WindowsController::~WindowsController()
{
    delete menuWindow;
    //delete gameWindow;
}

void WindowsController::ShowMenuWindow(bool isGameWindowActive)
{
    menuWindow=new MenuWindow();
    connect(menuWindow,SIGNAL(StartButtonPressed()),this,SLOT(StartGameSlot()));
    connect(menuWindow,SIGNAL(SettingsButtonPressed()),this,SLOT(SettingsSlot()));
    connect(menuWindow,SIGNAL(QuitButtonPressed()),this,SLOT(QuitGameSlot()));
    menuWindow->show();
    if(isGameWindowActive)
    {
        gameWindow->PauseGame();
    }
}

void WindowsController::StartGameSlot()
{
    menuWindow->hide();
    if(onApplicationStart)
    {
        gameWindow=new GameWindow();
        connect(gameWindow,SIGNAL(MenuButtonPressed(bool)),this,SLOT(ShowMenuWindow(bool)));
        gameWindow->show();
        onApplicationStart=false;
    }
    else
    {
        gameWindow->ResumeGame();
    }
}

void WindowsController::SettingsSlot()
{
    qDebug()<<"settings";
}

void WindowsController::QuitGameSlot()
{
    QApplication::quit();
}
