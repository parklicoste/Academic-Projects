#ifndef CHILDRENWINDOW_H
#define CHILDRENWINDOW_H
#include "displaywindow.h"

constexpr uint8_t SECOND_WINDOW_CHILDREN_MAX_ITEMS(5);

typedef enum
{
    DISABLE = 0,
    UP_TO_ONE_YEAR,
    ONE_TO_THREE_YEARS,
    FOUR_TO_SEVEN,
    EIGHT_TO_TWELVE,

}ChildrenWindowList;


class ChildrenWindow : public DisplayWindow
{
public:
    ChildrenWindow();
    ~ChildrenWindow();
    void setCurrentItem();
    void incrementCursor();
    void decrementCursor();
private:
    QLabel *disable;
    QLabel *upToOneYear;
    QLabel *oneToThreeYears;
    QLabel *fourToSevenYears;
    QLabel *eightToTwelveYears;
};

#endif // CHILDRENWINDOW_H
