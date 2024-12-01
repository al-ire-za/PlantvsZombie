#ifndef SOLDIERENEMY_H
#define SOLDIERENEMY_H

#include "Enemy.h"
#include <QLabel>

namespace Ui {
class SoldierEnemy;
}

class SoldierEnemy : public Enemy
{
    Q_OBJECT

public:
    SoldierEnemy(QWidget *parent = nullptr);
    SoldierEnemy(const SoldierEnemy &other);
    virtual ~SoldierEnemy();
    void move() override;

private:
    Ui::SoldierEnemy *ui;
};

#endif // SOLDIERENEMY_H
