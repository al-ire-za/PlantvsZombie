/********************************************************************************
** Form generated from reading UI file 'Freezer.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREEZER_H
#define UI_FREEZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Freezer
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Freezer)
    {
        if (Freezer->objectName().isEmpty())
            Freezer->setObjectName("Freezer");
        Freezer->resize(800, 600);
        centralwidget = new QWidget(Freezer);
        centralwidget->setObjectName("centralwidget");
        Freezer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Freezer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Freezer->setMenuBar(menubar);
        statusbar = new QStatusBar(Freezer);
        statusbar->setObjectName("statusbar");
        Freezer->setStatusBar(statusbar);

        retranslateUi(Freezer);

        QMetaObject::connectSlotsByName(Freezer);
    } // setupUi

    void retranslateUi(QMainWindow *Freezer)
    {
        Freezer->setWindowTitle(QCoreApplication::translate("Freezer", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Freezer: public Ui_Freezer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREEZER_H
