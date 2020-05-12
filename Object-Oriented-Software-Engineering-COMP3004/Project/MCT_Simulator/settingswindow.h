#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H
#include "displaywindow.h"

constexpr uint8_t SECOND_WINDOW_SETTINGS_MAX_ITEMS(2);

class SettingsWindow : public DisplayWindow
{
public:
    SettingsWindow();
    ~SettingsWindow();
    void setCurrentItem();
    void incrementCursor();
    void decrementCursor();
    void setFirstWindow();
    void setSecondWindow();
    bool isFirstWindowDisplyed;
    bool isUp;
private:
    QLabel *sounds;
    QLabel *brightness;
    QLabel *economy;
    QLabel *recording;
    QLabel *clock;
    QLabel *alarm;
    QLabel *language;
    QLabel *colour;
};

#endif // SETTINGSWINDOW_H
