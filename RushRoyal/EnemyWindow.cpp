#include "EnemyWindow.h"
#include "ui_EnemyWindow.h"
#include <QScreen>
#include <QGuiApplication>
#include "Welcom_page.h"
#include "Gameplay_page.h"

EnemyWindow::EnemyWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EnemyWindow)
{
    ui->setupUi(this);
    // Set fixed size for the window
    this->setFixedSize(this->size());

    // Get screen geometry
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    this->move(x, y);  // Move window to the center of the screen
}

EnemyWindow::~EnemyWindow()
{
    delete ui;
}

void EnemyWindow::on_pushButton_clicked()
{
    welcom_page *we = new welcom_page;
    we->show();
    this->close();
}


void EnemyWindow::on_pushButton_2_clicked()
{
    Gameplay_page *window_game = new Gameplay_page;
    window_game->show();
    this->close();
}




