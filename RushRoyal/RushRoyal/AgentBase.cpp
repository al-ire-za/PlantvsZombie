#include "AgentBase.h"
#include "Gameplay_page.h"
#include "Bullet.h"
#include <QTimer>

AgentBase::AgentBase(QWidget *parent, const QString &imageUrl, int power, int firerate, int elixirCost)
    : QLabel(parent), AgentBaseimageUrl(imageUrl), AgentBasePower(power), AgentBaseFireRate(firerate), AgentBaseElixirCost(elixirCost), frozen(false)

{
    updateimagUrl(imageUrl);
    shootTimer = new QTimer(this);

}

AgentBase::AgentBase(const AgentBase &other): AgentBasePower(other.AgentBasePower), AgentBaseFireRate(other.AgentBaseFireRate),
    AgentBaseimageUrl(other.AgentBaseimageUrl), frozen(false)
{
    updateimagUrl(other.AgentBaseimageUrl);
    shootTimer = new QTimer(this);
}

AgentBase::~AgentBase()
{

}

int AgentBase::getpower() const{
    return AgentBasePower;
}

double AgentBase::getspeed() const{
    return AgentBaseFireRate;
}

void AgentBase::updateimagUrl(const QString &image){
    AgentBaseimageUrl = image;
    setStyleSheet("background-image: url(" + image + ");");
}


void AgentBase::shootAt(const QVector<Enemy*>& enemies)
{
    if (enemies.isEmpty()) return;

    Enemy* target = enemies.first();
    if (!target || !target->isalive()) return;

    Bullet* bullet = new Bullet(parentWidget(), AgentBasePower);
    bullet->setGeometry(geometry().center().x() - 5, geometry().y() - 20, 10, 20);
    bullet->show();

    Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
    if (gamePage) {
        connect(bullet, &Bullet::enemyKilled, gamePage, &Gameplay_page::onEnemyKilled);
    }

    bullet->shoot(this->pos(), target);
<<<<<<< HEAD:RushRoyal/RushRoyal/AgentBase.cpp
=======
}

bool AgentBase::isFrozen() const
{
    return frozen;
}

void AgentBase::setFrozen(bool frozen)
{
    this->frozen = frozen;
    setEnabled(!frozen);
>>>>>>> 2810e8069d1a50aa421431c3fe073b5bae208eb1:RushRoyal/AgentBase.cpp
}

void AgentBase::stopShooting()
{
    shootTimer->stop();
}

void AgentBase::startShooting()
{

    shootTimer->start(AgentBaseFireRate * 1000);

}

