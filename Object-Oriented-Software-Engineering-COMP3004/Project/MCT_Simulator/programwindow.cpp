#include "programwindow.h"

ProgramWindow::ProgramWindow():
    allergy(new QLabel),
    pain(new QLabel),
    intPain(new QLabel),
    bloating(new QLabel),
    dystonia(new QLabel),
    gymPain(new QLabel),
    gynecology(new QLabel),
    hypertension(new QLabel),
    hypotonia(new QLabel),
    head(new QLabel),
    throat(new QLabel),
    isFirstWindowDisplyed(true),
    isUp(false)
{
    this->currentLayout = new QVBoxLayout;
    this->cursor = 0;
    this->currentDisplayedItems = MAX_DISPLAYED_ITEMS_NUMBER;
    this->palette.setColor(QPalette::Background, QColor(Qt::red));
    this->windowName = "ProgramWindow";
    //initWindow
    this->allergy->setAutoFillBackground(true);
    this->allergy->setPalette(this->palette);

    this->currentLayout->addWidget(this->allergy);
    this->currentLayout->addWidget(this->pain);
    this->currentLayout->addWidget(this->intPain);
    this->currentLayout->addWidget(this->bloating);
    this->currentLayout->addWidget(this->dystonia);
    this->currentLayout->addWidget(this->gymPain);


    this->allergy->setText("ALLERGY");
    this->pain->setText("PAIN");
    this->intPain->setText("INI. PIAN");
    this->bloating->setText("BLOATING");
    this->dystonia->setText("DYSTONIA");
    this->gymPain->setText("GYN. PAIN");
    this->gynecology->setText("GYNECOLOGY");
    this->hypertension->setText("HYPERTENSION");
    this->hypotonia->setText("HYPOTONIA");
    this->head->setText("HEAD");
    this->throat->setText("THROAT");
}

ProgramWindow::~ProgramWindow()
{
    delete this->currentLayout;
}

void ProgramWindow::setCurrentItem()
{
    if(this->isFirstWindowDisplyed)
    {
        switch (this->cursor) {
        case 0:
            this->allergy->setAutoFillBackground(true);
            this->allergy->setPalette(this->palette);
            this->pain->setAutoFillBackground(false);
            this->throat->setAutoFillBackground(false);
            break;
        case 1:
            this->pain->setAutoFillBackground(true);
            this->pain->setPalette(this->palette);
            this->allergy->setAutoFillBackground(false);
            this->intPain->setAutoFillBackground(false);
            break;
        case 2:
            this->intPain->setAutoFillBackground(true);
            this->intPain->setPalette(this->palette);
            this->pain->setAutoFillBackground(false);
            this->bloating->setAutoFillBackground(false);
            break;
        case 3:
            this->bloating->setAutoFillBackground(true);
            this->bloating->setPalette(this->palette);
            this->intPain->setAutoFillBackground(false);
            this->dystonia->setAutoFillBackground(false);
            break;
        case 4:
            this->dystonia->setAutoFillBackground(true);
            this->dystonia->setPalette(this->palette);
            this->gymPain->setAutoFillBackground(false);
            this->bloating->setAutoFillBackground(false);
            break;
        case 5:
            this->gymPain->setAutoFillBackground(true);
            this->gymPain->setPalette(this->palette);
            this->dystonia->setAutoFillBackground(false);
            this->gynecology->setAutoFillBackground(false);
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
            this->gynecology->setAutoFillBackground(true);
            this->gynecology->setPalette(this->palette);
            this->gymPain->setAutoFillBackground(false);
            this->hypertension->setAutoFillBackground(false);
            break;
        case 1:
            this->hypertension->setAutoFillBackground(true);
            this->hypertension->setPalette(this->palette);
            this->gynecology->setAutoFillBackground(false);
            this->hypotonia->setAutoFillBackground(false);
            break;
        case 2:
            this->hypotonia->setAutoFillBackground(true);
            this->hypotonia->setPalette(this->palette);
            this->hypertension->setAutoFillBackground(false);
            this->head->setAutoFillBackground(false);
            break;
        case 3:
            this->head->setAutoFillBackground(true);
            this->head->setPalette(this->palette);
            this->hypotonia->setAutoFillBackground(false);
            this->throat->setAutoFillBackground(false);
            break;
        case 4:
            this->throat->setAutoFillBackground(true);
            this->throat->setPalette(this->palette);
            this->head->setAutoFillBackground(false);
            this->allergy->setAutoFillBackground(false);
            break;
        default:
            break;
        }
    }

}

void ProgramWindow::incrementCursor()
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

void ProgramWindow::decrementCursor()
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

void ProgramWindow::setFirstWindow()
{
    //Add Items
    this->currentLayout->addWidget(this->allergy);
    this->currentLayout->addWidget(this->pain);
    this->currentLayout->addWidget(this->intPain);
    this->currentLayout->addWidget(this->bloating);
    this->currentLayout->addWidget(this->dystonia);
    this->currentLayout->addWidget(this->gymPain);
    this->allergy->setVisible(true);
    this->pain->setVisible(true);
    this->intPain->setVisible(true);
    this->bloating->setVisible(true);
    this->dystonia->setVisible(true);
    this->gymPain->setVisible(true);
    //Remove Items
    this->currentLayout->removeWidget(this->gynecology);
    this->currentLayout->removeWidget(this->hypertension);
    this->currentLayout->removeWidget(this->hypotonia);
    this->currentLayout->removeWidget(this->head);
    this->currentLayout->removeWidget(this->throat);
    this->gynecology->setVisible(false);
    this->hypertension->setVisible(false);
    this->hypotonia->setVisible(false);
    this->head->setVisible(false);
    this->throat->setVisible(false);

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

void ProgramWindow::setSecondWindow()
{
    // Add Items
    this->currentLayout->addWidget(this->gynecology);
    this->currentLayout->addWidget(this->hypertension);
    this->currentLayout->addWidget(this->hypotonia);
    this->currentLayout->addWidget(this->head);
    this->currentLayout->addWidget(this->throat);
    this->gynecology->setVisible(true);
    this->hypertension->setVisible(true);
    this->hypotonia->setVisible(true);
    this->head->setVisible(true);
    this->throat->setVisible(true);
    //Remove Items
    this->currentLayout->removeWidget(this->allergy);
    this->currentLayout->removeWidget(this->pain);
    this->currentLayout->removeWidget(this->intPain);
    this->currentLayout->removeWidget(this->bloating);
    this->currentLayout->removeWidget(this->dystonia);
    this->currentLayout->removeWidget(this->gymPain);
    this->allergy->setVisible(false);
    this->pain->setVisible(false);
    this->intPain->setVisible(false);
    this->bloating->setVisible(false);
    this->dystonia->setVisible(false);
    this->gymPain->setVisible(false);

    if(this->isUp)
    {
        this->cursor = SECOND_WINDOW_PROGRAM_MAX_ITEMS - 1; // start from 140 Hz
    }
    else
    {
        this->cursor = 0;
    }

    this->currentDisplayedItems = SECOND_WINDOW_PROGRAM_MAX_ITEMS;
    isFirstWindowDisplyed = false;
}
