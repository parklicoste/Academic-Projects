#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_create_clicked();

    void on_enter_clicked();

    void on_p1_clicked();

    void on_p22_clicked();

    void on_p2_clicked();

    void on_p23_clicked();

    void on_p3_clicked();

    void on_p24_clicked();

    void on_p4_clicked();

    void on_p25_clicked();

    void on_p5_clicked();

    void on_p26_clicked();

    void on_p6_clicked();

    void on_p27_clicked();

    void on_p7_clicked();

    void on_p28_clicked();

    void on_p15_clicked();

    void on_p36_clicked();

    void on_p16_clicked();

    void on_p37_clicked();

    void on_p17_clicked();

    void on_p38_clicked();

    void on_p18_clicked();

    void on_p39_clicked();

    void on_p19_clicked();

    void on_p40_clicked();

    void on_p20_clicked();

    void on_p41_clicked();

    void on_p21_clicked();

    void on_p42_clicked();

    void on_p14_clicked();

    void on_p35_clicked();

    void on_p13_clicked();

    void on_p34_clicked();

    void on_p12_clicked();

    void on_p33_clicked();

    void on_p11_clicked();

    void on_p32_clicked();
    void on_p8_clicked();

    void on_p29_clicked();
    void on_p10_clicked();

        void on_p31_clicked();

        void on_p9_clicked();

        void on_p30_clicked();

        void on_ok_clicked();

        void on_next_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QString> password;
    QVector<QString> * input;
};
#endif // MAINWINDOW_H
