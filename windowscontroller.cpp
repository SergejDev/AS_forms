#include "windowscontroller.h"

WindowsController::WindowsController(QObject *parent):QObject(parent)
{

    //gameWindow=new GameWindow();

}

WindowsController::~WindowsController()
{
    delete menuWindow;
    //delete gameWindow;
}

void WindowsController::ShowMenuWindow()
{
    menuWindow=new MenuWindow();
    connect(menuWindow,SIGNAL(StartButtonPressed()),this,SLOT(StartGameSlot()));
    connect(menuWindow,SIGNAL(SettingsButtonPressed()),this,SLOT(SettingsSlot()));
    connect(menuWindow,SIGNAL(QuitButtonPressed()),this,SLOT(QuitGameSlot()));
    menuWindow->show();
//    qDebug()<<gameWindow;
//    if(gameWindow)
//    {
//        qDebug()<<"sss";
//        gameWindow->PauseGame();
//    }
}

void WindowsController::StartGameSlot()
{
    menuWindow->hide();
    gameWindow=new GameWindow();
    connect(gameWindow,SIGNAL(MenuButtonPressed()),this,SLOT(ShowMenuWindow()));
    gameWindow->show();
}

void WindowsController::SettingsSlot()
{
    qDebug()<<"settings";
}

void WindowsController::QuitGameSlot()
{
    QApplication::quit();
}
