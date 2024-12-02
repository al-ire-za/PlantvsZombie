#include "Soldierenemy.h"
#include <QPropertyAnimation>

// background-image: url(:/prefix2/BossEnemy.png);
// background-image: url(:/prefix2/SoldierEnemy.png);

SoldierEnemy::SoldierEnemy(QWidget *parent)
    : Enemy(parent, 100, 2, ":/prefix2/SoldierEnemy.png")

{

}

SoldierEnemy::SoldierEnemy(const SoldierEnemy &other)
    :Enemy(other)
{

}

SoldierEnemy::~SoldierEnemy()
{

}

void SoldierEnemy::move(){
    int durationFactor = 1000 / EnemySpeed;

    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "geometry");
    animation1->setDuration(durationFactor * 4); // مدت زمان انیمیشن مرحله اول
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
