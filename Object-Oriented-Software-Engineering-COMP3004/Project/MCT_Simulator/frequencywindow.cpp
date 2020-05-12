#include "frequencywindow.h"

FrequencyWindow::FrequencyWindow():
    oneToten(new QLabel),
    ten(new QLabel),
    twenty(new QLabel),
    sixty(new QLabel),
    seventyseven(new QLabel),
    oneTwentyFive(new QLabel),
    oneFourty(new QLabel),
    twoHundred(new QLabel),
    sevenSevenOneZero(new QLabel),
    sevenSevenTwoZero(new QLabel),
    sevenSevenAm(new QLabel),
    isFirstWindowDisplyed(true),
    isUp(false)
{
    this->currentLayout = new QVBoxLayout;
    this->cursor = 0;
    this->currentDisplayedItems = MAX_DISPLAYED_ITEMS_NUMBER;
    this->palette.setColor(QPalette::Background, QColor(Qt::red));
    this->windowName = "FrequencyWindow";
    //initWindow
    this->oneToten->setAutoFillBackground(true);
    this->oneToten->setPalette(this->palette);

    this->currentLayout->addWidget(this->oneToten);
    this->currentLayout->addWidget(this->ten);
    this->currentLayout->addWidget(this->twenty);
    this->currentLayout->addWidget(this->sixty);
    this->currentLayout->addWidget(this->seventyseven);
    this->currentLayout->addWidget(this->oneTwentyFive);


    this->oneToten->setText("1.0-9.99 Hz");
    this->ten->setText("10 Hz");
    this->twenty->setText("20 Hz");
    this->sixty->setText("60 Hz");
    this->seventyseven->setText("77 Hz");
    this->oneTwentyFive->setText("125 Hz");
    this->oneFourty->setText("140 Hz");
    this->twoHundred->setText("200 Hz");
    this->sevenSevenOneZero->setText("7710 Hz");
    this->sevenSevenTwoZero->setText("7720 Hz");
    this->sevenSevenAm->setText("77 AM");

}

FrequencyWindow::~FrequencyWindow()
{
    //delete this->currentWidget;
    delete this->currentLayout;
}

void FrequencyWindow::setCurrentItem()
{
    if(this->isFirstWindowDisplyed)
    {
        switch (this->cursor) {
        case 0:
            this->oneToten->setAutoFillBackground(true);
            this->oneToten->setPalette(this->palette);
            this->ten->setAutoFillBackground(false);
            this->sevenSevenAm->setAutoFillBackground(false);
            break;
        case 1:
            this->ten->setAutoFillBackground(true);
            this->ten->setPalette(this->palette);
            this->oneToten->setAutoFillBackground(false);
            this->twenty->setAutoFillBackground(false);
            break;
        case 2:
            this->twenty->setAutoFillBackground(true);
            this->twenty->setPalette(this->palette);
            this->ten->setAutoFillBackground(false);
            this->sixty->setAutoFillBackground(false);
            break;
        case 3:
            this->sixty->setAutoFillBackground(true);
            this->sixty->setPalette(this->palette);
            this->twenty->setAutoFillBackground(false);
            this->seventyseven->setAutoFillBackground(false);
            break;
        case 4:
            this->seventyseven->setAutoFillBackground(true);
            this->seventyseven->setPalette(this->palette);
            this->sixty->setAutoFillBackground(false);
            this->oneTwentyFive->setAutoFillBackground(false);
            break;
        case 5:
            this->oneTwentyFive->setAutoFillBackground(true);
            this->oneTwentyFive->setPalette(this->palette);
            this->seventyseven->setAutoFillBackground(false);
            this->oneFourty->setAutoFillBackground(false);
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
            this->oneFourty->setAutoFillBackground(true);
            this->oneFourty->setPalette(this->palette);
            this->oneTwentyFive->setAutoFillBackground(false);
            this->twoHundred->setAutoFillBackground(false);
            break;
        case 1:
            this->twoHundred->setAutoFillBackground(true);
            this->twoHundred->setPalette(this->palette);
            this->oneFourty->setAutoFillBackground(false);
            this->sevenSevenOneZero->setAutoFillBackground(false);
            break;
        case 2:
            this->sevenSevenOneZero->setAutoFillBackground(true);
            this->sevenSevenOneZero->setPalette(this->palette);
            this->twoHundred->setAutoFillBackground(false);
            this->sevenSevenTwoZero->setAutoFillBackground(false);
            break;
        case 3:
            this->sevenSevenTwoZero->setAutoFillBackground(true);
            this->sevenSevenTwoZero->setPalette(this->palette);
            this->sevenSevenOneZero->setAutoFillBackground(false);
            this->sevenSevenAm->setAutoFillBackground(false);
            break;
        case 4:
            this->sevenSevenAm->setAutoFillBackground(true);
            this->sevenSevenAm->setPalette(this->palette);
            this->oneToten->setAutoFillBackground(false);
            this->sevenSevenTwoZero->setAutoFillBackground(false);
            break;
        default:
            break;
        }
    }

}

void FrequencyWindow::incrementCursor()
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

void FrequencyWindow::decrementCursor()
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

void FrequencyWindow::setSecondWindow()
{
    // Add Items
    this->currentLayout->addWidget(this->oneFourty);
    this->currentLayout->addWidget(this->twoHundred);
    this->currentLayout->addWidget(this->sevenSevenOneZero);
    this->currentLayout->addWidget(this->sevenSevenTwoZero);
    this->currentLayout->addWidget(this->sevenSevenAm);
    this->oneFourty->setVisible(true);
    this->twoHundred->setVisible(true);
    this->sevenSevenOneZero->setVisible(true);
    this->sevenSevenTwoZero->setVisible(true);
    this->sevenSevenAm->setVisible(true);
    //Remove Items
    this->currentLayout->removeWidget(this->oneToten);
    this->currentLayout->removeWidget(this->ten);
    this->currentLayout->removeWidget(this->twenty);
    this->currentLayout->removeWidget(this->sixty);
    this->currentLayout->removeWidget(this->seventyseven);
    this->currentLayout->removeWidget(this->oneTwentyFive);
    this->oneToten->setVisible(false);
    this->ten->setVisible(false);
    this->twenty->setVisible(false);
    this->sixty->setVisible(false);
    this->seventyseven->setVisible(false);
    this->oneTwentyFive->setVisible(false);

    if(this->isUp)
    {
        this->cursor = SECOND_WINDOW_MAX_ITEMS - 1; // start from 140 Hz
    }
    else
    {
        this->cursor = 0;
    }

    this->currentDisplayedItems = SECOND_WINDOW_MAX_ITEMS;
    isFirstWindowDisplyed = false;
}

void FrequencyWindow::setFirstWindow()
{
    //Add Items
    this->currentLayout->addWidget(this->oneToten);
    this->currentLayout->addWidget(this->ten);
    this->currentLayout->addWidget(this->twenty);
    this->currentLayout->addWidget(this->sixty);
    this->currentLayout->addWidget(this->seventyseven);
    this->currentLayout->addWidget(this->oneTwentyFive);
    this->oneToten->setVisible(true);
    this->ten->setVisible(true);
    this->twenty->setVisible(true);
    this->sixty->setVisible(true);
    this->seventyseven->setVisible(true);
    this->oneTwentyFive->setVisible(true);
    //Remove Items
    this->currentLayout->removeWidget(this->oneFourty);
    this->currentLayout->removeWidget(this->twoHundred);
    this->currentLayout->removeWidget(this->sevenSevenOneZero);
    this->currentLayout->removeWidget(this->sevenSevenTwoZero);
    this->currentLayout->removeWidget(this->sevenSevenAm);
    this->oneFourty->setVisible(false);
    this->twoHundred->setVisible(false);
    this->sevenSevenOneZero->setVisible(false);
    this->sevenSevenTwoZero->setVisible(false);
    this->sevenSevenAm->setVisible(false);

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

