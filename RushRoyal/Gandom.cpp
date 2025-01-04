#include "Gandom.h"
#include "AgentBase.h"
#include "Gameplay_page.h"
#include <QTimer>

Gandom::Gandom(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/gandom1.png", 15, 1200, 2)
{
    timett = new QTimer();
    connect(timett , &QTimer::timeout , this , &Gandom::shootAt );
}

Gandom::Gandom(const Gandom &other)
    :AgentBase(other){

}



void Gandom::shootAt()
{
    Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
    if (gamePage->enemies.isEmpty()|| isFrozen()) return;

    Enemy* target = gamePage->enemies.last();  // هدف: نفر آخر لیست

    if (target) {
        AgentBase::shootAt(QVector<Enemy*>{target});  // استفاده از target در فراخوانی تابع پایه
    }
}

int Gandom::getElixirCost() const
{
    return AgentBaseElixirCost;
}

void Gandom::shot(){
    timett->start(AgentBaseFireRate);
}

Gandom::~Gandom()
{

}
