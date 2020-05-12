#include "mainwindowlist.h"

MainWindowList::MainWindowList():
    programs(new QLabel),
    frequency(new QLabel),
    med(new QLabel),
    screening(new QLabel),
    children(new QLabel),
    settings(new QLabel)
{
    this->currentLayout = new QVBoxLayout;
    this->cursor = 0;
    this->currentDisplayedItems = MAX_DISPLAYED_ITEMS_NUMBER;
    this->palette.setColor(QPalette::Background, QColor(Qt::red));
    this->windowName = "MainWindowList";
    //init Window
    this->programs->setAutoFillBackground(true);
    this->programs->setPalette(this->palette);

    this->currentLayout->addWidget(this->programs);
    this->currentLayout->addWidget(this->frequency);
    this->currentLayout->addWidget(this->med);
    this->currentLayout->addWidget(this->screening);
    this->currentLayout->addWidget(this->children);
    this->currentLayout->addWidget(this->settings);
    this->currentLayout->addStretch();


    this->programs->setText("PROGRAMS");
    this->frequency->setText("FREQUENCY");
    this->med->setText("MED");
    this->screening->setText("SCREENING");
    this->children->setText("CHILDREN");
    this->settings->setText("SETTINGS");
}

MainWindowList::~MainWindowList()
{
    delete this->currentLayout;
}

void MainWindowList::setCurrentItem()
{
    switch (this->cursor) {
    case PROGRAMS:
        this->programs->setAutoFillBackground(true);
        this->programs->setPalette(this->palette);
        this->frequency->setAutoFillBackground(false);
        this->settings->setAutoFillBackground(false);
        break;
    case FREQUENCY:
        this->frequency->setAutoFillBackground(true);
        this->frequency->setPalette(this->palette);
        this->programs->setAutoFillBackground(false);
        this->med->setAutoFillBackground(false);
        break;
    case MED:
        this->med->setAutoFillBackground(true);
        this->med->setPalette(this->palette);
        this->frequency->setAutoFillBackground(false);
        this->screening->setAutoFillBackground(false);
        break;
    case SCREENING:
        this->screening->setAutoFillBackground(true);
        this->screening->setPalette(this->palette);
        this->med->setAutoFillBackground(false);
        this->children->setAutoFillBackground(false);
        break;
    case CHILDREN:
        this->children->setAutoFillBackground(true);
        this->children->setPalette(this->palette);
        this->screening->setAutoFillBackground(false);
        this->settings->setAutoFillBackground(false);
        break;
    case SETTINGS:
        this->settings->setAutoFillBackground(true);
        this->settings->setPalette(this->palette);
        this->programs->setAutoFillBackground(false);
        this->children->setAutoFillBackground(false);
        break;
    default:
        break;
    }
}

void MainWindowList::incrementCursor()
{
    this->cursor ++;
    if(this->cursor > (this->currentDisplayedItems-1))
        this->cursor = 0;
    this->setCurrentItem();
}

void MainWindowList::decrementCursor()
{
    this->cursor --;
    if(this->cursor < 0)
        this->cursor = (this->currentDisplayedItems-1);
    this->setCurrentItem();
}


