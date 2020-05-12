#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    //    displayWindow(new MainWindowList),
    mainWidget(new QWidget),
    frequencyWidget(new QWidget),
    programWidget(new QWidget),
    childrenWidget(new QWidget),
    settingsWidget(new QWidget),
    colourWidget(new QWidget),
    languageWidget(new QWidget),
    mainWindowList(new MainWindowList),
    frequencyWindow(new FrequencyWindow),
    programWindow(new ProgramWindow),
    childrenWindow(new ChildrenWindow),
    settingsWindow(new SettingsWindow),
    colourWindow(new ColourWindow),
    languageWindow(new LanguageWindow),
    mainStackedLayout(new QStackedLayout),
    currentPower(new Power),
    timer(new TimerDisplay),
    isPower(false)
{
    ui->setupUi(this);
    this->mainWidget->setLayout(this->mainWindowList->currentLayout);
    this->frequencyWidget->setLayout(this->frequencyWindow->currentLayout);
    this->programWidget->setLayout(this->programWindow->currentLayout);
    this->childrenWidget->setLayout(this->childrenWindow->currentLayout);
    this->settingsWidget->setLayout(this->settingsWindow->currentLayout);
    this->colourWidget->setLayout(this->colourWindow->currentLayout);
    this->languageWidget->setLayout(this->languageWindow->currentLayout);

    this->mainStackedLayout->addWidget(this->mainWidget);
    this->mainStackedLayout->addWidget(this->frequencyWidget);
    this->mainStackedLayout->addWidget(this->programWidget);
    this->mainStackedLayout->addWidget(this->childrenWidget);
    this->mainStackedLayout->addWidget(this->settingsWidget);
    this->mainStackedLayout->addWidget(this->colourWidget);
    this->mainStackedLayout->addWidget(this->languageWidget);
    this->mainStackedLayout->addWidget(this->currentPower);
    this->mainStackedLayout->addWidget(this->timer);
    ui->verticalLayout->addLayout(this->mainStackedLayout);

    this->displayWindow = this->mainWindowList;
    this->mainStackedLayout->setCurrentWidget(this->mainWidget);
}

MainWindow::~MainWindow()
{
    delete this->displayWindow;
    delete this->mainStackedLayout;
    delete ui;
}

void MainWindow::on_undo_clicked()
{
    if(!this->displayWindow->windowName.compare("FrequencyWindow",Qt::CaseInsensitive) ||
            !this->displayWindow->windowName.compare("ProgramWindow",Qt::CaseInsensitive) ||
            !this->displayWindow->windowName.compare("childrenWindow",Qt::CaseInsensitive) ||
            !this->displayWindow->windowName.compare("settingsWindow",Qt::CaseInsensitive))
    {
        this->displayWindow = this->mainWindowList;
        this->mainStackedLayout->setCurrentWidget(this->mainWidget);
    }
    if(!this->displayWindow->windowName.compare("colourWindow",Qt::CaseInsensitive) ||
            !this->displayWindow->windowName.compare("languageWindow",Qt::CaseInsensitive) )
    {
        this->displayWindow = this->settingsWindow;
        this->mainStackedLayout->setCurrentWidget(this->settingsWidget);
    }
}

void MainWindow::on_mainWindow_clicked()
{
    this->displayWindow = this->mainWindowList;
    this->mainStackedLayout->setCurrentWidget(this->mainWidget);
    this->isPower = false;
}

void MainWindow::on_up_clicked()
{
    this->displayWindow->decrementCursor();
    ui->verticalLayout->update();
}

void MainWindow::on_left_clicked()
{
    if(this->mainStackedLayout->currentWidget()->isEnabledTo(this->currentPower))
    {
        this->currentPower->power --;
        if(this->currentPower->power < 1)
        {
            this->currentPower->power = 1;
        }
        else if(this->currentPower->power > 10)
        {
            this->currentPower->power = 10;
        }
        else
        {
            this->currentPower->setPower(this->currentPower->power);
        }
    }
}

void MainWindow::on_ok_clicked()
{
    int currentCursorPosition = this->displayWindow->getCursor();

    if(!this->displayWindow->windowName.compare("MainWindowList",Qt::CaseInsensitive))
    {
        switch (currentCursorPosition) {
        case PROGRAMS:
            this->displayWindow = this->programWindow;
            this->mainStackedLayout->setCurrentWidget(this->programWidget);
            break;
        case FREQUENCY:
            this->displayWindow = this->frequencyWindow;
            this->mainStackedLayout->setCurrentWidget(this->frequencyWidget);
            break;
        case MED:
            //
            break;
        case SCREENING:
            //
            break;
        case CHILDREN:
            this->displayWindow = this->childrenWindow;
            this->mainStackedLayout->setCurrentWidget(this->childrenWidget);
            break;
        case SETTINGS:
            this->displayWindow = this->settingsWindow;
            this->mainStackedLayout->setCurrentWidget(this->settingsWidget);
            break;
        default:
            break;
        }
        this->isPower = false;
    }
    else if(!this->displayWindow->windowName.compare("FrequencyWindow",Qt::CaseInsensitive) && !this->isPower)
    {
        this->currentPower->power = 1;
        this->mainStackedLayout->setCurrentWidget(this->currentPower);
        this->isPower = true;
    }
    else if(!this->displayWindow->windowName.compare("ProgramWindow",Qt::CaseInsensitive) && !this->isPower)
    {
        this->currentPower->power = 1;
        this->mainStackedLayout->setCurrentWidget(this->currentPower);
        this->isPower = true;
    }
    else if(!this->displayWindow->windowName.compare("childrenWindow",Qt::CaseInsensitive))
    {
        this->on_undo_clicked();
        this->isPower = false;
    }
    else if(!this->displayWindow->windowName.compare("settingsWindow",Qt::CaseInsensitive))
    {
        if(dynamic_cast<SettingsWindow*>(this->displayWindow)->isFirstWindowDisplyed)
        {
            switch (currentCursorPosition) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
            }
        }
        else
        {
            switch (currentCursorPosition)
            {
            case 0:
                this->displayWindow = this->languageWindow;
                this->mainStackedLayout->setCurrentWidget(this->languageWidget);
                break;
            case 1:
                this->displayWindow = this->colourWindow;
                this->mainStackedLayout->setCurrentWidget(this->colourWidget);
                break;
            default:
                break;
            }
        }
        this->isPower = false;
    }
    else if(!this->displayWindow->windowName.compare("colourWindow",Qt::CaseInsensitive))
    {
        this->displayWindow = this->settingsWindow;
        this->mainStackedLayout->setCurrentWidget(this->settingsWidget);
        this->isPower = false;
    }
    else if(!this->displayWindow->windowName.compare("languageWindow",Qt::CaseInsensitive))
    {
        this->displayWindow = this->settingsWindow;
        this->mainStackedLayout->setCurrentWidget(this->settingsWidget);
        this->isPower = false;
    }
    else if(this->isPower)
    {
        this->mainStackedLayout->setCurrentWidget(this->timer);
        this->timer->startDefaultTimer();
    }
}

void MainWindow::on_right_clicked()
{
    if(this->mainStackedLayout->currentWidget()->isEnabledTo(this->currentPower))
    {
        this->currentPower->power ++;
        if(this->currentPower->power < 1)
        {
            this->currentPower->power = 1;
        }
        else if(this->currentPower->power > 10)
        {
            this->currentPower->power = 10;
        }
        else
        {
            this->currentPower->setPower(this->currentPower->power);
        }
    }
}

void MainWindow::on_down_clicked()
{
    this->displayWindow->incrementCursor();
    ui->verticalLayout->update();
}

void MainWindow::on_Off_On_clicked()
{
    this->close();
}


