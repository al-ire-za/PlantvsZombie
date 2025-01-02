#include "Kalam.h"


Kalam::Kalam(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/kalam2.png", 22, 900, 3)
{

}

Kalam::Kalam(const Kalam &other)
    : AgentBase(other){

}

void Kalam::shootAt(const QVector<Enemy*>& enemies)
{
    if (enemies.isEmpty()|| isFrozen()) return;

    Enemy* target = nullptr;
    int maxHealth = 0;

    for (Enemy* enemy : enemies) {
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

Kalam::~Kalam()
{

}
