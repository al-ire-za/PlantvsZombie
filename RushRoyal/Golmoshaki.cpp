#include "Golmoshaki.h"
#include "AgentBase.h"
#include "Gameplay_page.h"
#include <qtimer.h>
#include <QTimer>
#include "Bullet.h"


Golmoshaki::Golmoshaki(QWidget *parent)
    :AgentBase(parent, ":/prefix2/images/golmoshaki1.png", 15, 1200, 2)
{
    timett = new QTimer();
    connect(timett , &QTimer::timeout , this , &Golmoshaki::shootAt );
}

Golmoshaki::Golmoshaki(const Golmoshaki &other)
    : AgentBase(other){

}

int Golmoshaki::calculateDistanceToFinish(Enemy* enemy) {
    QPointF enemyPos = enemy->pos();
    int distance = 0;

    // محاسبه فاصله از ابتدای مسیر تا موقعیت فعلی انمی
    // بخش اول از 215, 700 تا 215, 140
    if (enemyPos.x() == 215 && enemyPos.y() <= 700 && enemyPos.y() >= 140) {
        distance += (enemyPos.y() - 140) + (900 - 215) + (625 - 140);
    }
    // بخش دوم از 215, 140 تا 900, 140
    else if (enemyPos.y() == 140 && enemyPos.x() >= 215 && enemyPos.x() <= 900) {
        distance += (900 - enemyPos.x()) + (625 - 140);
    }
    // بخش سوم از 900, 140 تا 900, 625
    else if (enemyPos.x() == 900 && enemyPos.y() >= 140 && enemyPos.y() <= 625) {
        distance +=  (625 - enemyPos.y());
    }

    return distance;
}

Enemy* Golmoshaki::findClosestEnemy(Gameplay_page* gamePage)
{
    Enemy* closestEnemy = nullptr;
    int closestDistance = INT_MAX;

    foreach(Enemy* enemy, gamePage->enemies) {
        int distance = calculateDistanceToFinish(enemy);
        if (distance < closestDistance) { // بررسی کمترین فاصله
            closestEnemy = enemy;
            closestDistance = distance;
        }
    }

    return closestEnemy;
}

void Golmoshaki::shootAt()
{
    Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
    if (!gamePage || gamePage->enemies.isEmpty() || isFrozen()) return;

    Enemy* target = findClosestEnemy(gamePage); // تغییر نام تابع

    if (target) {
        Bullet* bullet = new Bullet(parentWidget(), AgentBasePower);
        bullet->setGeometry(geometry().center().x() - 5, geometry().y() - 20, 10, 20);
        bullet->setStyleSheet(QString("background-image: url(:/prefix2/images/tirgolmushaki%1.png);").arg(gamePage->levels[0]));
        bullet->setFixedSize(45, 45);
        bullet->show();

        if (gamePage) {
            connect(bullet, &Bullet::enemyKilled, gamePage, &Gameplay_page::onEnemyKilled);
        }

        bullet->shoot(this->pos(), target);
    }
}



int Golmoshaki::getElixirCost() const
{
    return AgentBaseElixirCost;
}

Golmoshaki::~Golmoshaki()
{

}

void Golmoshaki::shot()
{
    timett->start(AgentBaseFireRate);
}


