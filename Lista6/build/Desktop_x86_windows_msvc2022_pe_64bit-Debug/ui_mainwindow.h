/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "my_widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Zakoncz;
    QAction *action_O_programie;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    MyWidget *widget;
    QMenuBar *menubar;
    QMenu *menu_Quit;
    QMenu *menuPomo_c;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        action_Zakoncz = new QAction(MainWindow);
        action_Zakoncz->setObjectName("action_Zakoncz");
        action_O_programie = new QAction(MainWindow);
        action_O_programie->setObjectName("action_O_programie");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        widget = new MyWidget(centralwidget);
        widget->setObjectName("widget");

        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menu_Quit = new QMenu(menubar);
        menu_Quit->setObjectName("menu_Quit");
        menuPomo_c = new QMenu(menubar);
        menuPomo_c->setObjectName("menuPomo_c");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_Quit->menuAction());
        menubar->addAction(menuPomo_c->menuAction());
        menu_Quit->addAction(action_Zakoncz);
        menuPomo_c->addAction(action_O_programie);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_Zakoncz->setText(QCoreApplication::translate("MainWindow", "&Zako\305\204cz", nullptr));
#if QT_CONFIG(tooltip)
        action_Zakoncz->setToolTip(QCoreApplication::translate("MainWindow", "Zako\305\204cz program", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        action_Zakoncz->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        action_O_programie->setText(QCoreApplication::translate("MainWindow", "&O programie", nullptr));
#if QT_CONFIG(shortcut)
        action_O_programie->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        menu_Quit->setTitle(QCoreApplication::translate("MainWindow", "&Plik", nullptr));
        menuPomo_c->setTitle(QCoreApplication::translate("MainWindow", "Pomo&c", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
