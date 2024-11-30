#include "Gandom.h"
#include "Agentbase.h"


Gandom::Gandom(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/gandom22.png", 10, 1)
{

}

Gandom::Gandom(const Gandom &other)
    :AgentBase(other){

}


Gandom::~Gandom()
{

}
