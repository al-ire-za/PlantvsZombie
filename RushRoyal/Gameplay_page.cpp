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
    QLabel *agent_choice1 = new QLabel(this);
    agent_choice1->setGeometry(410, 640, 90, 80);
    agent_choice1->setFrameShape(QFrame::Panel);
    QLabel *agent_choice2 = new QLabel(this);
    agent_choice2->setGeometry(510, 640, 90, 80);
    agent_choice2->setFrameShape(QFrame::Panel);
    QLabel *agent_choice3 = new QLabel(this);
    agent_choice3->setGeometry(610, 640, 90, 80);
    agent_choice3->setFrameShape(QFrame::Panel);
    QLabel *agent_choice4 = new QLabel(this);
    agent_choice4->setGeometry(710, 640, 90, 80);
    agent_choice4->setFrameShape(QFrame::Panel);

    // board agent
    QLabel *agent_board1 = new QLabel(this);
    agent_board1->setGeometry(350, 250, 90, 80);
    QLabel *agent_board2 = new QLabel(this);
    agent_board2->setGeometry(490, 250, 90, 80);
    QLabel *agent_board3 = new QLabel(this);
    agent_board3->setGeometry(630, 250, 90, 80);
    QLabel *agent_board4 = new QLabel(this);
    agent_board4->setGeometry(770, 250, 90, 80);
    QLabel *agent_board5 = new QLabel(this);
    agent_board5->setGeometry(350, 340, 90, 80);
    QLabel *agent_board6 = new QLabel(this);
    agent_board6->setGeometry(490, 340, 90, 80);
    QLabel *agent_board7 = new QLabel(this);
    agent_board7->setGeometry(630, 340, 90, 80);
    QLabel *agent_board8 = new QLabel(this);
    agent_board8->setGeometry(770, 340, 90, 80);
    QLabel *agent_board9 = new QLabel(this);
    agent_board9->setGeometry(350, 430, 90, 80);
    QLabel *agent_board10 = new QLabel(this);
    agent_board10->setGeometry(490, 430, 90, 80);
    QLabel *agent_board11 = new QLabel(this);
    agent_board11->setGeometry(630, 430, 90, 80);
    QLabel *agent_board12 = new QLabel(this);
    agent_board12->setGeometry(770, 430, 90, 80);
    QLabel *agent_board13 = new QLabel(this);
    agent_board13->setGeometry(350, 520, 90, 80);
    QLabel *agent_board14 = new QLabel(this);
    agent_board14->setGeometry(490, 520, 90, 80);
    QLabel *agent_board15 = new QLabel(this);
    agent_board15->setGeometry(630, 520, 90, 80);
    QLabel *agent_board16 = new QLabel(this);
    agent_board16->setGeometry(770, 520, 90, 80);



    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gameplay_page::create_enemi);
    timer->start(2000); //5000
}




int count_enemi = 0;
void Gameplay_page :: create_enemi(){
    int randomInterval;
    QLabel *new_labal = new QLabel(this);
    count_enemi ++;
    new_labal->setStyleSheet("background: transparent;background-image: url(:/prefix2/images/gorg.jpg);");
    new_labal->setGeometry(220, 700, 80, 80);
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
    animation->setStartValue(QRect(215, 700, 80, 80));
    animation->setEndValue(QRect(215, 140, 80, 80));

    QPropertyAnimation *animation2 = new QPropertyAnimation(labal, "geometry");
    animation2->setDuration(5000);
    animation2->setStartValue(QRect(215, 140, 80, 80));
    animation2->setEndValue(QRect(900, 140, 80, 80));

    QPropertyAnimation *animation3 = new QPropertyAnimation(labal, "geometry");
    animation3->setDuration(5000);
    animation3->setStartValue(QRect(900, 140, 80, 80));
    animation3->setEndValue(QRect(900, 625, 80, 80));


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
    qDebug() << event->pos();

}

Gameplay_page::~Gameplay_page()
{
    delete ui;
}
