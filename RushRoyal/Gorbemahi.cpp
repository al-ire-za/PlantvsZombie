#include "Gorbemahi.h"

#include "AgentBase.h"

Gorbemahi::Gorbemahi(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/gorbemahi2.png", 25, 1000)
{

}

Gorbemahi::Gorbemahi(const Gorbemahi &other)
    :AgentBase(other){

}

void Gorbemahi::shootAt(const QVector<Enemy*>& enemies)
{
    if (enemies.isEmpty()) return;

    int randomIndex = std::rand() % enemies.size();
    Enemy* target = enemies[randomIndex];  // هدف: انمی تصادفی
    if (target) {
        AgentBase::shootAt(QVector<Enemy*>{target});  // استفاده از target در فراخوانی تابع پایه
    }
}

Gorbemahi::~Gorbemahi()
{

}
