#include "childrenwindow.h"

ChildrenWindow::ChildrenWindow() :
    disable(new QLabel),
    upToOneYear(new QLabel),
    oneToThreeYears(new QLabel),
    fourToSevenYears(new QLabel),
    eightToTwelveYears(new QLabel)
{
    this->currentLayout = new QVBoxLayout;
    this->cursor = 0;
    this->currentDisplayedItems = SECOND_WINDOW_CHILDREN_MAX_ITEMS;
    this->palette.setColor(QPalette::Background, QColor(Qt::red));
    this->windowName = "ChildrenWindow";
    //init Window
    this->disable->setAutoFillBackground(true);
    this->disable->setPalette(this->palette);

    this->currentLayout->addWidget(this->disable);
    this->currentLayout->addWidget(this->upToOneYear);
    this->currentLayout->addWidget(this->oneToThreeYears);
    this->currentLayout->addWidget(this->fourToSevenYears);
    this->currentLayout->addWidget(this->eightToTwelveYears);

    this->disable->setText("DISABLE");
    this->upToOneYear->setText("UPTO 1 YEAR");
    this->oneToThreeYears->setText("1 - 3 YEARS");
    this->fourToSevenYears->setText("4 - 7 YEARS");
    this->eightToTwelveYears->setText("8 - 12 YEARS");
}

ChildrenWindow::~ChildrenWindow()
{
    delete this->currentLayout;
}

void ChildrenWindow::setCurrentItem()
{
    switch (this->cursor) {
    case DISABLE:
        this->disable->setAutoFillBackground(true);
        this->disable->setPalette(this->palette);
        this->eightToTwelveYears->setAutoFillBackground(false);
        this->upToOneYear->setAutoFillBackground(false);
        break;
    case UP_TO_ONE_YEAR:
        this->upToOneYear->setAutoFillBackground(true);
        this->upToOneYear->setPalette(this->palette);
        this->disable->setAutoFillBackground(false);
        this->oneToThreeYears->setAutoFillBackground(false);
        break;
    case ONE_TO_THREE_YEARS:
        this->oneToThreeYears->setAutoFillBackground(true);
        this->oneToThreeYears->setPalette(this->palette);
        this->upToOneYear->setAutoFillBackground(false);
        this->fourToSevenYears->setAutoFillBackground(false);
        break;
    case FOUR_TO_SEVEN:
        this->fourToSevenYears->setAutoFillBackground(true);
        this->fourToSevenYears->setPalette(this->palette);
        this->oneToThreeYears->setAutoFillBackground(false);
        this->eightToTwelveYears->setAutoFillBackground(false);
        break;
    case EIGHT_TO_TWELVE:
        this->eightToTwelveYears->setAutoFillBackground(true);
        this->eightToTwelveYears->setPalette(this->palette);
        this->fourToSevenYears->setAutoFillBackground(false);
        this->disable->setAutoFillBackground(false);
        break;
    default:
        break;
    }
}

void ChildrenWindow::incrementCursor()
{
    this->cursor ++;
    if(this->cursor > (this->currentDisplayedItems-1))
        this->cursor = 0;
    this->setCurrentItem();
}

void ChildrenWindow::decrementCursor()
{
    this->cursor --;
    if(this->cursor < 0)
        this->cursor = (this->currentDisplayedItems-1);
    this->setCurrentItem();
}
