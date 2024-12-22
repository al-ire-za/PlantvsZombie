#include "Enemy.h"
#include <QLabel>
#include <QPropertyAnimation>

Enemy::Enemy(QWidget *parent, int health, double speed, const QString &imageUrl)
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

}

void Enemy::move(){

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





