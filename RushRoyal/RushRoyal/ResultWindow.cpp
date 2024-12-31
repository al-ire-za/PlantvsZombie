#include "ResultWindow.h"
#include "ui_ResultWindow.h"
#include <QLabel>
#include <QGuiApplication>
#include <QScreen>


ResultWindow::ResultWindow(QWidget *parent) :
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

    int windowWidth = 640;
    int windowHeight = 600;
    int labelWidth = 200;
    int labelHeight = 50;
    int spacing = 20;

    int startY = (windowHeight - 4 * labelHeight - 3 * spacing) / 1;

    recordwave->setGeometry((windowWidth - labelWidth) / 2, startY, labelWidth, labelHeight);
    NOEnemyKilled->setGeometry((windowWidth - labelWidth) / 2, startY + labelHeight + spacing, labelWidth, labelHeight);
    elixirused->setGeometry((windowWidth - labelWidth) / 2, startY + 2 * (labelHeight + spacing), labelWidth, labelHeight);
    recorGame->setGeometry((windowWidth - labelWidth) / 2, startY - 1 * (labelHeight + spacing), labelWidth, labelHeight);


    recordwave->setStyleSheet("background-color: white; background: transparent; border: 2px solid black; font: bold 14px; text-align: center;");
   /* NOEnemyKilled->setStyleSheet("background-color: white; border: 2px solid black; font: bold 14px; text-align: center;");
    elixirused->setStyleSheet("background-color: white; border: 2px solid black; font: bold 14px; text-align: center;");
    recorGame->setStyleSheet("background-color: white; border: 2px solid black; font: bold 14px; text-align: center;");
*/
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenRect = screen->availableGeometry();
    int x = (screenRect.width() - width()) / 2;
    int y = (screenRect.height() - height()) / 2;
    move(x, y);

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
