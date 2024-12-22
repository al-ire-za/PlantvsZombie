/********************************************************************************
** Form generated from reading UI file 'Bossenemy.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOSSENEMY_H
#define UI_BOSSENEMY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bossenemy
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Bossenemy)
    {
        if (Bossenemy->objectName().isEmpty())
            Bossenemy->setObjectName("Bossenemy");
        Bossenemy->resize(800, 600);
        centralwidget = new QWidget(Bossenemy);
        centralwidget->setObjectName("centralwidget");
        Bossenemy->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Bossenemy);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Bossenemy->setMenuBar(menubar);
        statusbar = new QStatusBar(Bossenemy);
        statusbar->setObjectName("statusbar");
        Bossenemy->setStatusBar(statusbar);

        retranslateUi(Bossenemy);

        QMetaObject::connectSlotsByName(Bossenemy);
    } // setupUi

    void retranslateUi(QMainWindow *Bossenemy)
    {
        Bossenemy->setWindowTitle(QCoreApplication::translate("Bossenemy", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bossenemy: public Ui_Bossenemy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOSSENEMY_H
