#include "Bomb.h"
#include "AgentBase.h"
#include "QLabel"
#include <QTimer>

Bomb::Bomb(QWidget *parent)
    :AgentBase(parent, ":/prefix2/images/bomb.png", 50, 1, 2),collisionCount(0),powerkill(2)
{
    timerStart = new QTimer(this);
    connect(timerStart, &QTimer::timeout, this, &Bomb::onTimeout);

}

Bomb::Bomb(const Bomb &other)
    :AgentBase(other){

}

void Bomb::startTimer() {
    timerStart->start(3000);
}

int Bomb::getElixirCost() const
{
    return AgentBaseElixirCost;
}

int Bomb::getcollisionCount() const{
    return collisionCount;
}

void Bomb::setpowerkill(int pow){
    powerkill = pow;
}

int Bomb::getpowerkill() const{
    return powerkill;
}

void Bomb::checkCollision(const QVector<Enemy*>& enemies)
{
    QVector<Enemy*> enemiesToRemove;
    for (Enemy* enemy : enemies) {
        if (geometry().intersects(enemy->geometry())) {
            enemiesToRemove.append(enemy);
            collisionCount++;
            if (collisionCount == powerkill) {
                break;
            }
        }
    }

    if (!enemiesToRemove.isEmpty()) {
        emit removeEnemies(enemiesToRemove);
    }

    if (collisionCount >= powerkill) {
        timerStart->stop();
    }
}


QTimer* Bomb::getTimer() const {
    return timerStart;
}

void Bomb::onTimeout()
{
    emit bombExpired(this);
}


Bomb::~Bomb()
{

}
