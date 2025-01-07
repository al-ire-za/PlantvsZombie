#include "Gandom.h"
#include "AgentBase.h"
#include "Bullet.h"
#include "Gameplay_page.h"
#include <QTimer>

Gandom::Gandom(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/gandom1.png", 15, 1200, 2)
{
    timett = new QTimer();
    connect(timett , &QTimer::timeout , this , &Gandom::shootAt );
}

Gandom::Gandom(const Gandom &other)
    :AgentBase(other){

}



// void Gandom::shootAt()
// {
//     Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
//     if (gamePage->enemies.isEmpty()|| isFrozen()) return;

//     Enemy* target = gamePage->enemies.last();

//     Bullet* bullet = new Bullet(parentWidget(), AgentBasePower);
//     bullet->setGeometry(geometry().center().x() - 5, geometry().y() - 20, 10, 20);
//     bullet->setStyleSheet(QString("background-image: url(:/prefix2/images/tirgandom%1.png);").arg(gamePage->levels[3]));
//     bullet->setFixedSize(50, 50);
//     bullet->show();

//     if (gamePage) {
//         connect(bullet, &Bullet::enemyKilled, gamePage, &Gameplay_page::onEnemyKilled);
//     }

//     bullet->shoot(this->pos(), target);
// }

int Gandom::calculateDistanceToFinish(Enemy* enemy) {
    QPointF enemyPos = enemy->pos();
    int distance = 0;

    // بخش اول از 215, 700 تا 215, 140
    if (enemyPos.x() == 215 && enemyPos.y() <= 700 && enemyPos.y() >= 140) {
        distance += (enemyPos.y() - 140) + (900 - 215) + (625 - 140);
    }
    // بخش دوم از 215, 140 تا 900, 140
    else if (enemyPos.y() == 140 && enemyPos.x() >= 215 && enemyPos.x() <= 900) {
        distance +=(900 - enemyPos.x()) + (625 - 140);
    }
    // بخش سوم از 900, 140 تا 900, 625
    else if (enemyPos.x() == 900 && enemyPos.y() >= 140 && enemyPos.y() <= 625) {
        distance += (625 - enemyPos.y());
    }

    return distance;
}

Enemy* Gandom::findFurthestEnemy(Gameplay_page* gamePage)
{
    Enemy* furthestEnemy = nullptr;
    int furthestDistance = 0;

    foreach(Enemy* enemy, gamePage->enemies) {
        int distance = calculateDistanceToFinish(enemy);
        if (distance > furthestDistance) { // بررسی بیشترین فاصله
            furthestEnemy = enemy;
            furthestDistance = distance;
        }
    }

    return furthestEnemy;
}

void Gandom::shootAt()
{
    Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
    if (!gamePage || gamePage->enemies.isEmpty() || isFrozen()) return;

    Enemy* target = findFurthestEnemy(gamePage); // تغییر نام تابع

    if (target) {
        Bullet* bullet = new Bullet(parentWidget(), AgentBasePower);
        bullet->setGeometry(geometry().center().x() - 5, geometry().y() - 20, 10, 20);
        bullet->setStyleSheet(QString("background-image: url(:/prefix2/images/tirgandom%1.png);").arg(gamePage->levels[3]));
        bullet->setFixedSize(50, 50);
        bullet->show();

        if (gamePage) {
            connect(bullet, &Bullet::enemyKilled, gamePage, &Gameplay_page::onEnemyKilled);
        }

        bullet->shoot(this->pos(), target);
    }
}



int Gandom::getElixirCost() const
{
    return AgentBaseElixirCost;
}

void Gandom::shot(){
    timett->start(AgentBaseFireRate);
}

Gandom::~Gandom()
{

}
