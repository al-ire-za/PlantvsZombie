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
    explicit Bomb(QWidget *parent = nullptr);
    ~Bomb();

private:
    Ui::Bomb *ui;
};

#endif // BOMB_H
