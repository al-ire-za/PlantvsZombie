#include "Kalam.h"


Kalam::Kalam(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/kalam2.png", 20, 900)
{

}

Kalam::Kalam(const Kalam &other)
    : AgentBase(other){

}


Kalam::~Kalam()
{

}
