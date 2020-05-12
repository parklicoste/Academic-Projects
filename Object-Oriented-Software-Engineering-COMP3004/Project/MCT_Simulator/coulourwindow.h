#ifndef COULOURWINDOW_H
#define COULOURWINDOW_H

#include "displaywindow.h"
constexpr uint8_t SECOND_WINDOW_COLOUR_MAX_ITEMS(4);
typedef enum
{
    TURQUOISE = 0,
    WINTER,
    BRONZE,
    NIGHT

}ColourWindowListItems;

class ColourWindow : public DisplayWindow
{
public:
    ColourWindow();
    ~ColourWindow();
    void setCurrentItem();
    void incrementCursor();
    void decrementCursor();
private:
    QLabel *turquoise;
    QLabel *winter;
    QLabel *bonze;
    QLabel *night;
};

#endif // COULOURWINDOW_H
