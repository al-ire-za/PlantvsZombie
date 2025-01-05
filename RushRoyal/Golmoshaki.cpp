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

void Golmoshaki::shootAt()
{
    Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
    if (gamePage->enemies.isEmpty() || isFrozen()) return;

    Enemy* target = gamePage->enemies.first();

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
