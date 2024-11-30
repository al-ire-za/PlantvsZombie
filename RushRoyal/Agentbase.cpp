#include "Agentbase.h"

AgentBase::AgentBase(QWidget *parent, const QString &imageUrl, int power, int speed)
    : QLabel(parent), AgentBaseimageUrl(imageUrl), AgentBasePower(power), AgentBaseSpeed(speed)

{
    updateimagUrl(imageUrl);
}

AgentBase::AgentBase(const AgentBase &other): AgentBasePower(other.AgentBasePower), AgentBaseSpeed(other.AgentBaseSpeed),
    AgentBaseimageUrl(other.AgentBaseimageUrl){
    updateimagUrl(other.AgentBaseimageUrl);
}

AgentBase::~AgentBase()
{

}

int AgentBase::getpower() const{
    return AgentBasePower;
}

int AgentBase::getspeed() const{
    return AgentBaseSpeed;
}

void AgentBase::updateimagUrl(const QString &image){
    AgentBaseimageUrl = image;
    setStyleSheet("background-image: url(" + image + "); background-color: rgb(238, 145, 84);");
}
