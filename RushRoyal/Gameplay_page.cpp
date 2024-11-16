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


    // navar paiin
    agent_choice1 = new QLabel(this);
    agent_choice1->setGeometry(410, 640, 90, 80);
    agent_choice1->setStyleSheet("background-image: url(:/new/prefix1/images/abi_playbutton.png);");
    agent_choice1->setFrameShape(QFrame::Panel);

    agent_choice2 = new QLabel(this);
    agent_choice2->setGeometry(510, 640, 90, 80); 
    agent_choice2->setStyleSheet("background-image: url(:/new/prefix2/images/sorati.jfif);");
    agent_choice2->setFrameShape(QFrame::Panel);

    agent_choice3 = new QLabel(this);
    agent_choice3->setGeometry(610, 640, 90, 80);
    agent_choice3->setStyleSheet("background-image: url(:/new/prefix2/images/red.png);");
    agent_choice3->setFrameShape(QFrame::Panel);

    agent_choice4 = new QLabel(this);
    agent_choice4->setGeometry(710, 640, 90, 80);
    agent_choice4->setStyleSheet("background-image: url(:/new/prefix2/images/zard.png);");
    agent_choice4->setFrameShape(QFrame::Panel);





    for (int i = 0; i < 16; ++i) {
        agent_board[i] = new QLabel(this);

    }

    agent_board[0]->setGeometry(350, 250, 90, 80);
    agent_board[1]->setGeometry(490, 250, 90, 80);
    agent_board[2]->setGeometry(630, 250, 90, 80);
    agent_board[3]->setGeometry(770, 250, 90, 80);
    agent_board[4]->setGeometry(350, 340, 90, 80);
    agent_board[5]->setGeometry(490, 340, 90, 80);
    agent_board[6]->setGeometry(630, 340, 90, 80);
    agent_board[7]->setGeometry(770, 340, 90, 80);
    agent_board[8]->setGeometry(350, 430, 90, 80);
    agent_board[9]->setGeometry(490, 430, 90, 80);
    agent_board[10]->setGeometry(630, 430, 90, 80);
    agent_board[11]->setGeometry(770, 430, 90, 80);
    agent_board[12]->setGeometry(350, 520, 90, 80);
    agent_board[13]->setGeometry(490, 520, 90, 80);
    agent_board[14]->setGeometry(630, 520, 90, 80);
    agent_board[15]->setGeometry(770, 520, 90, 80);

    current_choice = nullptr;


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gameplay_page::create_enemi);
    timer->start(2000); //5000
}


// background-image: url(:/prefix2/images/babr_edit3.png);
// background-image: url(:/prefix2/images/gorg_edit.png);
// background-image: url(:/prefix2/images/kargadan_edit.png);
// background-image: url(:/prefix2/images/shir_edit.png);

int count_enemi = 0;
void Gameplay_page :: create_enemi(){
    int randomInterval;
    QLabel *new_labal = new QLabel(this);
    count_enemi ++;
    new_labal->setStyleSheet("background: transparent;background-image: url(:/prefix2/images/shir_edit.png);");
    new_labal->setGeometry(220, 700, 90, 80);
    new_labal->show();
    labels.append(new_labal);
    move_enemi(new_labal);
    if(count_enemi % 5 != 0){ // %20
        randomInterval = (std::rand() % 1500) + 500;
    }
    else{
        randomInterval = 10000; //20000
    }

    timer->start(randomInterval);


}

void Gameplay_page :: move_enemi(QLabel *labal){
    QPropertyAnimation *animation = new QPropertyAnimation(labal, "geometry");
    animation->setDuration(5000); //5000
    animation->setStartValue(QRect(215, 700, 90, 80));
    animation->setEndValue(QRect(215, 140, 90, 80));

    QPropertyAnimation *animation2 = new QPropertyAnimation(labal, "geometry");
    animation2->setDuration(5000);
    animation2->setStartValue(QRect(215, 140, 90, 80));
    animation2->setEndValue(QRect(900, 140, 90, 80));

    QPropertyAnimation *animation3 = new QPropertyAnimation(labal, "geometry");
    animation3->setDuration(5000);
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


    }
}




Gameplay_page::~Gameplay_page()
{
    delete ui;
}
