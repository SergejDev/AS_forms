#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDialog>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();
    
private:
    Ui::MenuWindow *ui;
    void SetWindowStyle();
signals:
    void StartButtonPressed();
    void SettingsButtonPressed();
    void QuitButtonPressed();
};

#endif // MENUWINDOW_H
