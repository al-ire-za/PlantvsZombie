#include "Enemy.h"
#include <QLabel>
#include <QPropertyAnimation>

Enemy::Enemy(QWidget *parent, int health, int speed, const QString &imageUrl)
    : QLabel(parent), EnemyHealth(health), EnemySpeed(speed), EnemyImageUrl(imageUrl)

{
    updateimage(imageUrl);
}

Enemy::Enemy(const Enemy &other): EnemyHealth(other.EnemyHealth), EnemySpeed(other.EnemySpeed), EnemyImageUrl(other.EnemyImageUrl)
{
    updateimage(other.EnemyImageUrl);
}

Enemy::~Enemy()
{
    delete animationGroup;
}

void Enemy::move(){
    double durationFactor = 1000 / EnemySpeed;

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

int Enemy::gethealth() const{
    return EnemyHealth;
}

double Enemy::getspeed() const{
    return EnemySpeed;
}

void Enemy::updateimage(const QString &imageUrl){
    EnemyImageUrl = imageUrl;
    setStyleSheet("background-image: url(" + imageUrl + ");");
}

void Enemy::takeDamage(int damage) {
    EnemyHealth -= damage;
    if (EnemyHealth <= 0) {
        emit enemyDefeated();
        hide();
        deleteLater();
    }
}



