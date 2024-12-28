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

signals:
    void removeEnemies(const QVector<Enemy*>& enemiesToRemove);

private:
    Ui::Trap *ui;
    int collisionCount;
};

#endif // TRAP_H
