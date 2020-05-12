#include "coulourwindow.h"

ColourWindow::ColourWindow():
    turquoise(new QLabel),
    winter(new QLabel),
    bonze(new QLabel),
    night(new QLabel)
{
    this->currentLayout = new QVBoxLayout;
    this->cursor = 0;
    this->currentDisplayedItems = SECOND_WINDOW_COLOUR_MAX_ITEMS;
    this->palette.setColor(QPalette::Background, QColor(Qt::red));
    this->windowName = "ColourWindow";
    //init Window
    this->turquoise->setAutoFillBackground(true);
    this->turquoise->setPalette(this->palette);

    this->currentLayout->addWidget(this->turquoise);
    this->currentLayout->addWidget(this->winter);
    this->currentLayout->addWidget(this->bonze);
    this->currentLayout->addWidget(this->night);
    this->currentLayout->addStretch();


    this->turquoise->setText("TURQUOISE");
    this->winter->setText("WINTER");
    this->bonze->setText("BRONZE");
    this->night->setText("NIGHT");
}

ColourWindow::~ColourWindow()
{
    delete this->currentLayout;
}

void ColourWindow::setCurrentItem()
{
    switch (this->cursor) {
    case TURQUOISE:
        this->turquoise->setAutoFillBackground(true);
        this->turquoise->setPalette(this->palette);
        this->winter->setAutoFillBackground(false);
        this->night->setAutoFillBackground(false);
        break;
    case WINTER:
        this->winter->setAutoFillBackground(true);
        this->winter->setPalette(this->palette);
        this->turquoise->setAutoFillBackground(false);
        this->bonze->setAutoFillBackground(false);
        break;
    case BRONZE:
        this->bonze->setAutoFillBackground(true);
        this->bonze->setPalette(this->palette);
        this->winter->setAutoFillBackground(false);
        this->night->setAutoFillBackground(false);
        break;
    case NIGHT:
        this->night->setAutoFillBackground(true);
        this->night->setPalette(this->palette);
        this->bonze->setAutoFillBackground(false);
        this->turquoise->setAutoFillBackground(false);
        break;
    default:
        break;
    }
}

void ColourWindow::incrementCursor()
{
    this->cursor ++;
    if(this->cursor > (this->currentDisplayedItems-1))
        this->cursor = 0;
    this->setCurrentItem();
}

void ColourWindow::decrementCursor()
{
    this->cursor --;
    if(this->cursor < 0)
        this->cursor = (this->currentDisplayedItems-1);
    this->setCurrentItem();
}
