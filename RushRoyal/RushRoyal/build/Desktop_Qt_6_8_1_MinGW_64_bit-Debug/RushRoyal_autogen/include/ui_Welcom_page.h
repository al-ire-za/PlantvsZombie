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

    void setupUi(QMainWindow *welcom_page)
    {
        if (welcom_page->objectName().isEmpty())
            welcom_page->setObjectName("welcom_page");
        welcom_page->resize(1054, 822);
        welcom_page->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        welcom_page->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/new/prefix1/images/welcom_page.png);"));
        centralwidget = new QWidget(welcom_page);
        centralwidget->setObjectName("centralwidget");
        play_button = new QPushButton(centralwidget);
        play_button->setObjectName("play_button");
        play_button->setGeometry(QRect(340, 630, 121, 51));
        play_button->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        play_button->setMouseTracking(false);
        play_button->setStyleSheet(QString::fromUtf8(""));
        welcom_page->setCentralWidget(centralwidget);

        retranslateUi(welcom_page);

        QMetaObject::connectSlotsByName(welcom_page);
    } // setupUi

    void retranslateUi(QMainWindow *welcom_page)
    {
        welcom_page->setWindowTitle(QCoreApplication::translate("welcom_page", "welcom_page", nullptr));
        play_button->setText(QCoreApplication::translate("welcom_page", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class welcom_page: public Ui_welcom_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOM_PAGE_H
