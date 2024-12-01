#include "Bombice.h"
#include "Agentbase.h"

Bombice::Bombice(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/bomb_ice.png", 40, 2)

{

}

Bombice::Bombice(const Bombice &other)
    : AgentBase(other)
{

}


Bombice::~Bombice()
{

}
