#include "Kalam.h"
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

    if (target) {
        AgentBase::shootAt(QVector<Enemy*>{target});  // استفاده از target در فراخوانی تابع پایه
    }
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
