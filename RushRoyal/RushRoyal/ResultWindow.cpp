#include "ResultWindow.h"
#include "ui_ResultWindow.h"
#include <QLabel>
#include <QGuiApplication>
#include <QScreen>


ResultWindow::ResultWindow(int wave , int count , int elixir , int record , QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    resize(640, 600);
    setMaximumSize(640, 600);
    setMinimumSize(640, 600);
    recordwave = new QLabel(this);
    NOEnemyKilled = new QLabel(this);
    elixirused = new QLabel(this);
    recorGame = new QLabel(this);

    ui->leaderboard->setText("RESULT");

    ui->leaderboard->setStyleSheet(
        "background: transparent;"
        " background-color: rgba(135, 230, 250, 150);"
        " border: 8px;"
        " font: bold 40px; "
        " color:  orange; "
        "border-radius: 25px;"
        "padding-top: 5px;"
        );


    int windowWidth = 640;
    int windowHeight = 600;
    int labelWidth = 280;
    int labelHeight = 55;
    int spacing = 10;

    int startY = (windowHeight - 4 * labelHeight - 3 * spacing) / 1;


    recordwave->setGeometry((windowWidth - labelWidth) / 2, startY - (labelHeight + spacing) +20, labelWidth, labelHeight);
    setRecordWave(wave);
    recordwave->setStyleSheet(" background: transparent;"
                              " background-color: rgba(255, 170, 0, 200);"
                              " border: 2px solid black;"
                              " border-radius: 15px ;"
                              " font: bold 28px;"
                              );

    NOEnemyKilled->setGeometry((windowWidth - labelWidth) / 2, startY +20 , labelWidth, labelHeight);
    setNOEnemyKilled(count);
    NOEnemyKilled->setStyleSheet(" background: transparent;"
                                 " background-color: rgba(255, 170, 0, 200);"
                                 " border: 2px solid black;"
                                 " border-radius: 15px ;"
                                 " font: bold 26px;"
                                 );

    elixirused->setGeometry((windowWidth - labelWidth) / 2, startY + (labelHeight + spacing) +20, labelWidth, labelHeight);
    setElixirUsed(elixir);
    elixirused->setStyleSheet(" background: transparent;"
                              " background-color: rgba(255, 170, 0, 200);"
                              " border: 2px solid black;"
                              " border-radius: 15px ;"
                              " font: bold 28px;"
                              );

    recorGame->setGeometry((windowWidth - labelWidth) / 2, startY + 2 * (labelHeight + spacing) +20, labelWidth, labelHeight);
    setRecordGame(record);
    recorGame->setStyleSheet(" background: transparent;"
                             " background-color: rgba(255, 170, 0, 200);"
                             " border: 2px solid black;"
                             " border-radius: 15px ;"
                             " font: bold 27px;");


    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenRect = screen->availableGeometry();
    int x = (screenRect.width() - width()) / 2;
    int y = (screenRect.height() - height()) / 2;
    move(x, y);

}


void ResultWindow::setRecordWave(int wave)
{
    recordwave->setText(QString("Wave Record :  "+ QString::number(wave)));
}

void ResultWindow::setNOEnemyKilled(int count)
{
    NOEnemyKilled->setText(QString("Killed Enemies :  "+ QString::number(count)));
}

void ResultWindow::setElixirUsed(int elixir)
{
    elixirused->setText(QString("Elixir Used :      "+ QString::number(elixir)));
}

void ResultWindow::setRecordGame(int record)
{
    recorGame->setText(QString("Game Record :  "+ QString::number(record)));
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

