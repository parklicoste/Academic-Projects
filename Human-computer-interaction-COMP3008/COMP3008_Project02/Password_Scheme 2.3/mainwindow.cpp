#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <QDebug>
#include <QRandomGenerator>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <QCoreApplication>
#include <QList>
#include <QStringList>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <stdlib.h>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->lok->setVisible(false);
    this->ui->pls->setVisible(false);
    this->ui->ok->setVisible(false);
    this->ui->ok2->setVisible(false);
    input = new QVector<QString>;
    input->reserve(21);
   x=false;
   y= false;
   z = false;
   a=3;
   b=3;
   c=3;
   mode = NULL;

}

MainWindow::~MainWindow()
{
    delete input;
    delete ui;
}


void MainWindow::createPasswords(int n)
{
    QString path = QApplication::applicationDirPath();
    qDebug() << path;
        if (n == 1){
        this->password.append("1");

        this->password.append("1");

        this->password.append("0");

        this->password.append("0");

        this->password.append("0");

        this->password.append("0");

        this->password.append("0");

        this->password.append("0");

        this->password.append("1");

        this->password.append("0");

        this->password.append("1");

        this->password.append("0");

        this->password.append("1");

        this->password.append("0");

        this->password.append("1");

        this->password.append("1");

        this->password.append("0");

        this->password.append("1");

        this->password.append("1");

        this->password.append("0");

        this->password.append("1");

        QString temp;
            for (int i = 0; i < this->password.length(); i++){
                 temp = temp + this->password.at(i);
            }
        this->ui->output->setText(temp);

        }else if (n == 2){
            this->password2.append("0");
            this->password2.append("1");
            this->password2.append("1");
            this->password2.append("0");
            this->password2.append("1");
            this->password2.append("0");
            this->password2.append("1");
            this->password2.append("0");
            this->password2.append("1");
            this->password2.append("0");
            this->password2.append("0");
            this->password2.append("0");
            this->password2.append("1");
            this->password2.append("0");
            this->password2.append("1");
            this->password2.append("1");
            this->password2.append("0");
            this->password2.append("0");
            this->password2.append("0");
            this->password2.append("1");
            this->password2.append("1");


            QString temp;
                for (int i = 0; i < this->password2.length(); i++){
                     temp = temp + this->password2.at(i);
                }
            this->ui->output->setText(temp);

            }else {
            this->password3.append("0");

            this->password3.append("0");

            this->password3.append("1");

            this->password3.append("0");

            this->password3.append("1");

            this->password3.append("1");

            this->password3.append("1");

            this->password3.append("0");

            this->password3.append("1");

            this->password3.append("0");

            this->password3.append("1");

            this->password3.append("0");

            this->password3.append("1");

            this->password3.append("1");

            this->password3.append("1");

            this->password3.append("0");

            this->password3.append("0");
           ;
            this->password3.append("0");

            this->password3.append("0");

            this->password3.append("1");

            this->password3.append("0");





            }



}





void MainWindow::on_enter_clicked(){
      time_t t = time(0);
    tm* now = localtime(&t);
    timer = now->tm_hour*3600 + now->tm_min *60 + now->tm_sec ;
    this->ui->enter->setEnabled(false);

    this->mode= 3;
    this->ui->info->setText("Please Enter Google Password");
    this->ui->lok->setVisible(true);
    this->ui->pls->setVisible(true);
    this->ui->ok2->setVisible(true);
    this->ui->output->setText("");
    this->ui->p1->setEnabled(true);
    this->ui->p2->setEnabled(true);
    this->ui->p3->setEnabled(true);
    this->ui->p4->setEnabled(true);
    this->ui->p5->setEnabled(true);
    this->ui->p6->setEnabled(true);
    this->ui->p7->setEnabled(true);
    this->ui->p8->setEnabled(true);
    this->ui->p9->setEnabled(true);
    this->ui->p10->setEnabled(true);
    this->ui->p11->setEnabled(true);
    this->ui->p12->setEnabled(true);
    this->ui->p13->setEnabled(true);
    this->ui->p14->setEnabled(true);
    this->ui->p15->setEnabled(true);
    this->ui->p16->setEnabled(true);
    this->ui->p17->setEnabled(true);
    this->ui->p18->setEnabled(true);
    this->ui->p19->setEnabled(true);
    this->ui->p20->setEnabled(true);
    this->ui->p21->setEnabled(true);
    this->ui->p22->setEnabled(true);
    this->ui->p23->setEnabled(true);
    this->ui->p24->setEnabled(true);
    this->ui->p25->setEnabled(true);
    this->ui->p26->setEnabled(true);
    this->ui->p27->setEnabled(true);
    this->ui->p28->setEnabled(true);
    this->ui->p29->setEnabled(true);
    this->ui->p30->setEnabled(true);
    this->ui->p31->setEnabled(true);
    this->ui->p32->setEnabled(true);
    this->ui->p33->setEnabled(true);
    this->ui->p34->setEnabled(true);
    this->ui->p35->setEnabled(true);
    this->ui->p36->setEnabled(true);
    this->ui->p37->setEnabled(true);
    this->ui->p38->setEnabled(true);
    this->ui->p39->setEnabled(true);
    this->ui->p40->setEnabled(true);
    this->ui->p41->setEnabled(true);
    this->ui->p42->setEnabled(true);
    this->ui->p1->setVisible(true);
    this->ui->p2->setVisible(true);
    this->ui->p3->setVisible(true);
    this->ui->p4->setVisible(true);
    this->ui->p5->setVisible(true);
    this->ui->p6->setVisible(true);
    this->ui->p7->setVisible(true);
    this->ui->p8->setVisible(true);
    this->ui->p9->setVisible(true);
    this->ui->p10->setVisible(true);
    this->ui->p11->setVisible(true);
    this->ui->p12->setVisible(true);
    this->ui->p13->setVisible(true);
    this->ui->p14->setVisible(true);
    this->ui->p15->setVisible(true);
    this->ui->p16->setVisible(true);
    this->ui->p17->setVisible(true);
    this->ui->p18->setVisible(true);
    this->ui->p19->setVisible(true);
    this->ui->p20->setVisible(true);
    this->ui->p21->setVisible(true);
    this->ui->p22->setVisible(true);
    this->ui->p23->setVisible(true);
    this->ui->p24->setVisible(true);
    this->ui->p25->setVisible(true);
    this->ui->p26->setVisible(true);
    this->ui->p27->setVisible(true);
    this->ui->p28->setVisible(true);
    this->ui->p29->setVisible(true);
    this->ui->p30->setVisible(true);
    this->ui->p31->setVisible(true);
    this->ui->p32->setVisible(true);
    this->ui->p33->setVisible(true);
    this->ui->p34->setVisible(true);
    this->ui->p35->setVisible(true);
    this->ui->p36->setVisible(true);
    this->ui->p37->setVisible(true);
    this->ui->p38->setVisible(true);
    this->ui->p39->setVisible(true);
    this->ui->p40->setVisible(true);
    this->ui->p41->setVisible(true);
    this->ui->p42->setVisible(true);

}




void MainWindow::on_p1_clicked()
{
    input->insert(0, "1");
    this->ui->p1->setEnabled(false);
    this->ui->p22->setVisible(false);
}

void MainWindow::on_p22_clicked()
{
    input->insert(0, "0");
    this->ui->p22->setEnabled(false);
    this->ui->p1->setVisible(false);
}

void MainWindow::on_p2_clicked()
{
    input->insert(1, "1");
    this->ui->p2->setEnabled(false);
    this->ui->p23->setVisible(false);
}



void MainWindow::on_p23_clicked()
{
    input->insert(1, "0");
    this->ui->p23->setEnabled(false);
    this->ui->p2->setVisible(false);
}



void MainWindow::on_p3_clicked()
{
    input->insert(2, "1");
    this->ui->p3->setEnabled(false);
    this->ui->p24->setVisible(false);
}

void MainWindow::on_p24_clicked()
{
    input->insert(2, "0");
    this->ui->p24->setEnabled(false);
    this->ui->p3->setVisible(false);
}




void MainWindow::on_p4_clicked()
{
    input->insert(3, "1");
    this->ui->p4->setEnabled(false);
    this->ui->p25->setVisible(false);

}




void MainWindow::on_p25_clicked()
{
    input->insert(3, "0");
    this->ui->p25->setEnabled(false);
    this->ui->p4->setVisible(false);

}

void MainWindow::on_p5_clicked()
{
    input->insert(4, "1");
    this->ui->p5->setEnabled(false);
    this->ui->p26->setVisible(false);
}

void MainWindow::on_p26_clicked()
{
    input->insert(4, "0");
    this->ui->p26->setEnabled(false);
    this->ui->p5->setVisible(false);
}

void MainWindow::on_p6_clicked()
{
    input->insert(5, "1");
    this->ui->p6->setEnabled(false);
    this->ui->p27->setVisible(false);
}

void MainWindow::on_p27_clicked()
{
    input->insert(5, "0");
    this->ui->p27->setEnabled(false);
    this->ui->p6->setVisible(false);
}

void MainWindow::on_p7_clicked()
{
    input->insert(6, "1");
    this->ui->p7->setEnabled(false);
    this->ui->p28->setVisible(false);
}

void MainWindow::on_p28_clicked()
{

    input->insert(6, "0");
    this->ui->p28->setEnabled(false);
    this->ui->p7->setVisible(false);
}
void MainWindow::on_p15_clicked()
{
    input->insert(14, "1");
    this->ui->p15->setEnabled(false);
    this->ui->p36->setVisible(false);
}

void MainWindow::on_p36_clicked()
{
    input->insert(14, "0");
    this->ui->p36->setEnabled(false);
    this->ui->p15->setVisible(false);
}

void MainWindow::on_p16_clicked()
{
    input->insert(15, "1");
    this->ui->p16->setEnabled(false);
    this->ui->p37->setVisible(false);
}

void MainWindow::on_p37_clicked()
{
    input->insert(15, "0");
    this->ui->p37->setEnabled(false);
    this->ui->p16->setVisible(false);
}

void MainWindow::on_p17_clicked()
{
    input->insert(16, "1");
    this->ui->p17->setEnabled(false);
    this->ui->p38->setVisible(false);
}

void MainWindow::on_p38_clicked()
{
    input->insert(16, "0");
    this->ui->p38->setEnabled(false);
    this->ui->p17->setVisible(false);
}

void MainWindow::on_p18_clicked()
{
    input->insert(17, "1");
    this->ui->p18->setEnabled(false);
    this->ui->p39->setVisible(false);
}

void MainWindow::on_p39_clicked()
{
    input->insert(17, "0");
    this->ui->p39->setEnabled(false);
    this->ui->p18->setVisible(false);
}

void MainWindow::on_p19_clicked()
{
    input->insert(18, "1");
    this->ui->p19->setEnabled(false);
    this->ui->p40->setVisible(false);
}

void MainWindow::on_p40_clicked()
{
    input->insert(18, "0");
    this->ui->p40->setEnabled(false);
    this->ui->p19->setVisible(false);
}

void MainWindow::on_p20_clicked()
{
    input->insert(19, "1");
    this->ui->p20->setEnabled(false);
    this->ui->p41->setVisible(false);
}

void MainWindow::on_p41_clicked()
{
    input->insert(19, "0");
    this->ui->p41->setEnabled(false);
    this->ui->p20->setVisible(false);
}

void MainWindow::on_p21_clicked()
{
    input->insert(20, "1");
    this->ui->p21->setEnabled(false);
    this->ui->p42->setVisible(false);
}

void MainWindow::on_p42_clicked()
{
    input->insert(20, "0");
    this->ui->p42->setEnabled(false);
    this->ui->p21->setVisible(false);
}



void MainWindow::on_p14_clicked()
{
    input->insert(13, "1");
    this->ui->p14->setEnabled(false);
    this->ui->p35->setVisible(false);
}

void MainWindow::on_p35_clicked()
{
    input->insert(13, "0");
    this->ui->p35->setEnabled(false);
    this->ui->p14->setVisible(false);
}

void MainWindow::on_p13_clicked()
{
    input->insert(12, "1");
    this->ui->p13->setEnabled(false);
    this->ui->p34->setVisible(false);
}

void MainWindow::on_p34_clicked()
{
    input->insert(12, "0");
    this->ui->p34->setEnabled(false);
    this->ui->p13->setVisible(false);
}

void MainWindow::on_p12_clicked()
{
    input->insert(11, "1");
    this->ui->p12->setEnabled(false);
    this->ui->p33->setVisible(false);
}

void MainWindow::on_p33_clicked()
{
    input->insert(11, "0");
    this->ui->p33->setEnabled(false);
    this->ui->p12->setVisible(false);
}

void MainWindow::on_p11_clicked()
{
    input->insert(10, "1");
    this->ui->p11->setEnabled(false);
    this->ui->p32->setVisible(false);
}

void MainWindow::on_p32_clicked()
{
    input->insert(10, "0");
    this->ui->p32->setEnabled(false);
    this->ui->p11->setVisible(false);
}

void MainWindow::on_p8_clicked()
{
    input->insert(7, "1");
    this->ui->p8->setEnabled(false);
    this->ui->p29->setVisible(false);
}


void MainWindow::on_p29_clicked()
{
    input->insert(7, "0");
    this->ui->p29->setEnabled(false);
    this->ui->p8->setVisible(false);
}
void MainWindow::on_p10_clicked()
{
    input->insert(9, "1");
    this->ui->p10->setEnabled(false);
    this->ui->p31->setVisible(false);
}

void MainWindow::on_p31_clicked()
{
    input->insert(9, "0");
    this->ui->p31->setEnabled(false);
    this->ui->p10->setVisible(false);
}

void MainWindow::on_p9_clicked()
{
    input->insert(8, "1");
    this->ui->p9->setEnabled(false);
    this->ui->p30->setVisible(false);
}

void MainWindow::on_p30_clicked()
{
    input->insert(8, "0");
    this->ui->p30->setEnabled(false);
    this->ui->p9->setVisible(false);
}

void MainWindow::on_ok_clicked()
{



    QString temp, guess;
    for (int i = 0; i < 21; i++){
        guess = guess + this->input->at(i);


    }
    if (mode == 1){
        for (int i = 0; i < this->password.length(); i++){
            temp = temp + this->password.at(i);

        }
        if (temp.compare(guess)==0){
            this->ui->success->setText("success");
            x = true;
            this->ui->output->setText("");
            this->ui->lok->setVisible(false);
            this->ui->pls->setVisible(false);
            this->ui->ok->setVisible(false);
            this->ui->ok2->setVisible(false);
            if (x && y && z){

                this->ui->info->setText("");
                this->ui->enter->setEnabled(true);

            }else{
                if (!y){
                    this->ui->pass2->setVisible(true);
                }
                if (!z){

                    this->ui->pass3->setVisible(true);

                }
                this->ui->info->setText("please correctly enter all passwords as pratice to begin");

            }

        }else{
            this->ui->success->setText("wrong");
            this->ui->p1->setEnabled(true);
            this->ui->p2->setEnabled(true);
            this->ui->p3->setEnabled(true);
            this->ui->p4->setEnabled(true);
            this->ui->p5->setEnabled(true);
            this->ui->p6->setEnabled(true);
            this->ui->p7->setEnabled(true);
            this->ui->p8->setEnabled(true);
            this->ui->p9->setEnabled(true);
            this->ui->p10->setEnabled(true);
            this->ui->p11->setEnabled(true);
            this->ui->p12->setEnabled(true);
            this->ui->p13->setEnabled(true);
            this->ui->p14->setEnabled(true);
            this->ui->p15->setEnabled(true);
            this->ui->p16->setEnabled(true);
            this->ui->p17->setEnabled(true);
            this->ui->p18->setEnabled(true);
            this->ui->p19->setEnabled(true);
            this->ui->p20->setEnabled(true);
            this->ui->p21->setEnabled(true);
            this->ui->p22->setEnabled(true);
            this->ui->p23->setEnabled(true);
            this->ui->p24->setEnabled(true);
            this->ui->p25->setEnabled(true);
            this->ui->p26->setEnabled(true);
            this->ui->p27->setEnabled(true);
            this->ui->p28->setEnabled(true);
            this->ui->p29->setEnabled(true);
            this->ui->p30->setEnabled(true);
            this->ui->p31->setEnabled(true);
            this->ui->p32->setEnabled(true);
            this->ui->p33->setEnabled(true);
            this->ui->p34->setEnabled(true);
            this->ui->p35->setEnabled(true);
            this->ui->p36->setEnabled(true);
            this->ui->p37->setEnabled(true);
            this->ui->p38->setEnabled(true);
            this->ui->p39->setEnabled(true);
            this->ui->p40->setEnabled(true);
            this->ui->p41->setEnabled(true);
            this->ui->p42->setEnabled(true);
            this->ui->p1->setVisible(true);
            this->ui->p2->setVisible(true);
            this->ui->p3->setVisible(true);
            this->ui->p4->setVisible(true);
            this->ui->p5->setVisible(true);
            this->ui->p6->setVisible(true);
            this->ui->p7->setVisible(true);
            this->ui->p8->setVisible(true);
            this->ui->p9->setVisible(true);
            this->ui->p10->setVisible(true);
            this->ui->p11->setVisible(true);
            this->ui->p12->setVisible(true);
            this->ui->p13->setVisible(true);
            this->ui->p14->setVisible(true);
            this->ui->p15->setVisible(true);
            this->ui->p16->setVisible(true);
            this->ui->p17->setVisible(true);
            this->ui->p18->setVisible(true);
            this->ui->p19->setVisible(true);
            this->ui->p20->setVisible(true);
            this->ui->p21->setVisible(true);
            this->ui->p22->setVisible(true);
            this->ui->p23->setVisible(true);
            this->ui->p24->setVisible(true);
            this->ui->p25->setVisible(true);
            this->ui->p26->setVisible(true);
            this->ui->p27->setVisible(true);
            this->ui->p28->setVisible(true);
            this->ui->p29->setVisible(true);
            this->ui->p30->setVisible(true);
            this->ui->p31->setVisible(true);
            this->ui->p32->setVisible(true);
            this->ui->p33->setVisible(true);
            this->ui->p34->setVisible(true);
            this->ui->p35->setVisible(true);
            this->ui->p36->setVisible(true);
            this->ui->p37->setVisible(true);
            this->ui->p38->setVisible(true);
            this->ui->p39->setVisible(true);
            this->ui->p40->setVisible(true);
            this->ui->p41->setVisible(true);
            this->ui->p42->setVisible(true);
           this->ui->info->setText("please enter the password correctly for facebook");
        }
    }else if (mode == 2){
        for (int i = 0; i < this->password2.length(); i++){
            temp = temp + this->password2.at(i);

        }
        if (temp.compare(guess)==0){
            this->ui->success->setText("success");
            y = true;
            this->ui->output->setText("");
            this->ui->lok->setVisible(false);
            this->ui->pls->setVisible(false);
            this->ui->ok->setVisible(false);
            this->ui->ok2->setVisible(false);
            if (x && y && z){

                this->ui->info->setText("");
                this->ui->enter->setEnabled(true);

            }else{
                if (!x){
                    this->ui->pass1->setVisible(true);
                }
                if (!z){

                    this->ui->pass3->setVisible(true);

                }this->ui->info->setText("please correctly enter all passwords as pratice to begin");

            }

        }else{
            this->ui->success->setText("wrong");
            this->ui->p1->setEnabled(true);
            this->ui->p2->setEnabled(true);
            this->ui->p3->setEnabled(true);
            this->ui->p4->setEnabled(true);
            this->ui->p5->setEnabled(true);
            this->ui->p6->setEnabled(true);
            this->ui->p7->setEnabled(true);
            this->ui->p8->setEnabled(true);
            this->ui->p9->setEnabled(true);
            this->ui->p10->setEnabled(true);
            this->ui->p11->setEnabled(true);
            this->ui->p12->setEnabled(true);
            this->ui->p13->setEnabled(true);
            this->ui->p14->setEnabled(true);
            this->ui->p15->setEnabled(true);
            this->ui->p16->setEnabled(true);
            this->ui->p17->setEnabled(true);
            this->ui->p18->setEnabled(true);
            this->ui->p19->setEnabled(true);
            this->ui->p20->setEnabled(true);
            this->ui->p21->setEnabled(true);
            this->ui->p22->setEnabled(true);
            this->ui->p23->setEnabled(true);
            this->ui->p24->setEnabled(true);
            this->ui->p25->setEnabled(true);
            this->ui->p26->setEnabled(true);
            this->ui->p27->setEnabled(true);
            this->ui->p28->setEnabled(true);
            this->ui->p29->setEnabled(true);
            this->ui->p30->setEnabled(true);
            this->ui->p31->setEnabled(true);
            this->ui->p32->setEnabled(true);
            this->ui->p33->setEnabled(true);
            this->ui->p34->setEnabled(true);
            this->ui->p35->setEnabled(true);
            this->ui->p36->setEnabled(true);
            this->ui->p37->setEnabled(true);
            this->ui->p38->setEnabled(true);
            this->ui->p39->setEnabled(true);
            this->ui->p40->setEnabled(true);
            this->ui->p41->setEnabled(true);
            this->ui->p42->setEnabled(true);
            this->ui->p1->setVisible(true);
            this->ui->p2->setVisible(true);
            this->ui->p3->setVisible(true);
            this->ui->p4->setVisible(true);
            this->ui->p5->setVisible(true);
            this->ui->p6->setVisible(true);
            this->ui->p7->setVisible(true);
            this->ui->p8->setVisible(true);
            this->ui->p9->setVisible(true);
            this->ui->p10->setVisible(true);
            this->ui->p11->setVisible(true);
            this->ui->p12->setVisible(true);
            this->ui->p13->setVisible(true);
            this->ui->p14->setVisible(true);
            this->ui->p15->setVisible(true);
            this->ui->p16->setVisible(true);
            this->ui->p17->setVisible(true);
            this->ui->p18->setVisible(true);
            this->ui->p19->setVisible(true);
            this->ui->p20->setVisible(true);
            this->ui->p21->setVisible(true);
            this->ui->p22->setVisible(true);
            this->ui->p23->setVisible(true);
            this->ui->p24->setVisible(true);
            this->ui->p25->setVisible(true);
            this->ui->p26->setVisible(true);
            this->ui->p27->setVisible(true);
            this->ui->p28->setVisible(true);
            this->ui->p29->setVisible(true);
            this->ui->p30->setVisible(true);
            this->ui->p31->setVisible(true);
            this->ui->p32->setVisible(true);
            this->ui->p33->setVisible(true);
            this->ui->p34->setVisible(true);
            this->ui->p35->setVisible(true);
            this->ui->p36->setVisible(true);
            this->ui->p37->setVisible(true);
            this->ui->p38->setVisible(true);
            this->ui->p39->setVisible(true);
            this->ui->p40->setVisible(true);
            this->ui->p41->setVisible(true);
            this->ui->p42->setVisible(true);
           this->ui->info->setText("please enter the password correctly for instagram");
        }
    }else{
        for (int i = 0; i < this->password3.length(); i++){
            temp = temp + this->password3.at(i);

        }
        if (temp.compare(guess)==0){
            this->ui->success->setText("success");
            z = true;
            this->ui->output->setText("");
            this->ui->lok->setVisible(false);
            this->ui->pls->setVisible(false);
            this->ui->ok->setVisible(false);
            this->ui->ok2->setVisible(false);
            if (x && y && z){

                this->ui->info->setText("");
                this->ui->enter->setEnabled(true);

            }else{
                if (!x){
                    this->ui->pass1->setVisible(true);
                }
                if (!y){

                    this->ui->pass2->setVisible(true);

                }
                this->ui->info->setText("please correctly enter all passwords as pratice to begin");
            }

        }else{
            this->ui->success->setText("wrong");
            this->ui->p1->setEnabled(true);
            this->ui->p2->setEnabled(true);
            this->ui->p3->setEnabled(true);
            this->ui->p4->setEnabled(true);
            this->ui->p5->setEnabled(true);
            this->ui->p6->setEnabled(true);
            this->ui->p7->setEnabled(true);
            this->ui->p8->setEnabled(true);
            this->ui->p9->setEnabled(true);
            this->ui->p10->setEnabled(true);
            this->ui->p11->setEnabled(true);
            this->ui->p12->setEnabled(true);
            this->ui->p13->setEnabled(true);
            this->ui->p14->setEnabled(true);
            this->ui->p15->setEnabled(true);
            this->ui->p16->setEnabled(true);
            this->ui->p17->setEnabled(true);
            this->ui->p18->setEnabled(true);
            this->ui->p19->setEnabled(true);
            this->ui->p20->setEnabled(true);
            this->ui->p21->setEnabled(true);
            this->ui->p22->setEnabled(true);
            this->ui->p23->setEnabled(true);
            this->ui->p24->setEnabled(true);
            this->ui->p25->setEnabled(true);
            this->ui->p26->setEnabled(true);
            this->ui->p27->setEnabled(true);
            this->ui->p28->setEnabled(true);
            this->ui->p29->setEnabled(true);
            this->ui->p30->setEnabled(true);
            this->ui->p31->setEnabled(true);
            this->ui->p32->setEnabled(true);
            this->ui->p33->setEnabled(true);
            this->ui->p34->setEnabled(true);
            this->ui->p35->setEnabled(true);
            this->ui->p36->setEnabled(true);
            this->ui->p37->setEnabled(true);
            this->ui->p38->setEnabled(true);
            this->ui->p39->setEnabled(true);
            this->ui->p40->setEnabled(true);
            this->ui->p41->setEnabled(true);
            this->ui->p42->setEnabled(true);
            this->ui->p1->setVisible(true);
            this->ui->p2->setVisible(true);
            this->ui->p3->setVisible(true);
            this->ui->p4->setVisible(true);
            this->ui->p5->setVisible(true);
            this->ui->p6->setVisible(true);
            this->ui->p7->setVisible(true);
            this->ui->p8->setVisible(true);
            this->ui->p9->setVisible(true);
            this->ui->p10->setVisible(true);
            this->ui->p11->setVisible(true);
            this->ui->p12->setVisible(true);
            this->ui->p13->setVisible(true);
            this->ui->p14->setVisible(true);
            this->ui->p15->setVisible(true);
            this->ui->p16->setVisible(true);
            this->ui->p17->setVisible(true);
            this->ui->p18->setVisible(true);
            this->ui->p19->setVisible(true);
            this->ui->p20->setVisible(true);
            this->ui->p21->setVisible(true);
            this->ui->p22->setVisible(true);
            this->ui->p23->setVisible(true);
            this->ui->p24->setVisible(true);
            this->ui->p25->setVisible(true);
            this->ui->p26->setVisible(true);
            this->ui->p27->setVisible(true);
            this->ui->p28->setVisible(true);
            this->ui->p29->setVisible(true);
            this->ui->p30->setVisible(true);
            this->ui->p31->setVisible(true);
            this->ui->p32->setVisible(true);
            this->ui->p33->setVisible(true);
            this->ui->p34->setVisible(true);
            this->ui->p35->setVisible(true);
            this->ui->p36->setVisible(true);
            this->ui->p37->setVisible(true);
            this->ui->p38->setVisible(true);
            this->ui->p39->setVisible(true);
            this->ui->p40->setVisible(true);
            this->ui->p41->setVisible(true);
            this->ui->p42->setVisible(true);
           this->ui->info->setText("please enter the password correctly for google");
        }
    }
}

void MainWindow::on_next_clicked()
{QString name = "data";
QString s = (name.prepend(qApp->applicationDirPath())).append(".csv");
QFile outFile(s);

if (outFile.open(QFile::WriteOnly|QFile::Truncate))
{
   QTextStream stream(&outFile);
    stream << a << "\n"<< b << "\n"<< c << "\n"<< o << "\n"<< p << "\n"<< q << "\n"<< r << "\n"<< s << "\n"<< t << "\n";
    qDebug() << a << "\n"<< b << "\n"<< c << "\n"<< o << "\n"<< p << "\n"<< q << "\n"<< r << "\n"<< s << "\n"<< t << "\n";
    outFile.close();

}
    MainWindow *w = new MainWindow();
    w->show();
    delete this;

}

void MainWindow::on_start_clicked()
{
   this->ui->start->setVisible(false);
   this->ui->info->setText("please correctly enter all passwords as pratice to begin");
}

void MainWindow::on_pass1_clicked()
{input->fill("", 21);
    this->mode = 1;
    this->ui->lok->setVisible(true);
    this->ui->pls->setVisible(true);
    this->ui->ok->setVisible(true);
    this->ui->p1->setEnabled(true);
    this->ui->p2->setEnabled(true);
    this->ui->p3->setEnabled(true);
    this->ui->p4->setEnabled(true);
    this->ui->p5->setEnabled(true);
    this->ui->p6->setEnabled(true);
    this->ui->p7->setEnabled(true);
    this->ui->p8->setEnabled(true);
    this->ui->p9->setEnabled(true);
    this->ui->p10->setEnabled(true);
    this->ui->p11->setEnabled(true);
    this->ui->p12->setEnabled(true);
    this->ui->p13->setEnabled(true);
    this->ui->p14->setEnabled(true);
    this->ui->p15->setEnabled(true);
    this->ui->p16->setEnabled(true);
    this->ui->p17->setEnabled(true);
    this->ui->p18->setEnabled(true);
    this->ui->p19->setEnabled(true);
    this->ui->p20->setEnabled(true);
    this->ui->p21->setEnabled(true);
    this->ui->p22->setEnabled(true);
    this->ui->p23->setEnabled(true);
    this->ui->p24->setEnabled(true);
    this->ui->p25->setEnabled(true);
    this->ui->p26->setEnabled(true);
    this->ui->p27->setEnabled(true);
    this->ui->p28->setEnabled(true);
    this->ui->p29->setEnabled(true);
    this->ui->p30->setEnabled(true);
    this->ui->p31->setEnabled(true);
    this->ui->p32->setEnabled(true);
    this->ui->p33->setEnabled(true);
    this->ui->p34->setEnabled(true);
    this->ui->p35->setEnabled(true);
    this->ui->p36->setEnabled(true);
    this->ui->p37->setEnabled(true);
    this->ui->p38->setEnabled(true);
    this->ui->p39->setEnabled(true);
    this->ui->p40->setEnabled(true);
    this->ui->p41->setEnabled(true);
    this->ui->p42->setEnabled(true);
    this->ui->p1->setVisible(true);
    this->ui->p2->setVisible(true);
    this->ui->p3->setVisible(true);
    this->ui->p4->setVisible(true);
    this->ui->p5->setVisible(true);
    this->ui->p6->setVisible(true);
    this->ui->p7->setVisible(true);
    this->ui->p8->setVisible(true);
    this->ui->p9->setVisible(true);
    this->ui->p10->setVisible(true);
    this->ui->p11->setVisible(true);
    this->ui->p12->setVisible(true);
    this->ui->p13->setVisible(true);
    this->ui->p14->setVisible(true);
    this->ui->p15->setVisible(true);
    this->ui->p16->setVisible(true);
    this->ui->p17->setVisible(true);
    this->ui->p18->setVisible(true);
    this->ui->p19->setVisible(true);
    this->ui->p20->setVisible(true);
    this->ui->p21->setVisible(true);
    this->ui->p22->setVisible(true);
    this->ui->p23->setVisible(true);
    this->ui->p24->setVisible(true);
    this->ui->p25->setVisible(true);
    this->ui->p26->setVisible(true);
    this->ui->p27->setVisible(true);
    this->ui->p28->setVisible(true);
    this->ui->p29->setVisible(true);
    this->ui->p30->setVisible(true);
    this->ui->p31->setVisible(true);
    this->ui->p32->setVisible(true);
    this->ui->p33->setVisible(true);
    this->ui->p34->setVisible(true);
    this->ui->p35->setVisible(true);
    this->ui->p36->setVisible(true);
    this->ui->p37->setVisible(true);
    this->ui->p38->setVisible(true);
    this->ui->p39->setVisible(true);
    this->ui->p40->setVisible(true);
    this->ui->p41->setVisible(true);
    this->ui->p42->setVisible(true);
    this->ui->pass1->setVisible(false);
    this->ui->pass2->setVisible(false);
    this->ui->pass3->setVisible(false);
    this->ui->info->setText("enter password for facebook->");
    createPasswords(1);
    QString temp;
        for (int i = 0; i < this->password.length(); i++){
             temp = temp + this->password.at(i);
        }
    this->ui->output->setText(temp);
}

void MainWindow::on_pass2_clicked()
{input->fill("", 21);
    this->mode = 2;
    this->ui->ok->setVisible(true);
    this->ui->lok->setVisible(true);
    this->ui->pls->setVisible(true);
    this->ui->p1->setEnabled(true);
    this->ui->p2->setEnabled(true);
    this->ui->p3->setEnabled(true);
    this->ui->p4->setEnabled(true);
    this->ui->p5->setEnabled(true);
    this->ui->p6->setEnabled(true);
    this->ui->p7->setEnabled(true);
    this->ui->p8->setEnabled(true);
    this->ui->p9->setEnabled(true);
    this->ui->p10->setEnabled(true);
    this->ui->p11->setEnabled(true);
    this->ui->p12->setEnabled(true);
    this->ui->p13->setEnabled(true);
    this->ui->p14->setEnabled(true);
    this->ui->p15->setEnabled(true);
    this->ui->p16->setEnabled(true);
    this->ui->p17->setEnabled(true);
    this->ui->p18->setEnabled(true);
    this->ui->p19->setEnabled(true);
    this->ui->p20->setEnabled(true);
    this->ui->p21->setEnabled(true);
    this->ui->p22->setEnabled(true);
    this->ui->p23->setEnabled(true);
    this->ui->p24->setEnabled(true);
    this->ui->p25->setEnabled(true);
    this->ui->p26->setEnabled(true);
    this->ui->p27->setEnabled(true);
    this->ui->p28->setEnabled(true);
    this->ui->p29->setEnabled(true);
    this->ui->p30->setEnabled(true);
    this->ui->p31->setEnabled(true);
    this->ui->p32->setEnabled(true);
    this->ui->p33->setEnabled(true);
    this->ui->p34->setEnabled(true);
    this->ui->p35->setEnabled(true);
    this->ui->p36->setEnabled(true);
    this->ui->p37->setEnabled(true);
    this->ui->p38->setEnabled(true);
    this->ui->p39->setEnabled(true);
    this->ui->p40->setEnabled(true);
    this->ui->p41->setEnabled(true);
    this->ui->p42->setEnabled(true);
    this->ui->p1->setVisible(true);
    this->ui->p2->setVisible(true);
    this->ui->p3->setVisible(true);
    this->ui->p4->setVisible(true);
    this->ui->p5->setVisible(true);
    this->ui->p6->setVisible(true);
    this->ui->p7->setVisible(true);
    this->ui->p8->setVisible(true);
    this->ui->p9->setVisible(true);
    this->ui->p10->setVisible(true);
    this->ui->p11->setVisible(true);
    this->ui->p12->setVisible(true);
    this->ui->p13->setVisible(true);
    this->ui->p14->setVisible(true);
    this->ui->p15->setVisible(true);
    this->ui->p16->setVisible(true);
    this->ui->p17->setVisible(true);
    this->ui->p18->setVisible(true);
    this->ui->p19->setVisible(true);
    this->ui->p20->setVisible(true);
    this->ui->p21->setVisible(true);
    this->ui->p22->setVisible(true);
    this->ui->p23->setVisible(true);
    this->ui->p24->setVisible(true);
    this->ui->p25->setVisible(true);
    this->ui->p26->setVisible(true);
    this->ui->p27->setVisible(true);
    this->ui->p28->setVisible(true);
    this->ui->p29->setVisible(true);
    this->ui->p30->setVisible(true);
    this->ui->p31->setVisible(true);
    this->ui->p32->setVisible(true);
    this->ui->p33->setVisible(true);
    this->ui->p34->setVisible(true);
    this->ui->p35->setVisible(true);
    this->ui->p36->setVisible(true);
    this->ui->p37->setVisible(true);
    this->ui->p38->setVisible(true);
    this->ui->p39->setVisible(true);
    this->ui->p40->setVisible(true);
    this->ui->p41->setVisible(true);
    this->ui->p42->setVisible(true);
    this->ui->pass1->setVisible(false);
    this->ui->pass2->setVisible(false);
    this->ui->pass3->setVisible(false);
    this->ui->info->setText("enter password for instagram->");
    createPasswords(2);
    QString temp;
        for (int i = 0; i < this->password2.length(); i++){
             temp = temp + this->password2.at(i);
        }
    this->ui->output->setText(temp);
}

void MainWindow::on_pass3_clicked()
{input->fill("", 21);
    this->mode = 3;
    this->ui->ok->setVisible(true);
    this->ui->lok->setVisible(true);
    this->ui->pls->setVisible(true);
    this->ui->p1->setEnabled(true);
    this->ui->p2->setEnabled(true);
    this->ui->p3->setEnabled(true);
    this->ui->p4->setEnabled(true);
    this->ui->p5->setEnabled(true);
    this->ui->p6->setEnabled(true);
    this->ui->p7->setEnabled(true);
    this->ui->p8->setEnabled(true);
    this->ui->p9->setEnabled(true);
    this->ui->p10->setEnabled(true);
    this->ui->p11->setEnabled(true);
    this->ui->p12->setEnabled(true);
    this->ui->p13->setEnabled(true);
    this->ui->p14->setEnabled(true);
    this->ui->p15->setEnabled(true);
    this->ui->p16->setEnabled(true);
    this->ui->p17->setEnabled(true);
    this->ui->p18->setEnabled(true);
    this->ui->p19->setEnabled(true);
    this->ui->p20->setEnabled(true);
    this->ui->p21->setEnabled(true);
    this->ui->p22->setEnabled(true);
    this->ui->p23->setEnabled(true);
    this->ui->p24->setEnabled(true);
    this->ui->p25->setEnabled(true);
    this->ui->p26->setEnabled(true);
    this->ui->p27->setEnabled(true);
    this->ui->p28->setEnabled(true);
    this->ui->p29->setEnabled(true);
    this->ui->p30->setEnabled(true);
    this->ui->p31->setEnabled(true);
    this->ui->p32->setEnabled(true);
    this->ui->p33->setEnabled(true);
    this->ui->p34->setEnabled(true);
    this->ui->p35->setEnabled(true);
    this->ui->p36->setEnabled(true);
    this->ui->p37->setEnabled(true);
    this->ui->p38->setEnabled(true);
    this->ui->p39->setEnabled(true);
    this->ui->p40->setEnabled(true);
    this->ui->p41->setEnabled(true);
    this->ui->p42->setEnabled(true);
    this->ui->p1->setVisible(true);
    this->ui->p2->setVisible(true);
    this->ui->p3->setVisible(true);
    this->ui->p4->setVisible(true);
    this->ui->p5->setVisible(true);
    this->ui->p6->setVisible(true);
    this->ui->p7->setVisible(true);
    this->ui->p8->setVisible(true);
    this->ui->p9->setVisible(true);
    this->ui->p10->setVisible(true);
    this->ui->p11->setVisible(true);
    this->ui->p12->setVisible(true);
    this->ui->p13->setVisible(true);
    this->ui->p14->setVisible(true);
    this->ui->p15->setVisible(true);
    this->ui->p16->setVisible(true);
    this->ui->p17->setVisible(true);
    this->ui->p18->setVisible(true);
    this->ui->p19->setVisible(true);
    this->ui->p20->setVisible(true);
    this->ui->p21->setVisible(true);
    this->ui->p22->setVisible(true);
    this->ui->p23->setVisible(true);
    this->ui->p24->setVisible(true);
    this->ui->p25->setVisible(true);
    this->ui->p26->setVisible(true);
    this->ui->p27->setVisible(true);
    this->ui->p28->setVisible(true);
    this->ui->p29->setVisible(true);
    this->ui->p30->setVisible(true);
    this->ui->p31->setVisible(true);
    this->ui->p32->setVisible(true);
    this->ui->p33->setVisible(true);
    this->ui->p34->setVisible(true);
    this->ui->p35->setVisible(true);
    this->ui->p36->setVisible(true);
    this->ui->p37->setVisible(true);
    this->ui->p38->setVisible(true);
    this->ui->p39->setVisible(true);
    this->ui->p40->setVisible(true);
    this->ui->p41->setVisible(true);
    this->ui->p42->setVisible(true);
    this->ui->pass1->setVisible(false);
    this->ui->pass2->setVisible(false);
    this->ui->pass3->setVisible(false);
    this->ui->info->setText("enter password for google->");
    createPasswords(3);

    QString temp;
        for (int i = 0; i < this->password3.length(); i++){
             temp = temp + this->password3.at(i);
        }
    this->ui->output->setText(temp);

}

void MainWindow::on_ok2_clicked()
{
    QString temp, guess;
    for (int i = 0; i < 21; i++){
        guess = guess + this->input->at(i);


    }
    if (mode == 3){
        for (int i = 0; i < this->password3.length(); i++){
            temp = temp + this->password3.at(i);

        }
        if (temp.compare(guess)==0){
            this->ui->success->setText("success");
            this->ui->output->setText("");
             time_t t = time(0);
            tm * now = localtime(&t);
            timer =  (now->tm_hour*3600 + now->tm_min *60 + now->tm_sec)-timer;
            q = timer;
            t = 0;
            face();
        }else{
            c--;
            if(c == 0){
               this->ui->success->setText("failure");
                  this->ui->output->setText("");
                time_t t = time(0);
               tm * now = localtime(&t);
               timer =  (now->tm_hour*3600 + now->tm_min *60 + now->tm_sec)-timer;
               q = timer;
                t = -1;
                 face();

            }else{
            this->ui->success->setText("wrong");
            this->ui->p1->setEnabled(true);
            this->ui->p2->setEnabled(true);
            this->ui->p3->setEnabled(true);
            this->ui->p4->setEnabled(true);
            this->ui->p5->setEnabled(true);
            this->ui->p6->setEnabled(true);
            this->ui->p7->setEnabled(true);
            this->ui->p8->setEnabled(true);
            this->ui->p9->setEnabled(true);
            this->ui->p10->setEnabled(true);
            this->ui->p11->setEnabled(true);
            this->ui->p12->setEnabled(true);
            this->ui->p13->setEnabled(true);
            this->ui->p14->setEnabled(true);
            this->ui->p15->setEnabled(true);
            this->ui->p16->setEnabled(true);
            this->ui->p17->setEnabled(true);
            this->ui->p18->setEnabled(true);
            this->ui->p19->setEnabled(true);
            this->ui->p20->setEnabled(true);
            this->ui->p21->setEnabled(true);
            this->ui->p22->setEnabled(true);
            this->ui->p23->setEnabled(true);
            this->ui->p24->setEnabled(true);
            this->ui->p25->setEnabled(true);
            this->ui->p26->setEnabled(true);
            this->ui->p27->setEnabled(true);
            this->ui->p28->setEnabled(true);
            this->ui->p29->setEnabled(true);
            this->ui->p30->setEnabled(true);
            this->ui->p31->setEnabled(true);
            this->ui->p32->setEnabled(true);
            this->ui->p33->setEnabled(true);
            this->ui->p34->setEnabled(true);
            this->ui->p35->setEnabled(true);
            this->ui->p36->setEnabled(true);
            this->ui->p37->setEnabled(true);
            this->ui->p38->setEnabled(true);
            this->ui->p39->setEnabled(true);
            this->ui->p40->setEnabled(true);
            this->ui->p41->setEnabled(true);
            this->ui->p42->setEnabled(true);
            this->ui->p1->setVisible(true);
            this->ui->p2->setVisible(true);
            this->ui->p3->setVisible(true);
            this->ui->p4->setVisible(true);
            this->ui->p5->setVisible(true);
            this->ui->p6->setVisible(true);
            this->ui->p7->setVisible(true);
            this->ui->p8->setVisible(true);
            this->ui->p9->setVisible(true);
            this->ui->p10->setVisible(true);
            this->ui->p11->setVisible(true);
            this->ui->p12->setVisible(true);
            this->ui->p13->setVisible(true);
            this->ui->p14->setVisible(true);
            this->ui->p15->setVisible(true);
            this->ui->p16->setVisible(true);
            this->ui->p17->setVisible(true);
            this->ui->p18->setVisible(true);
            this->ui->p19->setVisible(true);
            this->ui->p20->setVisible(true);
            this->ui->p21->setVisible(true);
            this->ui->p22->setVisible(true);
            this->ui->p23->setVisible(true);
            this->ui->p24->setVisible(true);
            this->ui->p25->setVisible(true);
            this->ui->p26->setVisible(true);
            this->ui->p27->setVisible(true);
            this->ui->p28->setVisible(true);
            this->ui->p29->setVisible(true);
            this->ui->p30->setVisible(true);
            this->ui->p31->setVisible(true);
            this->ui->p32->setVisible(true);
            this->ui->p33->setVisible(true);
            this->ui->p34->setVisible(true);
            this->ui->p35->setVisible(true);
            this->ui->p36->setVisible(true);
            this->ui->p37->setVisible(true);
            this->ui->p38->setVisible(true);
            this->ui->p39->setVisible(true);
            this->ui->p40->setVisible(true);
            this->ui->p41->setVisible(true);
            this->ui->p42->setVisible(true);
           this->ui->info->setText("pls try again for google, you have" + QString::number(c) + "tries left");}
        }
    }else if (mode == 2){
        for (int i = 0; i < this->password2.length(); i++){
            temp = temp + this->password2.at(i);

        }
        if (temp.compare(guess)==0){
            this->ui->success->setText("success");
            this->ui->output->setText("");
             time_t t = time(0);
            tm * now = localtime(&t);
            timer =  (now->tm_hour*3600 + now->tm_min *60 + now->tm_sec)-timer;
            p = timer;
            s = 0;
             this->ui->ok2->setEnabled(false);
            this->ui->next->setEnabled(true);
        }else{
            b--;
            if(b == 0){
               this->ui->success->setText("failure");


                time_t t = time(0);
               tm * now = localtime(&t);
               timer =  (now->tm_hour*3600 + now->tm_min *60 + now->tm_sec)-timer;
               p = timer;
               s = -1;

                this->ui->next->setEnabled(true);
                this->ui->ok2->setEnabled(false);
            }else{
            this->ui->success->setText("wrong");
            this->ui->p1->setEnabled(true);
            this->ui->p2->setEnabled(true);
            this->ui->p3->setEnabled(true);
            this->ui->p4->setEnabled(true);
            this->ui->p5->setEnabled(true);
            this->ui->p6->setEnabled(true);
            this->ui->p7->setEnabled(true);
            this->ui->p8->setEnabled(true);
            this->ui->p9->setEnabled(true);
            this->ui->p10->setEnabled(true);
            this->ui->p11->setEnabled(true);
            this->ui->p12->setEnabled(true);
            this->ui->p13->setEnabled(true);
            this->ui->p14->setEnabled(true);
            this->ui->p15->setEnabled(true);
            this->ui->p16->setEnabled(true);
            this->ui->p17->setEnabled(true);
            this->ui->p18->setEnabled(true);
            this->ui->p19->setEnabled(true);
            this->ui->p20->setEnabled(true);
            this->ui->p21->setEnabled(true);
            this->ui->p22->setEnabled(true);
            this->ui->p23->setEnabled(true);
            this->ui->p24->setEnabled(true);
            this->ui->p25->setEnabled(true);
            this->ui->p26->setEnabled(true);
            this->ui->p27->setEnabled(true);
            this->ui->p28->setEnabled(true);
            this->ui->p29->setEnabled(true);
            this->ui->p30->setEnabled(true);
            this->ui->p31->setEnabled(true);
            this->ui->p32->setEnabled(true);
            this->ui->p33->setEnabled(true);
            this->ui->p34->setEnabled(true);
            this->ui->p35->setEnabled(true);
            this->ui->p36->setEnabled(true);
            this->ui->p37->setEnabled(true);
            this->ui->p38->setEnabled(true);
            this->ui->p39->setEnabled(true);
            this->ui->p40->setEnabled(true);
            this->ui->p41->setEnabled(true);
            this->ui->p42->setEnabled(true);
            this->ui->p1->setVisible(true);
            this->ui->p2->setVisible(true);
            this->ui->p3->setVisible(true);
            this->ui->p4->setVisible(true);
            this->ui->p5->setVisible(true);
            this->ui->p6->setVisible(true);
            this->ui->p7->setVisible(true);
            this->ui->p8->setVisible(true);
            this->ui->p9->setVisible(true);
            this->ui->p10->setVisible(true);
            this->ui->p11->setVisible(true);
            this->ui->p12->setVisible(true);
            this->ui->p13->setVisible(true);
            this->ui->p14->setVisible(true);
            this->ui->p15->setVisible(true);
            this->ui->p16->setVisible(true);
            this->ui->p17->setVisible(true);
            this->ui->p18->setVisible(true);
            this->ui->p19->setVisible(true);
            this->ui->p20->setVisible(true);
            this->ui->p21->setVisible(true);
            this->ui->p22->setVisible(true);
            this->ui->p23->setVisible(true);
            this->ui->p24->setVisible(true);
            this->ui->p25->setVisible(true);
            this->ui->p26->setVisible(true);
            this->ui->p27->setVisible(true);
            this->ui->p28->setVisible(true);
            this->ui->p29->setVisible(true);
            this->ui->p30->setVisible(true);
            this->ui->p31->setVisible(true);
            this->ui->p32->setVisible(true);
            this->ui->p33->setVisible(true);
            this->ui->p34->setVisible(true);
            this->ui->p35->setVisible(true);
            this->ui->p36->setVisible(true);
            this->ui->p37->setVisible(true);
            this->ui->p38->setVisible(true);
            this->ui->p39->setVisible(true);
            this->ui->p40->setVisible(true);
            this->ui->p41->setVisible(true);
            this->ui->p42->setVisible(true);
           this->ui->info->setText("pls try again for instagram, you have" + QString::number(b) + "tries left");}
        }
    }else{
        for (int i = 0; i < this->password.length(); i++){
            temp = temp + this->password.at(i);

        }
        if (temp.compare(guess)==0){
            this->ui->success->setText("success");
            this->ui->output->setText("");
             time_t t = time(0);
            tm * now = localtime(&t);
            timer =  (now->tm_hour*3600 + now->tm_min *60 + now->tm_sec)-timer;
            o = timer;
            r = 0;
            insta();
        }else{
            a--;
            if(a == 0){
               this->ui->success->setText("failure");
                this->ui->output->setText("");
                time_t t = time(0);
               tm * now = localtime(&t);
               timer =  (now->tm_hour*3600 + now->tm_min *60 + now->tm_sec)-timer;
               o = timer;
               r = -1;

               insta();

            }else{
            this->ui->success->setText("wrong");
            this->ui->p1->setEnabled(true);
            this->ui->p2->setEnabled(true);
            this->ui->p3->setEnabled(true);
            this->ui->p4->setEnabled(true);
            this->ui->p5->setEnabled(true);
            this->ui->p6->setEnabled(true);
            this->ui->p7->setEnabled(true);
            this->ui->p8->setEnabled(true);
            this->ui->p9->setEnabled(true);
            this->ui->p10->setEnabled(true);
            this->ui->p11->setEnabled(true);
            this->ui->p12->setEnabled(true);
            this->ui->p13->setEnabled(true);
            this->ui->p14->setEnabled(true);
            this->ui->p15->setEnabled(true);
            this->ui->p16->setEnabled(true);
            this->ui->p17->setEnabled(true);
            this->ui->p18->setEnabled(true);
            this->ui->p19->setEnabled(true);
            this->ui->p20->setEnabled(true);
            this->ui->p21->setEnabled(true);
            this->ui->p22->setEnabled(true);
            this->ui->p23->setEnabled(true);
            this->ui->p24->setEnabled(true);
            this->ui->p25->setEnabled(true);
            this->ui->p26->setEnabled(true);
            this->ui->p27->setEnabled(true);
            this->ui->p28->setEnabled(true);
            this->ui->p29->setEnabled(true);
            this->ui->p30->setEnabled(true);
            this->ui->p31->setEnabled(true);
            this->ui->p32->setEnabled(true);
            this->ui->p33->setEnabled(true);
            this->ui->p34->setEnabled(true);
            this->ui->p35->setEnabled(true);
            this->ui->p36->setEnabled(true);
            this->ui->p37->setEnabled(true);
            this->ui->p38->setEnabled(true);
            this->ui->p39->setEnabled(true);
            this->ui->p40->setEnabled(true);
            this->ui->p41->setEnabled(true);
            this->ui->p42->setEnabled(true);
            this->ui->p1->setVisible(true);
            this->ui->p2->setVisible(true);
            this->ui->p3->setVisible(true);
            this->ui->p4->setVisible(true);
            this->ui->p5->setVisible(true);
            this->ui->p6->setVisible(true);
            this->ui->p7->setVisible(true);
            this->ui->p8->setVisible(true);
            this->ui->p9->setVisible(true);
            this->ui->p10->setVisible(true);
            this->ui->p11->setVisible(true);
            this->ui->p12->setVisible(true);
            this->ui->p13->setVisible(true);
            this->ui->p14->setVisible(true);
            this->ui->p15->setVisible(true);
            this->ui->p16->setVisible(true);
            this->ui->p17->setVisible(true);
            this->ui->p18->setVisible(true);
            this->ui->p19->setVisible(true);
            this->ui->p20->setVisible(true);
            this->ui->p21->setVisible(true);
            this->ui->p22->setVisible(true);
            this->ui->p23->setVisible(true);
            this->ui->p24->setVisible(true);
            this->ui->p25->setVisible(true);
            this->ui->p26->setVisible(true);
            this->ui->p27->setVisible(true);
            this->ui->p28->setVisible(true);
            this->ui->p29->setVisible(true);
            this->ui->p30->setVisible(true);
            this->ui->p31->setVisible(true);
            this->ui->p32->setVisible(true);
            this->ui->p33->setVisible(true);
            this->ui->p34->setVisible(true);
            this->ui->p35->setVisible(true);
            this->ui->p36->setVisible(true);
            this->ui->p37->setVisible(true);
            this->ui->p38->setVisible(true);
            this->ui->p39->setVisible(true);
            this->ui->p40->setVisible(true);
            this->ui->p41->setVisible(true);
            this->ui->p42->setVisible(true);
           this->ui->info->setText("pls try again for facebook, you have" + QString::number(a) + "tries left");}
        }
    }
}

void MainWindow::face(){
    time_t t = time(0);
  tm* now = localtime(&t);
  timer = now->tm_hour*3600 + now->tm_min *60 + now->tm_sec ;
input->fill("", 21);

  this->mode= 1;
  this->ui->info->setText("Please Enter Facebook Password");
  this->ui->lok->setVisible(true);
  this->ui->pls->setVisible(true);
  this->ui->ok2->setVisible(true);
  this->ui->output->setText("");
  this->ui->p1->setEnabled(true);
  this->ui->p2->setEnabled(true);
  this->ui->p3->setEnabled(true);
  this->ui->p4->setEnabled(true);
  this->ui->p5->setEnabled(true);
  this->ui->p6->setEnabled(true);
  this->ui->p7->setEnabled(true);
  this->ui->p8->setEnabled(true);
  this->ui->p9->setEnabled(true);
  this->ui->p10->setEnabled(true);
  this->ui->p11->setEnabled(true);
  this->ui->p12->setEnabled(true);
  this->ui->p13->setEnabled(true);
  this->ui->p14->setEnabled(true);
  this->ui->p15->setEnabled(true);
  this->ui->p16->setEnabled(true);
  this->ui->p17->setEnabled(true);
  this->ui->p18->setEnabled(true);
  this->ui->p19->setEnabled(true);
  this->ui->p20->setEnabled(true);
  this->ui->p21->setEnabled(true);
  this->ui->p22->setEnabled(true);
  this->ui->p23->setEnabled(true);
  this->ui->p24->setEnabled(true);
  this->ui->p25->setEnabled(true);
  this->ui->p26->setEnabled(true);
  this->ui->p27->setEnabled(true);
  this->ui->p28->setEnabled(true);
  this->ui->p29->setEnabled(true);
  this->ui->p30->setEnabled(true);
  this->ui->p31->setEnabled(true);
  this->ui->p32->setEnabled(true);
  this->ui->p33->setEnabled(true);
  this->ui->p34->setEnabled(true);
  this->ui->p35->setEnabled(true);
  this->ui->p36->setEnabled(true);
  this->ui->p37->setEnabled(true);
  this->ui->p38->setEnabled(true);
  this->ui->p39->setEnabled(true);
  this->ui->p40->setEnabled(true);
  this->ui->p41->setEnabled(true);
  this->ui->p42->setEnabled(true);
  this->ui->p1->setVisible(true);
  this->ui->p2->setVisible(true);
  this->ui->p3->setVisible(true);
  this->ui->p4->setVisible(true);
  this->ui->p5->setVisible(true);
  this->ui->p6->setVisible(true);
  this->ui->p7->setVisible(true);
  this->ui->p8->setVisible(true);
  this->ui->p9->setVisible(true);
  this->ui->p10->setVisible(true);
  this->ui->p11->setVisible(true);
  this->ui->p12->setVisible(true);
  this->ui->p13->setVisible(true);
  this->ui->p14->setVisible(true);
  this->ui->p15->setVisible(true);
  this->ui->p16->setVisible(true);
  this->ui->p17->setVisible(true);
  this->ui->p18->setVisible(true);
  this->ui->p19->setVisible(true);
  this->ui->p20->setVisible(true);
  this->ui->p21->setVisible(true);
  this->ui->p22->setVisible(true);
  this->ui->p23->setVisible(true);
  this->ui->p24->setVisible(true);
  this->ui->p25->setVisible(true);
  this->ui->p26->setVisible(true);
  this->ui->p27->setVisible(true);
  this->ui->p28->setVisible(true);
  this->ui->p29->setVisible(true);
  this->ui->p30->setVisible(true);
  this->ui->p31->setVisible(true);
  this->ui->p32->setVisible(true);
  this->ui->p33->setVisible(true);
  this->ui->p34->setVisible(true);
  this->ui->p35->setVisible(true);
  this->ui->p36->setVisible(true);
  this->ui->p37->setVisible(true);
  this->ui->p38->setVisible(true);
  this->ui->p39->setVisible(true);
  this->ui->p40->setVisible(true);
  this->ui->p41->setVisible(true);
  this->ui->p42->setVisible(true);



}
void MainWindow::insta(){
    time_t t = time(0);
  tm* now = localtime(&t);
  timer = now->tm_hour*3600 + now->tm_min *60 + now->tm_sec ;
input->fill("", 21);

  this->mode= 2;
  this->ui->info->setText("Please Enter Instagram Password");
  this->ui->lok->setVisible(true);
  this->ui->pls->setVisible(true);
  this->ui->ok2->setVisible(true);
  this->ui->output->setText("");
  this->ui->p1->setEnabled(true);
  this->ui->p2->setEnabled(true);
  this->ui->p3->setEnabled(true);
  this->ui->p4->setEnabled(true);
  this->ui->p5->setEnabled(true);
  this->ui->p6->setEnabled(true);
  this->ui->p7->setEnabled(true);
  this->ui->p8->setEnabled(true);
  this->ui->p9->setEnabled(true);
  this->ui->p10->setEnabled(true);
  this->ui->p11->setEnabled(true);
  this->ui->p12->setEnabled(true);
  this->ui->p13->setEnabled(true);
  this->ui->p14->setEnabled(true);
  this->ui->p15->setEnabled(true);
  this->ui->p16->setEnabled(true);
  this->ui->p17->setEnabled(true);
  this->ui->p18->setEnabled(true);
  this->ui->p19->setEnabled(true);
  this->ui->p20->setEnabled(true);
  this->ui->p21->setEnabled(true);
  this->ui->p22->setEnabled(true);
  this->ui->p23->setEnabled(true);
  this->ui->p24->setEnabled(true);
  this->ui->p25->setEnabled(true);
  this->ui->p26->setEnabled(true);
  this->ui->p27->setEnabled(true);
  this->ui->p28->setEnabled(true);
  this->ui->p29->setEnabled(true);
  this->ui->p30->setEnabled(true);
  this->ui->p31->setEnabled(true);
  this->ui->p32->setEnabled(true);
  this->ui->p33->setEnabled(true);
  this->ui->p34->setEnabled(true);
  this->ui->p35->setEnabled(true);
  this->ui->p36->setEnabled(true);
  this->ui->p37->setEnabled(true);
  this->ui->p38->setEnabled(true);
  this->ui->p39->setEnabled(true);
  this->ui->p40->setEnabled(true);
  this->ui->p41->setEnabled(true);
  this->ui->p42->setEnabled(true);
  this->ui->p1->setVisible(true);
  this->ui->p2->setVisible(true);
  this->ui->p3->setVisible(true);
  this->ui->p4->setVisible(true);
  this->ui->p5->setVisible(true);
  this->ui->p6->setVisible(true);
  this->ui->p7->setVisible(true);
  this->ui->p8->setVisible(true);
  this->ui->p9->setVisible(true);
  this->ui->p10->setVisible(true);
  this->ui->p11->setVisible(true);
  this->ui->p12->setVisible(true);
  this->ui->p13->setVisible(true);
  this->ui->p14->setVisible(true);
  this->ui->p15->setVisible(true);
  this->ui->p16->setVisible(true);
  this->ui->p17->setVisible(true);
  this->ui->p18->setVisible(true);
  this->ui->p19->setVisible(true);
  this->ui->p20->setVisible(true);
  this->ui->p21->setVisible(true);
  this->ui->p22->setVisible(true);
  this->ui->p23->setVisible(true);
  this->ui->p24->setVisible(true);
  this->ui->p25->setVisible(true);
  this->ui->p26->setVisible(true);
  this->ui->p27->setVisible(true);
  this->ui->p28->setVisible(true);
  this->ui->p29->setVisible(true);
  this->ui->p30->setVisible(true);
  this->ui->p31->setVisible(true);
  this->ui->p32->setVisible(true);
  this->ui->p33->setVisible(true);
  this->ui->p34->setVisible(true);
  this->ui->p35->setVisible(true);
  this->ui->p36->setVisible(true);
  this->ui->p37->setVisible(true);
  this->ui->p38->setVisible(true);
  this->ui->p39->setVisible(true);
  this->ui->p40->setVisible(true);
  this->ui->p41->setVisible(true);
  this->ui->p42->setVisible(true);

}
