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

Gameplay_page::Gameplay_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gameplay_page)
{
    ui->setupUi(this);
    setMaximumSize(1200, 800);
    setMinimumSize(1200, 800);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenRect = screen->availableGeometry();
    int x = (screenRect.width() - width()) / 2;
    int y = (screenRect.height() - height()) / 2;
    move(x, y);

    QLabel *labal_agent1 = new QLabel(this);
    labal_agent1->setGeometry(390, 620, 100, 90);
    labal_agent1->setFrameShape(QFrame::Panel);
    QLabel *labal_agent2 = new QLabel(this);
    labal_agent2->setGeometry(500, 620, 100, 90);
    labal_agent2->setFrameShape(QFrame::Panel);
    QLabel *labal_agent3 = new QLabel(this);
    labal_agent3->setGeometry(610, 620, 100, 90);
    labal_agent3->setFrameShape(QFrame::Panel);
    QLabel *labal_agent4 = new QLabel(this);
    labal_agent4->setGeometry(720, 620, 100, 90);
    labal_agent4->setFrameShape(QFrame::Panel);


    create_enemi();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gameplay_page::create_enemi);
    int randomInterval = (std::rand() % 2000) + 1000;
    timer->start(randomInterval);
}





void Gameplay_page :: create_enemi(){
    QLabel *new_labal = new QLabel(this);
    new_labal->setStyleSheet("background: transparent;background-image: url(:/prefix2/images/Untitled-2.png);");
    new_labal->setGeometry(220, 700, 80, 80);
    new_labal->show();
    labels.append(new_labal);
    move_enemi(new_labal);

}

void Gameplay_page :: move_enemi(QLabel *labal){
    QPropertyAnimation *animation = new QPropertyAnimation(labal, "geometry");
    animation->setDuration(3000);
    animation->setStartValue(QRect(215, 700, 80, 80));
    animation->setEndValue(QRect(215, 140, 80, 80));

    QPropertyAnimation *animation2 = new QPropertyAnimation(labal, "geometry");
    animation2->setDuration(3000);
    animation2->setStartValue(QRect(215, 140, 80, 80));
    animation2->setEndValue(QRect(900, 140, 80, 80));

    QPropertyAnimation *animation3 = new QPropertyAnimation(labal, "geometry");
    animation3->setDuration(3000);
    animation3->setStartValue(QRect(900, 140, 80, 80));
    animation3->setEndValue(QRect(900, 610, 80, 80));

    QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);
    group->addAnimation(animation);
    group->addAnimation(animation2);
    group->addAnimation(animation3);
    group->start();
}

Gameplay_page::~Gameplay_page()
{
    delete ui;
}
