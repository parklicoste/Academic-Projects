#ifndef MAINWINDOWLIST_H
#define MAINWINDOWLIST_H
#include "displaywindow.h"

typedef enum
{
    PROGRAMS = 0,
    FREQUENCY,
    MED,
    SCREENING,
    CHILDREN,
    SETTINGS,
    NO_MAIN_WINDOW_LIST
}MainWindowListItems;


class MainWindowList : public DisplayWindow
{
public:
    MainWindowList();
    ~MainWindowList();
    void setCurrentItem();
    void incrementCursor();
    void decrementCursor();
private:
    QLabel *programs;
    QLabel *frequency;
    QLabel *med;
    QLabel *screening;
    QLabel *children;
    QLabel *settings;
};

#endif // MAINWINDOWLIST_H
