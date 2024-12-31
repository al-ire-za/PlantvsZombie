#include "Disarmer.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QTimer>
#include "AgentBase.h"
#include "Bomb.h"
#include "Trap.h"

Disarmer::Disarmer(QWidget *parent, int health, double speed)
    : Enemy(parent, health, speed, ":/prefix2/images/Disaemer1.png")
{
    disarmTimer = new QTimer(this);
    connect(disarmTimer, &QTimer::timeout, this, &Disarmer::disarmTrapsAndBombs);
    disarmTimer->start(500);
}

Disarmer::Disarmer(const Disarmer &other)
    : Enemy(other)
{
    disarmTimer = new QTimer(this);
    connect(disarmTimer, &QTimer::timeout, this, &Disarmer::disarmTrapsAndBombs);
    disarmTimer->start(500);
}

void Disarmer::disarmTrapsAndBombs()
{
    QVector<AgentBase*> agents = parentWidget()->findChildren<AgentBase*>();
    for (AgentBase* agent : agents) {
        if (Bomb* bomb = dynamic_cast<Bomb*>(agent)) {
            if (geometry().intersects(bomb->geometry())) {
                bomb->hide();
                bomb->deleteLater(); // خنثی کردن بمب
            }
        } else if (Trap* trap = dynamic_cast<Trap*>(agent)) {
            if (geometry().intersects(trap->geometry())) {
                trap->hide();
                trap->deleteLater(); // خنثی کردن تله
            }
        }
    }


}

Disarmer::~Disarmer()
{
    delete disarmTimer;
}

void Disarmer::move() {
}


