/********************************************************************************
** Form generated from reading UI file 'Welcom_page.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOM_PAGE_H
#define UI_WELCOM_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcom_page
{
public:
    QWidget *centralwidget;
    QPushButton *play_button;
    QPushButton *agents;
    QPushButton *enemy;
    QPushButton *exit;

    void setupUi(QMainWindow *welcom_page)
    {
        if (welcom_page->objectName().isEmpty())
            welcom_page->setObjectName("welcom_page");
        welcom_page->resize(1031, 765);
        welcom_page->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        welcom_page->setStyleSheet(QString::fromUtf8("background-image: url(:/prefix2/images/themwelcom.jpg);"));
        centralwidget = new QWidget(welcom_page);
        centralwidget->setObjectName("centralwidget");
        play_button = new QPushButton(centralwidget);
        play_button->setObjectName("play_button");
        play_button->setGeometry(QRect(410, 70, 331, 111));
        play_button->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        play_button->setMouseTracking(false);
        play_button->setStyleSheet(QString::fromUtf8("background : transparent;"));
        agents = new QPushButton(centralwidget);
        agents->setObjectName("agents");
        agents->setGeometry(QRect(420, 190, 291, 81));
        agents->setStyleSheet(QString::fromUtf8("background : transparent;\n"
""));
        enemy = new QPushButton(centralwidget);
        enemy->setObjectName("enemy");
        enemy->setGeometry(QRect(420, 280, 261, 71));
        enemy->setStyleSheet(QString::fromUtf8("background : transparent;"));
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(410, 360, 251, 71));
        exit->setStyleSheet(QString::fromUtf8("background : transparent;"));
        welcom_page->setCentralWidget(centralwidget);

        retranslateUi(welcom_page);

        QMetaObject::connectSlotsByName(welcom_page);
    } // setupUi

    void retranslateUi(QMainWindow *welcom_page)
    {
        welcom_page->setWindowTitle(QCoreApplication::translate("welcom_page", "welcom_page", nullptr));
        play_button->setText(QString());
        agents->setText(QString());
        enemy->setText(QString());
        exit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class welcom_page: public Ui_welcom_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOM_PAGE_H
