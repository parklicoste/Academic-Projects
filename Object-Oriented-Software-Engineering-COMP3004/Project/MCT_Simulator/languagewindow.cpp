#include "languagewindow.h"

LanguageWindow::LanguageWindow():
    russian(new QLabel),
    english(new QLabel),
    german(new QLabel),
    frensh(new QLabel),
    italien(new QLabel)
{
    this->currentLayout = new QVBoxLayout;
    this->cursor = 0;
    this->currentDisplayedItems = SECOND_WINDOW_LANGUGE_MAX_ITEMS;
    this->palette.setColor(QPalette::Background, QColor(Qt::red));
    this->windowName = "LanguageWindow";
    //init Window
    this->russian->setAutoFillBackground(true);
    this->russian->setPalette(this->palette);

    this->currentLayout->addWidget(this->russian);
    this->currentLayout->addWidget(this->english);
    this->currentLayout->addWidget(this->german);
    this->currentLayout->addWidget(this->frensh);
    this->currentLayout->addWidget(this->italien);

    this->russian->setText("RUSSIAN");
    this->english->setText("ENGLISH");
    this->german->setText("GERMAN");
    this->frensh->setText("FRENSH");
    this->italien->setText("ITALIAN");
}

LanguageWindow::~LanguageWindow()
{
    delete this->currentLayout;
}

void LanguageWindow::setCurrentItem()
{
    switch (this->cursor) {
    case RUSSIAN:
        this->russian->setAutoFillBackground(true);
        this->russian->setPalette(this->palette);
        this->english->setAutoFillBackground(false);
        this->italien->setAutoFillBackground(false);
        break;
    case ENGLISH:
        this->english->setAutoFillBackground(true);
        this->english->setPalette(this->palette);
        this->russian->setAutoFillBackground(false);
        this->german->setAutoFillBackground(false);
        break;
    case GERMAN:
        this->german->setAutoFillBackground(true);
        this->german->setPalette(this->palette);
        this->english->setAutoFillBackground(false);
        this->frensh->setAutoFillBackground(false);
        break;
    case FRENSH:
        this->frensh->setAutoFillBackground(true);
        this->frensh->setPalette(this->palette);
        this->german->setAutoFillBackground(false);
        this->italien->setAutoFillBackground(false);
        break;
    case ITALIAN:
        this->italien->setAutoFillBackground(true);
        this->italien->setPalette(this->palette);
        this->frensh->setAutoFillBackground(false);
        this->russian->setAutoFillBackground(false);
        break;
    default:
        break;
    }
}

void LanguageWindow::incrementCursor()
{
    this->cursor ++;
    if(this->cursor > (this->currentDisplayedItems-1))
        this->cursor = 0;
    this->setCurrentItem();
}

void LanguageWindow::decrementCursor()
{
    this->cursor --;
    if(this->cursor < 0)
        this->cursor = (this->currentDisplayedItems-1);
    this->setCurrentItem();
}
