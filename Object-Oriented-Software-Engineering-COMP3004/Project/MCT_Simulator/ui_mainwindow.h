/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *left;
    QPushButton *right;
    QPushButton *down;
    QPushButton *up;
    QPushButton *ok;
    QPushButton *Off_On;
    QPushButton *undo;
    QPushButton *mainWindow;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(411, 502);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        left = new QPushButton(centralWidget);
        left->setObjectName(QStringLiteral("left"));
        left->setGeometry(QRect(22, 290, 89, 25));
        right = new QPushButton(centralWidget);
        right->setObjectName(QStringLiteral("right"));
        right->setGeometry(QRect(282, 290, 89, 25));
        down = new QPushButton(centralWidget);
        down->setObjectName(QStringLiteral("down"));
        down->setGeometry(QRect(152, 340, 89, 25));
        up = new QPushButton(centralWidget);
        up->setObjectName(QStringLiteral("up"));
        up->setGeometry(QRect(152, 240, 89, 25));
        ok = new QPushButton(centralWidget);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(170, 290, 51, 21));
        Off_On = new QPushButton(centralWidget);
        Off_On->setObjectName(QStringLiteral("Off_On"));
        Off_On->setGeometry(QRect(152, 410, 89, 25));
        undo = new QPushButton(centralWidget);
        undo->setObjectName(QStringLiteral("undo"));
        undo->setGeometry(QRect(20, 190, 89, 25));
        mainWindow = new QPushButton(centralWidget);
        mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->setGeometry(QRect(280, 190, 111, 25));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(19, 10, 371, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 411, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        left->setText(QApplication::translate("MainWindow", "Left", Q_NULLPTR));
        right->setText(QApplication::translate("MainWindow", "Right", Q_NULLPTR));
        down->setText(QApplication::translate("MainWindow", "Down", Q_NULLPTR));
        up->setText(QApplication::translate("MainWindow", "Up", Q_NULLPTR));
        ok->setText(QApplication::translate("MainWindow", "Ok", Q_NULLPTR));
        Off_On->setText(QApplication::translate("MainWindow", "Off/On", Q_NULLPTR));
        undo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        mainWindow->setText(QApplication::translate("MainWindow", "Main window", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
