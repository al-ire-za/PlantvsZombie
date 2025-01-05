#include "AgentBase.h"
#include "Gameplay_page.h"
#include "Bullet.h"
#include <QTimer>

AgentBase::AgentBase(QWidget *parent, const QString &imageUrl, int power, int firerate, int elixirCost)
    : QLabel(parent), AgentBaseimageUrl(imageUrl), AgentBaseFireRate(firerate), AgentBaseElixirCost(elixirCost), frozen(false), levelspeedup(1)

{
    updateimagUrl(imageUrl);
    setpower(power);

}

AgentBase::AgentBase(const AgentBase &other): AgentBasePower(other.AgentBasePower), AgentBaseFireRate(other.AgentBaseFireRate),
    AgentBaseimageUrl(other.AgentBaseimageUrl), frozen(false)
{
    updateimagUrl(other.AgentBaseimageUrl);
    shootTimer = new QTimer(this);
}

AgentBase::~AgentBase()
{

}

int AgentBase::getpower() const{
    return AgentBasePower;
}

double AgentBase::getspeed() const{
    return AgentBaseFireRate;
}

void AgentBase::updateimagUrl(const QString &image){
    AgentBaseimageUrl = image;
    setStyleSheet("background-image: url(" + image + ");");
}

void AgentBase::setpower(int po){
    AgentBasePower = po;
}


bool AgentBase::isFrozen() const
{
    return frozen;
}

void AgentBase::setFrozen(bool frozen)
{
    this->frozen = frozen;
    setEnabled(!frozen);
}

void AgentBase::setlevelspeedup(int level){
    levelspeedup = level;
}

int AgentBase::getlevelspeedup(){
    return levelspeedup;
}

void AgentBase::setAgentBaseFireRate(double fire){
    AgentBaseFireRate = fire;
}

double AgentBase::getAgentBaseFireRate(){
    return AgentBaseFireRate;
}
