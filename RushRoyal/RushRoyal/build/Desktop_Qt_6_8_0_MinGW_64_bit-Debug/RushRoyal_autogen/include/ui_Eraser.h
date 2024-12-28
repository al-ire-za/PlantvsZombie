/********************************************************************************
** Form generated from reading UI file 'Eraser.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERASER_H
#define UI_ERASER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Eraser
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Eraser)
    {
        if (Eraser->objectName().isEmpty())
            Eraser->setObjectName("Eraser");
        Eraser->resize(800, 600);
        centralwidget = new QWidget(Eraser);
        centralwidget->setObjectName("centralwidget");
        Eraser->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Eraser);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Eraser->setMenuBar(menubar);
        statusbar = new QStatusBar(Eraser);
        statusbar->setObjectName("statusbar");
        Eraser->setStatusBar(statusbar);

        retranslateUi(Eraser);

        QMetaObject::connectSlotsByName(Eraser);
    } // setupUi

    void retranslateUi(QMainWindow *Eraser)
    {
        Eraser->setWindowTitle(QCoreApplication::translate("Eraser", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Eraser: public Ui_Eraser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERASER_H
