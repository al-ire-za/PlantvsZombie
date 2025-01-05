#include "Kalam.h"
#include "Bullet.h"
#include "Gameplay_page.h"
#include <QTimer>


Kalam::Kalam(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/kalam1.png", 22, 1400, 3)
{
    timett = new QTimer();
    connect(timett , &QTimer::timeout , this , &Kalam::shootAt );
}

Kalam::Kalam(const Kalam &other)
    : AgentBase(other){

}

void Kalam::shootAt()
{
    Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
    if (gamePage->enemies.isEmpty()|| isFrozen()) return;

    Enemy* target = nullptr;
    int maxHealth = 0;

    for (Enemy* enemy : gamePage->enemies) {
        if (enemy->gethealth() > maxHealth) {
            maxHealth = enemy->gethealth();
            target = enemy;
        }
    }

    Bullet* bullet = new Bullet(parentWidget(), AgentBasePower);
    bullet->setGeometry(geometry().center().x() - 5, geometry().y() - 20, 10, 20);
    bullet->setStyleSheet(QString("background-image: url(:/prefix2/images/tirkalam%1.png);").arg(gamePage->levels[2]));
    bullet->setFixedSize(40, 40);
    bullet->show();

    if (gamePage) {
        connect(bullet, &Bullet::enemyKilled, gamePage, &Gameplay_page::onEnemyKilled);
    }

    bullet->shoot(this->pos(), target);
}


int Kalam::getElixirCost() const
{
    return AgentBaseElixirCost;
}

void Kalam::shot(){
    timett->start(AgentBaseFireRate);
}

Kalam::~Kalam()
{

}
