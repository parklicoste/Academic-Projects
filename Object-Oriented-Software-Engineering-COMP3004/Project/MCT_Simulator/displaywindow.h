#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H
#include <QVBoxLayout>
#include <QPalette>
#include <QString>
#include <QLabel>

constexpr uint8_t MAX_DISPLAYED_ITEMS_NUMBER(6);

class DisplayWindow
{
public:
    virtual ~DisplayWindow() = default;
    virtual void incrementCursor() = 0;
    virtual void decrementCursor() = 0;
    QString windowName;
    QVBoxLayout *currentLayout;
    int getCursor() const;
protected:
    virtual void setCurrentItem() = 0;
    int cursor;
    uint currentDisplayedItems;
    QPalette palette;
};

#endif // DISPLAYWINDOW_H
