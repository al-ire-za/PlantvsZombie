/********************************************************************************
** Form generated from reading UI file 'ResultWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWINDOW_H
#define UI_RESULTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultWindow
{
public:
    QWidget *centralwidget;
    QLabel *leaderboard;
    QLabel *resultText;
    QMenuBar *menubar;

    void setupUi(QMainWindow *ResultWindow)
    {
        if (ResultWindow->objectName().isEmpty())
            ResultWindow->setObjectName("ResultWindow");
        ResultWindow->resize(800, 600);
        ResultWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/resultbackgrand.jpg);"));
        centralwidget = new QWidget(ResultWindow);
        centralwidget->setObjectName("centralwidget");
        leaderboard = new QLabel(centralwidget);
        leaderboard->setObjectName("leaderboard");
        leaderboard->setGeometry(QRect(170, 200, 301, 371));
        leaderboard->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"background-color: rgba(135, 230, 250, 150);\n"
"border: 8px;\n"
"font: bold 40px; \n"
"border-radius: 25px;\n"
"padding-top: 5px;"));
        resultText = new QLabel(centralwidget);
        resultText->setObjectName("resultText");
        resultText->setGeometry(QRect(250, 200, 141, 51));
        resultText->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"font: bold 40px;\n"
"color:  black;"));
        ResultWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ResultWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        ResultWindow->setMenuBar(menubar);

        retranslateUi(ResultWindow);

        QMetaObject::connectSlotsByName(ResultWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ResultWindow)
    {
        ResultWindow->setWindowTitle(QCoreApplication::translate("ResultWindow", "MainWindow", nullptr));
        leaderboard->setText(QString());
        resultText->setText(QCoreApplication::translate("ResultWindow", "RESULT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultWindow: public Ui_ResultWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWINDOW_H
