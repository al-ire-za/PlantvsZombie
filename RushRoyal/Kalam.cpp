#include "Kalam.h"


Kalam::Kalam(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/kalam2.png", 20, 900)
{

}

Kalam::Kalam(const Kalam &other)
    : AgentBase(other){

}

void Kalam::shootAt(const QVector<Enemy*>& enemies)
{
    if (enemies.isEmpty()) return;

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

Kalam::~Kalam()
{

}
