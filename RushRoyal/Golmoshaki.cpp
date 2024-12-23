#include "Golmoshaki.h"
#include "AgentBase.h"


Golmoshaki::Golmoshaki(QWidget *parent)
    :AgentBase(parent, ":/prefix2/images/golmoshaki2.png", 35, 1200)
{

}

Golmoshaki::Golmoshaki(const Golmoshaki &other)
    : AgentBase(other){

}

void Golmoshaki::shootAt(const QVector<Enemy*>& enemies)
{
    if (enemies.isEmpty()) return;

    Enemy* target = enemies.first();  // هدف: نفر اول لیست
    if (target) {
        AgentBase::shootAt(QVector<Enemy*>{target});  // استفاده از target در فراخوانی تابع پایه
    }
}

Golmoshaki::~Golmoshaki()
{

}
