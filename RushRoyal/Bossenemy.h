#ifndef BOSSENEMY_H
#define BOSSENEMY_H
#include "Enemy.h"

namespace Ui {
class BossEnemy;
}

class BossEnemy : public Enemy
{
    Q_OBJECT

public:
    BossEnemy(QWidget *parent = nullptr);
    BossEnemy(const BossEnemy &other);
    virtual ~BossEnemy();
    void move() override;

private:
    Ui::BossEnemy *ui;
};

#endif // BOSSENEMY_H
