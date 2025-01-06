#include "Gorbemahi.h"

#include "AgentBase.h"
#include "Bullet.h"
#include "Gameplay_page.h"
#include <QTimer>

Gorbemahi::Gorbemahi(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/gorbemahi1.png", 30, 200, 4)
{
    timett = new QTimer();
    connect(timett , &QTimer::timeout , this , &Gorbemahi::shootAt );
}

Gorbemahi::Gorbemahi(const Gorbemahi &other)
    :AgentBase(other){

}

void Gorbemahi::shootAt()
{

    Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
    if (gamePage->enemies.isEmpty()|| isFrozen()) return;

    int randomIndex = std::rand() % gamePage->enemies.size();
    Enemy* target = gamePage->enemies[randomIndex];

    Bullet* bullet = new Bullet(parentWidget(), AgentBasePower);
    bullet->setGeometry(geometry().center().x() - 5, geometry().y() - 20, 10, 20);
    bullet->setStyleSheet(QString("background-image: url(:/prefix2/images/tirgorbemahi%1.png);").arg(gamePage->levels[1]));
    bullet->setFixedSize(50, 50);
    bullet->show();


    if (gamePage) {
        connect(bullet, &Bullet::enemyKilled, gamePage, &Gameplay_page::onEnemyKilled);
    }

    bullet->shoot(this->pos(), target);
}

int Gorbemahi::getElixirCost() const
{
    return AgentBaseElixirCost;
}

void Gorbemahi::shot(){
    timett->start(AgentBaseFireRate);
}

Gorbemahi::~Gorbemahi()
{

}
