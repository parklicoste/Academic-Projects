#ifndef FREQUENCYWINDOW_H
#define FREQUENCYWINDOW_H
#include "displaywindow.h"

constexpr uint8_t SECOND_WINDOW_MAX_ITEMS(5);

class FrequencyWindow : public DisplayWindow
{
public:
    FrequencyWindow();
    ~FrequencyWindow();
    void setCurrentItem();
    void incrementCursor();
    void decrementCursor();
    void setFirstWindow();
    void setSecondWindow();
private:
    QLabel *oneToten;
    QLabel *ten;
    QLabel *twenty;
    QLabel *sixty;
    QLabel *seventyseven;
    QLabel *oneTwentyFive;
    QLabel *oneFourty;
    QLabel *twoHundred;
    QLabel *sevenSevenOneZero;
    QLabel *sevenSevenTwoZero;
    QLabel *sevenSevenAm;
    bool isFirstWindowDisplyed;
    bool isUp;
};

#endif // FREQUENCYWINDOW_H
