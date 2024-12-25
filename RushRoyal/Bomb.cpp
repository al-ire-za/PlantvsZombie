#include "Bomb.h"
#include "AgentBase.h"
#include "QLabel"
#include <QTimer>

Bomb::Bomb(QWidget *parent)
    :AgentBase(parent, ":/prefix2/images/bomb.png", 50, 1, 2),collisionCount(0)
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


void Bomb::checkCollision(const QVector<Enemy*>& enemies)
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

    // اگر برخوردها به ۲ رسید، تایمر را متوقف کنیم
    if (collisionCount >= 2) {
        timerStart->stop();
    }
}

QTimer* Bomb::getTimer() const {
    return timerStart;
}

void Bomb::onTimeout()
{
    emit bombExpired(this);  // ارسال سیگنال به پایان رسیدن بمب
}


Bomb::~Bomb()
{

}
