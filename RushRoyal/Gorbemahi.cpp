#include "Gorbemahi.h"

#include "AgentBase.h"

Gorbemahi::Gorbemahi(QWidget *parent)
    : AgentBase(parent, ":/prefix2/images/gorbemahi2.png", 25, 1000)
{

}

Gorbemahi::Gorbemahi(const Gorbemahi &other)
    :AgentBase(other){

}

Gorbemahi::~Gorbemahi()
{

}
