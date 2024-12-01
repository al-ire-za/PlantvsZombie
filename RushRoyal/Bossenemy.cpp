#include "Bossenemy.h"
#include <QPropertyAnimation>


BossEnemy::BossEnemy(QWidget *parent)
    : Enemy(parent, 500, 1, ":/prefix2/BossEnemy.png")

{

}

BossEnemy::BossEnemy(const BossEnemy &other)
    :Enemy(other)
{

}

BossEnemy::~BossEnemy()
{

}

void BossEnemy::move(){
    int durationFactor = 1000 / EnemySpeed;

    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "geometry");
    animation1->setDuration(durationFactor * 4);
    animation1->setStartValue(QRect(215, 700, 90, 80));
    animation1->setEndValue(QRect(215, 140, 90, 80));

    QPropertyAnimation *animation2 = new QPropertyAnimation(this, "geometry");
    animation2->setDuration(durationFactor * 4);
    animation2->setStartValue(QRect(215, 140, 90, 80));
    animation2->setEndValue(QRect(900, 140, 90, 80));

    QPropertyAnimation *animation3 = new QPropertyAnimation(this, "geometry");
    animation3->setDuration(durationFactor * 4);
    animation3->setStartValue(QRect(900, 140, 90, 80));
    animation3->setEndValue(QRect(900, 625, 90, 80));

    animationGroup->addAnimation(animation1);
    animationGroup->addAnimation(animation2);
    animationGroup->addAnimation(animation3);

    connect(animationGroup, &QSequentialAnimationGroup::finished, this, [this]() {
        this->hide();
    });

    animationGroup->start();
}
