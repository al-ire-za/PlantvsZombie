#include "Gandom.h"
#include "AgentBase.h"

Gandom::Gandom(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/gandom22.png", 15, 800)
{

}

Gandom::Gandom(const Gandom &other)
    :AgentBase(other){

}


Gandom::~Gandom()
{

}
