#ifndef LANGUAGEWINDOW_H
#define LANGUAGEWINDOW_H
#include "displaywindow.h"

constexpr uint8_t SECOND_WINDOW_LANGUGE_MAX_ITEMS(5);

typedef enum
{
    RUSSIAN = 0,
    ENGLISH,
    GERMAN,
    FRENSH,
    ITALIAN

}LanguageWindowList;

class LanguageWindow : public DisplayWindow
{
public:
    LanguageWindow();
    ~LanguageWindow();
    void setCurrentItem();
    void incrementCursor();
    void decrementCursor();
private:
    QLabel *russian;
    QLabel *english;
    QLabel *german;
    QLabel *frensh;
    QLabel *italien;

};

#endif // LANGUAGEWINDOW_H
