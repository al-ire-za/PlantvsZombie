/********************************************************************************
** Form generated from reading UI file 'Gameplay_page.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPLAY_PAGE_H
#define UI_GAMEPLAY_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gameplay_page
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;

    void setupUi(QMainWindow *Gameplay_page)
    {
        if (Gameplay_page->objectName().isEmpty())
            Gameplay_page->setObjectName("Gameplay_page");
        Gameplay_page->resize(1200, 800);
        Gameplay_page->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/map_gamplay.jpg);"));
        centralwidget = new QWidget(Gameplay_page);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(390, 620, 100, 90));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(360, 470, 100, 90));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(360, 380, 100, 90));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(360, 290, 100, 90));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(480, 290, 100, 90));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(480, 470, 100, 90));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(480, 380, 100, 90));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(600, 470, 100, 90));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(600, 380, 100, 90));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(600, 290, 100, 90));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(720, 470, 100, 90));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(720, 380, 100, 90));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(720, 290, 100, 90));
        Gameplay_page->setCentralWidget(centralwidget);

        retranslateUi(Gameplay_page);

        QMetaObject::connectSlotsByName(Gameplay_page);
    } // setupUi

    void retranslateUi(QMainWindow *Gameplay_page)
    {
        Gameplay_page->setWindowTitle(QCoreApplication::translate("Gameplay_page", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_13->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_14->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_16->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_17->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_18->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
        label_19->setText(QCoreApplication::translate("Gameplay_page", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gameplay_page: public Ui_Gameplay_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPLAY_PAGE_H
