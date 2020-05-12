#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindowlist.h"
#include "frequencywindow.h"
#include "programwindow.h"
#include "childrenwindow.h"
#include "settingswindow.h"
#include "coulourwindow.h"
#include "languagewindow.h"
#include "power.h"
#include "timerdisplay.h"
#include <QStackedLayout>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_undo_clicked();

    void on_mainWindow_clicked();

    void on_up_clicked();

    void on_left_clicked();

    void on_ok_clicked();

    void on_right_clicked();

    void on_down_clicked();

    void on_Off_On_clicked();

private:
    Ui::MainWindow *ui;
    DisplayWindow *displayWindow;
    QWidget *mainWidget;
    QWidget *frequencyWidget;
    QWidget *programWidget;
    QWidget *childrenWidget;
    QWidget *settingsWidget;
    QWidget *colourWidget;
    QWidget *languageWidget;

    MainWindowList *mainWindowList;
    FrequencyWindow *frequencyWindow;
    ProgramWindow *programWindow;
    ChildrenWindow *childrenWindow;
    SettingsWindow *settingsWindow;
    ColourWindow *colourWindow;
    LanguageWindow *languageWindow;

    QStackedLayout *mainStackedLayout;

    Power *currentPower;
    TimerDisplay *timer;
    bool isPower;
    //main Vbox window

};

#endif // MAINWINDOW_H
