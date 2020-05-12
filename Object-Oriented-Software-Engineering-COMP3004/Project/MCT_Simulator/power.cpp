#include "power.h"

Power::Power():
    progressBar(new QProgressBar),
    powerValue(new QLabel),
    currentLayout(new QVBoxLayout),
    powerName(new QLabel),
    power(1)
{
    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    this->powerValue->setText("1");
    this->powerValue->setFont(font);
    this->powerValue->setAlignment(Qt::AlignCenter);
    this->progressBar->setRange(1,10);
    this->progressBar->setValue(1);
    this->powerName->setText("POWER");
    this->powerName->setAlignment(Qt::AlignCenter);
    this->powerName->setFont(font);

    this->currentLayout->addStretch();
    this->currentLayout->addWidget(this->powerName);
    this->currentLayout->addWidget(this->powerValue);
    this->currentLayout->addWidget(this->progressBar);
    this->currentLayout->addStretch();

    this->setLayout(this->currentLayout);
}

Power::~Power()
{
    delete this->currentLayout;
}


void Power::setPower(uint power)
{
    this->progressBar->setValue(power);
    this->powerValue->setText(QString::number(power));
}

