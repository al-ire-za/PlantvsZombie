#ifndef TRAP_H
#define TRAP_H

#include "AgentBase.h"

namespace Ui {
class Trap;
}

class Trap : public AgentBase
{
    Q_OBJECT

public:
    Trap(QWidget *parent = nullptr);
    Trap(const Trap &other);
    int getElixirCost() const override;
    virtual ~Trap();
    void checkCollision(const QVector<Enemy*>& enemies);
    int getcollisionCount() const;
    int type() const override { return 6;}
    void setpowerkill(int pow);
    int getpowerkill() const;
    QTimer *timerStart;
    void startTimer();

signals:
    void removeEnemies(const QVector<Enemy*>& enemiesToRemove);
    void bombExpired(Trap* tarp);
    void enemyKilledByTrap();

private slots:
    void onTimeout();


private:
    Ui::Trap *ui;
    int powerkill;
    int collisionCount;
};

#endif // TRAP_H
