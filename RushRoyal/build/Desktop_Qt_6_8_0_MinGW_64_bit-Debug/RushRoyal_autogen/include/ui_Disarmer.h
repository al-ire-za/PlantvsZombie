/********************************************************************************
** Form generated from reading UI file 'Disarmer.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISARMER_H
#define UI_DISARMER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Disarmer
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Disarmer)
    {
        if (Disarmer->objectName().isEmpty())
            Disarmer->setObjectName("Disarmer");
        Disarmer->resize(800, 600);
        centralwidget = new QWidget(Disarmer);
        centralwidget->setObjectName("centralwidget");
        Disarmer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Disarmer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Disarmer->setMenuBar(menubar);
        statusbar = new QStatusBar(Disarmer);
        statusbar->setObjectName("statusbar");
        Disarmer->setStatusBar(statusbar);

        retranslateUi(Disarmer);

        QMetaObject::connectSlotsByName(Disarmer);
    } // setupUi

    void retranslateUi(QMainWindow *Disarmer)
    {
        Disarmer->setWindowTitle(QCoreApplication::translate("Disarmer", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Disarmer: public Ui_Disarmer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISARMER_H
