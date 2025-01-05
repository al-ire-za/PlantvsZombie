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



void Gandom::shootAt()
{
    Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
    if (gamePage->enemies.isEmpty()|| isFrozen()) return;

    Enemy* target = gamePage->enemies.last();

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
