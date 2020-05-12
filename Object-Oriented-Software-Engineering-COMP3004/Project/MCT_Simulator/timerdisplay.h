#ifndef TIMER_H
#define TIMER_H
#include <QLabel>
#include <QTimer>
#include "QHBoxLayout"

constexpr uint16_t second(1000);
constexpr uint16_t tenMinutes(600);

class TimerDisplay : public QWidget
{
    Q_OBJECT
public:
    TimerDisplay();
    ~TimerDisplay();
    void startDefaultTimer();
    void setHours(const uint &hours);

    void setMinutes(const uint &minutes);

    void setSeconds(const uint &seconds);

public slots:
    void downCounter();
private:
    QLabel *hours;
    QLabel *minutes;
    QLabel *seconds;
    QLabel *twoPoints1;
    QLabel *twoPoints2;
    QTimer *myTimer;
    QHBoxLayout *currentLayout;
    uint counter;
    uint m_hours;
    uint m_minutes;
    uint m_seconds;
};

#endif // TIMER_H
