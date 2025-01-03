#include "Golmoshaki.h"
#include "AgentBase.h"
#include "Gameplay_page.h"
#include <qtimer.h>
#include <QTimer>


Golmoshaki::Golmoshaki(QWidget *parent)
    :AgentBase(parent, ":/prefix2/images/golmoshaki1.png", 15, 1200, 2)
{
    timett = new QTimer();
    connect(timett , &QTimer::timeout , this , &Golmoshaki::shootAt );
}

Golmoshaki::Golmoshaki(const Golmoshaki &other)
    : AgentBase(other){

}
//const QVector<Enemy*>& enemies
void Golmoshaki::shootAt()
{
    Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
    if (gamePage->enemies.isEmpty() || isFrozen()) return;

    Enemy* target = gamePage->enemies.first();  // هدف: نفر اول لیست

    if (target) {
        AgentBase::shootAt(QVector<Enemy*>{target});  // استفاده از target در فراخوانی تابع پایه
    }
}

int Golmoshaki::getElixirCost() const
{
    return AgentBaseElixirCost;
}

Golmoshaki::~Golmoshaki()
{

}

void Golmoshaki::shot()
{
    timett->start(AgentBaseFireRate);
}
