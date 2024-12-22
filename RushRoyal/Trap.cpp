#include "Trap.h"
#include "AgentBase.h"




Trap::Trap(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/trap.png", 40, 2)

{

}

Trap::Trap(const Trap &other)
    : AgentBase(other)
{

}


Trap::~Trap()
{

}
