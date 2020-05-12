#include "timerdisplay.h"

TimerDisplay::TimerDisplay():
    hours(new QLabel),
    minutes(new QLabel),
    seconds(new QLabel),
    myTimer(new QTimer),
    currentLayout(new QHBoxLayout),
    twoPoints1(new QLabel),
    twoPoints2(new QLabel),
    counter(0)
{
    QFont font;
    font.setPointSize(40);
    font.setBold(true);
    this->hours->setFont(font);
    this->minutes->setFont(font);
    this->seconds->setFont(font);
    this->twoPoints1->setFont(font);
    this->twoPoints2->setFont(font);
    this->hours->setText("00");
    this->minutes->setText("00");
    this->seconds->setText("00");
    this->twoPoints1->setText(":");
    this->twoPoints2->setText(":");


    this->currentLayout->addWidget(this->hours);
    this->currentLayout->addWidget(this->twoPoints1);
    this->currentLayout->addWidget(this->minutes);
    this->currentLayout->addWidget(this->twoPoints2);
    this->currentLayout->addWidget(this->seconds);

    connect(this->myTimer,SIGNAL(timeout()),this,SLOT(downCounter()));

    this->setLayout(this->currentLayout);
}

TimerDisplay::~TimerDisplay()
{
    delete currentLayout;
}

void TimerDisplay::downCounter()
{
    if(counter == 0)
    {
        return;
    }
    else if (this->counter >= 3600)
    {
        this->m_hours = this->counter / 3600;
        this->m_minutes = this->counter / 60;
        this->m_seconds = (this->counter / 60) % 60;
        this->counter --;
        if(this->m_hours < 10)
            this->hours->setText("0" + QString::number(m_hours));
        else
            this->hours->setText(QString::number(m_hours));
        if(this->m_minutes < 10)
            this->minutes->setText("0" + QString::number(m_minutes));
        else
            this->minutes->setText(QString::number(m_minutes));
        if(this->m_seconds < 10)
            this->seconds->setText("0"+ QString::number(m_seconds));
        else
            this->seconds->setText(QString::number(m_seconds));
        this->myTimer->start(second);
    }
    else
    {
        this->m_minutes = this->counter / 60;
        this->m_seconds = this->counter % 60;
        this->counter --;
        if(this->m_minutes < 10)
            this->minutes->setText("0" + QString::number(m_minutes));
        else
            this->minutes->setText(QString::number(m_minutes));
        if(this->m_seconds < 10)
            this->seconds->setText("0"+ QString::number(m_seconds));
        else
            this->seconds->setText(QString::number(m_seconds));
        this->myTimer->start(second);
    }


}

void TimerDisplay::setSeconds(const uint &seconds)
{
    m_seconds = seconds;
}

void TimerDisplay::setMinutes(const uint &minutes)
{
    m_minutes = minutes;
}

void TimerDisplay::setHours(const uint &hours)
{
    m_hours = hours;
}

void TimerDisplay::startDefaultTimer()
{
    this->counter = tenMinutes;
    this->myTimer->start(second); // 10 minutes
}

