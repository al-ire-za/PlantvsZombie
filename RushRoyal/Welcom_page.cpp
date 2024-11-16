#include "Welcom_page.h"
#include "./ui_Welcom_page.h"
#include "Gameplay_page.h"
#include <QPointer>
#include <QGuiApplication>
#include <QScreen>

welcom_page::welcom_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::welcom_page)
{
    ui->setupUi(this);
    resize(806, 800);
    setMaximumSize(806, 800);
    setMinimumSize(806, 800);
    ui->play_button->setStyleSheet("QPushButton { "
                                   "border-radius: 20px; "
                                   "background-color: #4CAF50; "  // رنگ سبز
                                   "background-image: url(:/new/prefix1/images/abi_playbutton.png); "
                                   "background-position: center; "
                                   "background-repeat: no-repeat; "
                                   "color: rgb(255, 255, 255); "
                                   "font: bold 14pt 'Sitka Heading'; "
                                   "padding: 10px; "
                                   "border: none; "  // خط مرزی حذف شد
                                   "} "
                                   "}");

    ui->play_button->setCursor(Qt :: PointingHandCursor);

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
}

