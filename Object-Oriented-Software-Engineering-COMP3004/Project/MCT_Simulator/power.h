#ifndef POWER_H
#define POWER_H
#include <QProgressBar>
#include <QLabel>
#include <QVBoxLayout>

class Power : public QWidget
{
public:
    Power();
    ~Power();
    void setProgressBar(QProgressBar *value);
    void setPower(uint power);
    uint power;
private:
    QProgressBar *progressBar;
    QLabel *powerValue;
    QLabel *powerName;
    QVBoxLayout *currentLayout;
};

#endif // POWER_H
