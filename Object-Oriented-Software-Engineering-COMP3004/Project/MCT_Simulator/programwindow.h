#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H
#include "displaywindow.h"

constexpr uint8_t SECOND_WINDOW_PROGRAM_MAX_ITEMS(5);

class ProgramWindow : public DisplayWindow
{
public:
    ProgramWindow();
    ~ProgramWindow();
    void setCurrentItem();
    void incrementCursor();
    void decrementCursor();
    void setFirstWindow();
    void setSecondWindow();
    bool isFirstWindowDisplyed;
    bool isUp;
private:
    QLabel *allergy;
    QLabel *pain;
    QLabel *intPain;
    QLabel *bloating;
    QLabel *dystonia;
    QLabel *gymPain;
    QLabel *gynecology;
    QLabel *hypertension;
    QLabel *hypotonia;
    QLabel *head;
    QLabel *throat;
};

#endif // PROGRAMWINDOW_H
