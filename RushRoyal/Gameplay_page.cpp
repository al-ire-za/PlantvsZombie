#include "Gameplay_page.h"
#include "ui_Gameplay_page.h"

#include <QGuiApplication>
#include <QScreen>
#include <QLabel>
#include <QFrame>
#include <QPropertyAnimation>
#include <QTime>
#include <QSequentialAnimationGroup>
#include <QVector>
#include <QDebug>
#include <QTimer>
#include <QMouseEvent>
#include <QPoint>

Gameplay_page::Gameplay_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gameplay_page)
{
    ui->setupUi(this);
    setMaximumSize(1200, 800);
    setMinimumSize(1200, 800);
    std::srand(time(NULL));
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenRect = screen->availableGeometry();
    int x = (screenRect.width() - width()) / 2;
    int y = (screenRect.height() - height()) / 2;
    move(x, y);


    // background-image: url(:/prefix2/images/felfelmoshaki2.png);
    // background-image: url(:/prefix2/images/gorbemahi2.png);
    // background-image: url(:/prefix2/images/golmoshaki2.png);
    // background-image: url(:/prefix2/images/gandom2.png);
    // background-image: url(:/prefix2/images/hendone_yakhi22.png);
    // background-image: url(:/prefix2/images/hendone2.png);
    // background-image: url(:/prefix2/images/kalam2.png);
    // background-image: url(:/prefix2/images/jolback2.png);
    // navar paiin

    randomImages = {
        ":/prefix2/images/jolback2.png",
        ":/prefix2/images/kalam2.png",
        ":/prefix2/images/hendone2.png",
        ":/prefix2/images/gandom2.png",
        ":/prefix2/images/golmoshaki2.png",
        ":/prefix2/images/gorbemahi2.png",
        ":/prefix2/images/felfelmoshaki2.png",
        ":/prefix2/images/hendone_yakhi22.png"
    };

    agent_choice1 = new QLabel(this);
    agent_choice1->setGeometry(410, 640, 90, 80);
    randomImage1 = randomImages[std::rand() % randomImages.size()];
    agent_choice1->setStyleSheet("background-image: url(" + randomImage1 + ");background-color: rgb(255, 255, 255);");


    agent_choice2 = new QLabel(this);
    agent_choice2->setGeometry(510, 640, 90, 80);
    randomImage2 = randomImages[std::rand() % randomImages.size()];
    agent_choice2->setStyleSheet("background-image: url(" + randomImage2 + ");background-color: rgb(255, 255, 255);");


    agent_choice3 = new QLabel(this);
    agent_choice3->setGeometry(610, 640, 90, 80);
    randomImage3 = randomImages[std::rand() % randomImages.size()];
    agent_choice3->setStyleSheet("background-image: url(" + randomImage3 + ");background-color: rgb(255, 255, 255);");


    agent_choice4 = new QLabel(this);
    agent_choice4->setGeometry(710, 640, 90, 80);
    randomImage4 = randomImages[std::rand() % randomImages.size()];
    agent_choice4->setStyleSheet("background-image: url(" + randomImage4 + ");background-color: rgb(255, 255, 255);");




    for (int i = 0; i < 16; ++i) {
        agent_board[i] = new QLabel(this);

    }


    const int width = 90;
    const int height = 80;
    const int startX = 350;
    const int startY = 250;
    const int xOffset = 140;
    const int yOffset = 90;

    for (int i = 0; i < 16; ++i) {
        int x = startX + (i % 4) * xOffset;
        int y = startY + (i / 4) * yOffset;

        agent_board[i]->setGeometry(x, y, width, height);
        agent_board[i]->setStyleSheet("background-image: url(:/prefix2/images/sanng.png);");
    }



    current_choice = nullptr;


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gameplay_page::create_enemi);
    timer->start(2000); //5000
}


int count_enemi = 0;
int wave = 0;
void Gameplay_page :: create_enemi(){
    int randomInterval;
    QLabel *new_labal = new QLabel(this);
    count_enemi++ ;
    new_labal->setStyleSheet("background-image: url(:/prefix2/images/kargadan_edit.png);");
    new_labal->setGeometry(220, 700, 90, 80);
    new_labal->show();
    labels.append(new_labal);
    move_enemi(new_labal);

    if(wave == 2){

        QApplication::quit();
    }

    if((count_enemi) % ( 5 + wave ) != 0){ // %20
        randomInterval = (std::rand() % 1500) + 500;
    }
    else{
        randomInterval = 10000; //20000
        wave++ ;
        count_enemi = 0;
    }


    timer->start(randomInterval);
}


void Gameplay_page :: move_enemi(QLabel *labal){
    QPropertyAnimation *animation = new QPropertyAnimation(labal, "geometry");
    animation->setDuration(1000); //1000
    animation->setStartValue(QRect(215, 700, 90, 80));
    animation->setEndValue(QRect(215, 140, 90, 80));

    QPropertyAnimation *animation2 = new QPropertyAnimation(labal, "geometry");
    animation2->setDuration(1000);
    animation2->setStartValue(QRect(215, 140, 90, 80));
    animation2->setEndValue(QRect(900, 140, 90, 80));

    QPropertyAnimation *animation3 = new QPropertyAnimation(labal, "geometry");
    animation3->setDuration(1000);
    animation3->setStartValue(QRect(900, 140, 90, 80));
    animation3->setEndValue(QRect(900, 625, 90, 80));


    QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);
    group->addAnimation(animation);
    group->addAnimation(animation2);
    group->addAnimation(animation3);

    connect(animation3, &QPropertyAnimation::finished, this, [this, labal]() {
        labal->hide();
    });

    group->start();

}


void Gameplay_page :: mousePressEvent(QMouseEvent *event){

    if(event->button() == Qt::LeftButton){

        if (event->pos().x() >= 410 && event->pos().x() <= 500 &&
            event->pos().y() >= 640 && event->pos().y() <= 720){
            current_choice = agent_choice1;

        }

        if (event->pos().x() >= 510 && event->pos().x() <= 600 &&
            event->pos().y() >= 640 && event->pos().y() <= 720){
            current_choice = agent_choice2;

        }

        if (event->pos().x() >= 610 && event->pos().x() <= 700 &&
            event->pos().y() >= 640 && event->pos().y() <= 720){
            current_choice = agent_choice3;

        }

        if (event->pos().x() >= 710 && event->pos().x() <= 800 &&
            event->pos().y() >= 640 && event->pos().y() <= 720){
            current_choice = agent_choice4;

        }

        if (current_choice) {
            for (int i = 0; i < 16; ++i) {
                if (event->pos().x() >= agent_board[i]->x() &&
                    event->pos().x() <= agent_board[i]->x() + agent_board[i]->width() &&
                    event->pos().y() >= agent_board[i]->y() &&
                    event->pos().y() <= agent_board[i]->y() + agent_board[i]->height()) {


                    if (agent_board[i]->styleSheet() == "background-image: url(:/prefix2/images/sanng.png);" ){
                        if (current_choice == agent_choice1) {
                            agent_board[i]->setStyleSheet("background-image: url(" + randomImage1 + ");background-color: rgb(203, 176, 131);");
                        } else if (current_choice == agent_choice2) {
                            agent_board[i]->setStyleSheet("background-image: url(" + randomImage2 + ");background-color: rgb(203, 176, 131);");
                        } else if (current_choice == agent_choice3) {
                            agent_board[i]->setStyleSheet("background-image: url(" + randomImage3 + ");background-color: rgb(203, 176, 131);");
                        } else if (current_choice == agent_choice4) {
                            agent_board[i]->setStyleSheet("background-image: url(" + randomImage4 + ");background-color: rgb(203, 176, 131);");
                        }


                        if(current_choice == agent_choice1){
                            randomImage1 = randomImages[std::rand() % randomImages.size()];
                            agent_choice1->setStyleSheet("background-image: url(" + randomImage1 + ");background-color: rgb(255, 255, 255);");
                        } else if(current_choice == agent_choice2) {
                            randomImage2 = randomImages[std::rand() % randomImages.size()];
                            agent_choice2->setStyleSheet("background-image: url(" + randomImage2 + ");background-color: rgb(255, 255, 255);");
                        } else if(current_choice == agent_choice3){
                            randomImage3 = randomImages[std::rand() % randomImages.size()];
                            agent_choice3->setStyleSheet("background-image: url(" + randomImage3 + ");background-color: rgb(255, 255, 255);");
                        } else if(current_choice == agent_choice4){
                            randomImage4 = randomImages[std::rand() % randomImages.size()];
                            agent_choice4->setStyleSheet("background-image: url(" + randomImage4 + ");background-color: rgb(255, 255, 255);");
                        }

                        current_choice = nullptr;

                    }


                }
            }
        }
    }
}




Gameplay_page::~Gameplay_page()
{
    delete ui;
}
