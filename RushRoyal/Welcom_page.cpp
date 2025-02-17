#include "Welcom_page.h"
#include "./ui_Welcom_page.h"
#include "Gameplay_page.h"
#include <QPointer>
#include <QGuiApplication>
#include <QScreen>
#include "ResultWindow.h"
#include "AgentWindow.h"
#include "EnemyWindow.h"
welcom_page::welcom_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::welcom_page)
{
    ui->setupUi(this);
    resize(800, 600);
    setMaximumSize(800, 600);
    setMinimumSize(800, 600);
    // ui->play_button->setStyleSheet(
    //     "QPushButton {"
    //     "    border-radius: 20px;"
    //     "    background-color: #4CAF50;"
    //     "    background-image: url(:/new/prefix1/images/abi_playbutton.png);"
    //     "    background-position: center;"
    //     "    background-repeat: no-repeat;"
    //     "    color: white;"
    //     "    font: bold 20pt 'Sitka Heading';"
    //     "    padding: 10px;"
    //     "    border: 2px solid #2E7D32;"
    //     "    box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);"
    //     "}"
    //     "QPushButton:hover {"
    //     "    background-color: #66BB6A;"
    //     "    border: 2px solid #388E3C;"
    //     "}"
    //     "QPushButton:pressed {"
    //     "    background-color: #388E3C;"
    //     "    border: 2px solid #1B5E20;"
    //     "}"
    //     );

    ui->play_button->setCursor(Qt::PointingHandCursor);


    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenRect = screen->availableGeometry();
    int x = (screenRect.width() - width()) / 2;
    int y = (screenRect.height() - height()) / 2;
    move(x, y);


}
welcom_page::~welcom_page()
{
    delete ui;
}



void welcom_page::on_play_button_clicked()
{
    Gameplay_page *window_game = new Gameplay_page;
    window_game->show();
    this->close();
    // ResultWindow *r = new ResultWindow;
    // r->show();
}


void welcom_page::on_agents_clicked()
{
    AgentWindow *ag = new AgentWindow;
    ag->show();
    this->close();
}


void welcom_page::on_enemy_clicked()
{
    EnemyWindow *en = new EnemyWindow;
    en->show();
    this->close();
}


void welcom_page::on_exit_clicked()
{
    QCoreApplication::quit();
}

