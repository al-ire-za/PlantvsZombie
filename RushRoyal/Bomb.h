#ifndef BOMB_H
#define BOMB_H

#include "Agentbase.h"


namespace Ui {
class Bomb;
}

class Bomb : public AgentBase
{
    Q_OBJECT

public:
    Bomb(QWidget *parent = nullptr);
    Bomb(const Bomb &other);
    virtual ~Bomb();

private:
    Ui::Bomb *ui;
};

#endif // BOMB_H
