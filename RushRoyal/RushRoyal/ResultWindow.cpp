#include "ResultWindow.h"
#include "ui_ResultWindow.h"
#include <QLabel>


ResultWindow::ResultWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    recordwave = new QLabel(this);
    NOEnemyKilled = new QLabel(this);
    elixirused = new QLabel(this);
    recorGame = new QLabel(this);

    int windowWidth = 800;
    int windowHeight = 600;
    int labelWidth = 200;
    int labelHeight = 20;
    int spacing = 20;

    int startY = (windowHeight - 4 * labelHeight - 3 * spacing) / 2;

    recordwave->setGeometry((windowWidth - labelWidth) / 2, startY, labelWidth, labelHeight);
    NOEnemyKilled->setGeometry((windowWidth - labelWidth) / 2, startY + labelHeight + spacing, labelWidth, labelHeight);
    elixirused->setGeometry((windowWidth - labelWidth) / 2, startY + 2 * (labelHeight + spacing), labelWidth, labelHeight);
    recorGame->setGeometry((windowWidth - labelWidth) / 2, startY + 3 * (labelHeight + spacing), labelWidth, labelHeight);


    recordwave->setStyleSheet("background-color: white; border: 2px solid black; font: bold 14px; text-align: center;");
    NOEnemyKilled->setStyleSheet("background-color: white; border: 2px solid black; font: bold 14px; text-align: center;");
    elixirused->setStyleSheet("background-color: white; border: 2px solid black; font: bold 14px; text-align: center;");
    recorGame->setStyleSheet("background-color: white; border: 2px solid black; font: bold 14px; text-align: center;");

}


void ResultWindow::setRecordWave(int wave)
{
    recordwave->setText(QString("Record Wave: %1").arg(wave));
}

void ResultWindow::setNOEnemyKilled(int count)
{
    NOEnemyKilled->setText(QString("Number of Enemies Killed: %1").arg(count));
}

void ResultWindow::setElixirUsed(int elixir)
{
    elixirused->setText(QString("Elixir Used: %1").arg(elixir));
}

void ResultWindow::setRecordGame(int record)
{
    recorGame->setText(QString("Record Game: %1").arg(record));
}

ResultWindow::~ResultWindow()
{
    delete ui;
}
