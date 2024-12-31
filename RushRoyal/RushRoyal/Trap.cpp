#include "Trap.h"
#include "AgentBase.h"




Trap::Trap(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/trap.png", 40, 2, 2), collisionCount(0)

{

}

Trap::Trap(const Trap &other)
    : AgentBase(other)
{

}

int Trap::getElixirCost() const
{
    return AgentBaseElixirCost;
}

int Trap::getcollisionCount() const{
    return collisionCount;
}


void Trap::checkCollision(const QVector<Enemy*>& enemies)
{
    QVector<Enemy*> enemiesToRemove;
    for (Enemy* enemy : enemies) {
        if (geometry().intersects(enemy->geometry())) {
            enemiesToRemove.append(enemy);
            collisionCount++;
            if (collisionCount == 2) {
                break;
            }
        }
    }

    if (!enemiesToRemove.isEmpty()) {
        emit removeEnemies(enemiesToRemove);
    }
}


Trap::~Trap()
{

}
