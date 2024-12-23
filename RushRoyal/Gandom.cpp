#include "Gandom.h"
#include "AgentBase.h"

Gandom::Gandom(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/gandom22.png", 15, 800)
{

}

Gandom::Gandom(const Gandom &other)
    :AgentBase(other){

}



void Gandom::shootAt(const QVector<Enemy*>& enemies)
{
    if (enemies.isEmpty()) return;

    Enemy* target = enemies.last();  // هدف: نفر آخر لیست
    if (target) {
        AgentBase::shootAt(QVector<Enemy*>{target});  // استفاده از target در فراخوانی تابع پایه
    }
}



Gandom::~Gandom()
{

}
