#include "Bomb.h"
#include "Agentbase.h"
#include "QLabel"


Bomb::Bomb(QWidget *parent)
    :AgentBase(parent, ":/prefix2/images/bomb.png", 50, 1)
{

}

Bomb::Bomb(const Bomb &other)
    :AgentBase(other){

}

Bomb::~Bomb()
{

}
