#include "Gorbemahi.h"

#include "AgentBase.h"
#include "Gameplay_page.h"
#include <QTimer>

Gorbemahi::Gorbemahi(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/gorbemahi1.png", 30, 1000, 4)
{
    timett = new QTimer();
    connect(timett , &QTimer::timeout , this , &Gorbemahi::shootAt );
}

Gorbemahi::Gorbemahi(const Gorbemahi &other)
    :AgentBase(other){

}

// const QVector<Enemy*>& enemies
void Gorbemahi::shootAt()
{

    Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
    if (gamePage->enemies.isEmpty()|| isFrozen()) return;

    int randomIndex = std::rand() % gamePage->enemies.size();
    Enemy* target = gamePage->enemies[randomIndex];  // هدف: انمی تصادفی

    if (target) {
        AgentBase::shootAt(QVector<Enemy*>{target});  // استفاده از target در فراخوانی تابع پایه
    }
}

int Gorbemahi::getElixirCost() const
{
    return AgentBaseElixirCost;
}

void Gorbemahi::shot(){
    timett->start(AgentBaseFireRate);
}

Gorbemahi::~Gorbemahi()
{

}
