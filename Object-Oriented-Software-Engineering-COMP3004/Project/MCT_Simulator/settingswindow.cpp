#include "settingswindow.h"

SettingsWindow::SettingsWindow():
    sounds(new QLabel),
    brightness(new QLabel),
    economy(new QLabel),
    recording(new QLabel),
    clock(new QLabel),
    alarm(new QLabel),
    language(new QLabel),
    colour(new QLabel),
    isFirstWindowDisplyed(true),
    isUp(false)
{
    this->currentLayout = new QVBoxLayout;
    this->cursor = 0;
    this->currentDisplayedItems = MAX_DISPLAYED_ITEMS_NUMBER;
    this->palette.setColor(QPalette::Background, QColor(Qt::red));
    this->windowName = "SettingsWindow";
    //initWindow
    this->sounds->setAutoFillBackground(true);
    this->sounds->setPalette(this->palette);

    this->currentLayout->addWidget(this->sounds);
    this->currentLayout->addWidget(this->brightness);
    this->currentLayout->addWidget(this->economy);
    this->currentLayout->addWidget(this->recording);
    this->currentLayout->addWidget(this->clock);
    this->currentLayout->addWidget(this->alarm);


    this->sounds->setText("SOUND");
    this->brightness->setText("BRIGHTNESS");
    this->economy->setText("ECONOMY");
    this->recording->setText("RECORDING");
    this->clock->setText("CLOCK");
    this->alarm->setText("ALARM");
    this->language->setText("LANGUAGE");
    this->colour->setText("COLOUR");
}

SettingsWindow::~SettingsWindow()
{
    delete this->currentLayout;
}

void SettingsWindow::setCurrentItem()
{
    if(this->isFirstWindowDisplyed)
    {
        switch (this->cursor) {
        case 0:
            this->sounds->setAutoFillBackground(true);
            this->sounds->setPalette(this->palette);
            this->brightness->setAutoFillBackground(false);
            this->colour->setAutoFillBackground(false);
            break;
        case 1:
            this->brightness->setAutoFillBackground(true);
            this->brightness->setPalette(this->palette);
            this->sounds->setAutoFillBackground(false);
            this->economy->setAutoFillBackground(false);
            break;
        case 2:
            this->economy->setAutoFillBackground(true);
            this->economy->setPalette(this->palette);
            this->brightness->setAutoFillBackground(false);
            this->recording->setAutoFillBackground(false);
            break;
        case 3:
            this->recording->setAutoFillBackground(true);
            this->recording->setPalette(this->palette);
            this->economy->setAutoFillBackground(false);
            this->clock->setAutoFillBackground(false);
            break;
        case 4:
            this->clock->setAutoFillBackground(true);
            this->clock->setPalette(this->palette);
            this->recording->setAutoFillBackground(false);
            this->alarm->setAutoFillBackground(false);
            break;
        case 5:
            this->alarm->setAutoFillBackground(true);
            this->alarm->setPalette(this->palette);
            this->clock->setAutoFillBackground(false);
            this->language->setAutoFillBackground(false);
            break;
        default:
            break;
        }
    }
    else
    {
        switch (this->cursor)
        {
        case 0:
            this->language->setAutoFillBackground(true);
            this->language->setPalette(this->palette);
            this->alarm->setAutoFillBackground(false);
            this->colour->setAutoFillBackground(false);
            break;
        case 1:
            this->colour->setAutoFillBackground(true);
            this->colour->setPalette(this->palette);
            this->language->setAutoFillBackground(false);
            this->sounds->setAutoFillBackground(false);
            break;
        default:
            break;
        }
    }
}

void SettingsWindow::incrementCursor()
{
    this->cursor ++;
    if(this->cursor > (this->currentDisplayedItems-1))
    {
        this->isUp = false;
        if(isFirstWindowDisplyed)
        {
            this->setSecondWindow();
        }
        else
        {
            this->setFirstWindow();
        }
    }
    this->setCurrentItem();
}

void SettingsWindow::decrementCursor()
{
    this->cursor --;
    if( this->cursor < 0 )
    {
        this->isUp = true;
        if(isFirstWindowDisplyed)
        {
            this->setSecondWindow();
        }
        else
        {
            this->setFirstWindow();
        }
    }
    this->setCurrentItem();
}

void SettingsWindow::setFirstWindow()
{
    //Add Items
    this->currentLayout->addWidget(this->sounds);
    this->currentLayout->addWidget(this->brightness);
    this->currentLayout->addWidget(this->economy);
    this->currentLayout->addWidget(this->recording);
    this->currentLayout->addWidget(this->clock);
    this->currentLayout->addWidget(this->alarm);
    this->sounds->setVisible(true);
    this->brightness->setVisible(true);
    this->economy->setVisible(true);
    this->recording->setVisible(true);
    this->clock->setVisible(true);
    this->alarm->setVisible(true);
    //Remove Items
    this->currentLayout->removeWidget(this->language);
    this->currentLayout->removeWidget(this->colour);
    this->language->setVisible(false);
    this->colour->setVisible(false);

    if(this->isUp)
    {
        this->cursor = MAX_DISPLAYED_ITEMS_NUMBER -1 ; // start from 140 Hz
    }
    else
    {
        this->cursor = 0;
    }

    this->currentDisplayedItems = MAX_DISPLAYED_ITEMS_NUMBER;
    isFirstWindowDisplyed = true;
}

void SettingsWindow::setSecondWindow()
{
    // Add Items
    this->currentLayout->addWidget(this->language);
    this->currentLayout->addWidget(this->colour);
    this->currentLayout->addStretch();
    this->language->setVisible(true);
    this->colour->setVisible(true);

    //Remove Items
    this->currentLayout->removeWidget(this->sounds);
    this->currentLayout->removeWidget(this->brightness);
    this->currentLayout->removeWidget(this->economy);
    this->currentLayout->removeWidget(this->recording);
    this->currentLayout->removeWidget(this->clock);
    this->currentLayout->removeWidget(this->alarm);
    this->sounds->setVisible(false);
    this->brightness->setVisible(false);
    this->economy->setVisible(false);
    this->recording->setVisible(false);
    this->clock->setVisible(false);
    this->alarm->setVisible(false);

    if(this->isUp)
    {
        this->cursor = SECOND_WINDOW_SETTINGS_MAX_ITEMS - 1; // start from 140 Hz
    }
    else
    {
        this->cursor = 0;
    }

    this->currentDisplayedItems = SECOND_WINDOW_SETTINGS_MAX_ITEMS;
    isFirstWindowDisplyed = false;
}
