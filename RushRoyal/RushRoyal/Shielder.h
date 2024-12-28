#ifndef SHIELDER_H
#define SHIELDER_H

#include "Enemy.h"

namespace Ui {
class Shielder;
}

class Shielder : public Enemy
{
    Q_OBJECT

public:
    Shielder(QWidget *parent = nullptr);
    Shielder(const Shielder &other);
    virtual ~Shielder();
    void move() override;

private:
    Ui::Shielder *ui;
};

#endif // SHIELDER_H
