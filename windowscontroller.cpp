#include "windowscontroller.h"

WindowsController::WindowsController(QObject *parent):QObject(parent)
{
    settingsWindow=new ToolsWindow();
    connect(settingsWindow,SIGNAL(ButtonBackClicked()),this,SLOT(ReturnToMenuSlot()));
    connect(settingsWindow,SIGNAL(ButtonSaveClicked()),this,SLOT(ReturnToMenuSlot()));
    onApplicationStart=true;
}

WindowsController::~WindowsController()
{
    delete menuWindow;
    delete settingsWindow;
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

void WindowsController::ReturnToMenuSlot()
{
    qDebug()<<"return";
    menuWindow->show();
}

void WindowsController::StartGameSlot()
{
    menuWindow->hide();
    if(onApplicationStart)
    {

        gameWindow=new GameWindow(settingsWindow->GetLanguageID(),settingsWindow->GetTopicID());
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
    menuWindow->hide();
    //settingsWindow=new ToolsWindow();
    settingsWindow->show();
}

void WindowsController::QuitGameSlot()
{
    QApplication::quit();
}
