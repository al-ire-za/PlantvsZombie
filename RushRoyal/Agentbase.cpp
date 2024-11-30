#include "Agentbase.h"

AgentBase::AgentBase(QWidget *parent, const QString &imageUrl, int power, int speed)
    : QLabel(parent), AgentBaseimageUrl(imageUrl), AgentBasePower(power), AgentBasespeed(speed)

{
    updateimagUrl(imageUrl);
}

AgentBase::~AgentBase()
{

}

int AgentBase::getpower() const{
    return AgentBasePower;
}

int AgentBase::getspeed() const{
    return AgentBasespeed;
}

void AgentBase::updateimagUrl(const QString &image){
    AgentBaseimageUrl = image;
    setStyleSheet("background-image: url(" + image + "); background-color: rgb(238, 145, 84);");
}
