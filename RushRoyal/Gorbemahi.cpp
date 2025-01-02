#include "Gorbemahi.h"

#include "AgentBase.h"

Gorbemahi::Gorbemahi(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/gorbemahi2.png", 30, 1000, 4)
{

}

Gorbemahi::Gorbemahi(const Gorbemahi &other)
    :AgentBase(other){

}

void Gorbemahi::shootAt(const QVector<Enemy*>& enemies)
{
    if (enemies.isEmpty()|| isFrozen()) return;

    int randomIndex = std::rand() % enemies.size();
    Enemy* target = enemies[randomIndex];  // هدف: انمی تصادفی

    if (target) {
        AgentBase::shootAt(QVector<Enemy*>{target});  // استفاده از target در فراخوانی تابع پایه
    }
}

int Gorbemahi::getElixirCost() const
{
    return AgentBaseElixirCost;
}


Gorbemahi::~Gorbemahi()
{

}
