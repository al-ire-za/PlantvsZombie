/********************************************************************************
** Form generated from reading UI file 'EnemyWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENEMYWINDOW_H
#define UI_ENEMYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnemyWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *EnemyWindow)
    {
        if (EnemyWindow->objectName().isEmpty())
            EnemyWindow->setObjectName("EnemyWindow");
        EnemyWindow->resize(900, 800);
        EnemyWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/black.jpg);"));
        centralwidget = new QWidget(EnemyWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1200, 200));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/eraserwidow.PNG);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 120, 1200, 200));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 900, 530));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"\n"
"background-image: url(:/prefix2/images/2222.PNG);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 520, 900, 280));
        label_5->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/prefix2/images/13321.PNG);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(700, 770, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(67, 161, 81);\n"
"background-color: rgb(67, 161, 81);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(790, 770, 83, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(67, 161, 81);\n"
"background-color: rgb(67, 161, 81);"));
        EnemyWindow->setCentralWidget(centralwidget);

        retranslateUi(EnemyWindow);

        QMetaObject::connectSlotsByName(EnemyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EnemyWindow)
    {
        EnemyWindow->setWindowTitle(QCoreApplication::translate("EnemyWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        pushButton->setText(QCoreApplication::translate("EnemyWindow", "menu", nullptr));
        pushButton_2->setText(QCoreApplication::translate("EnemyWindow", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnemyWindow: public Ui_EnemyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENEMYWINDOW_H
