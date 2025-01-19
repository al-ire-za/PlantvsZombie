/********************************************************************************
** Form generated from reading UI file 'AgentWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTWINDOW_H
#define UI_AGENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgentWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *AgentWindow)
    {
        if (AgentWindow->objectName().isEmpty())
            AgentWindow->setObjectName("AgentWindow");
        AgentWindow->resize(1200, 800);
        AgentWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/black.jpg);"));
        centralwidget = new QWidget(AgentWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 600, 200));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/golmushakiwindow.PNG);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(600, 0, 600, 200));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/gorbemahiwindow.PNG);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 200, 601, 200));
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/windowgandom.png);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(600, 200, 621, 200));
        label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/kalamwindow.PNG);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 400, 1200, 201));
        label_5->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/windowbomb.PNG);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 590, 1200, 200));
        label_6->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/windowtrap.PNG);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1000, 740, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(67, 161, 81);\n"
"background-color: rgb(67, 161, 81);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(1090, 740, 83, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(67, 161, 81);\n"
"background-color: rgb(67, 161, 81);"));
        AgentWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AgentWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 25));
        AgentWindow->setMenuBar(menubar);

        retranslateUi(AgentWindow);

        QMetaObject::connectSlotsByName(AgentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AgentWindow)
    {
        AgentWindow->setWindowTitle(QCoreApplication::translate("AgentWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("AgentWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("AgentWindow", "menu", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AgentWindow", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgentWindow: public Ui_AgentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTWINDOW_H
