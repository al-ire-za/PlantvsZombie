#include "AgentBase.h"
#include "Bullet.h"
#include <QTimer>

AgentBase::AgentBase(QWidget *parent, const QString &imageUrl, int power, int firerate, int elixirCost)
    : QLabel(parent), AgentBaseimageUrl(imageUrl), AgentBasePower(power), AgentBaseFireRate(firerate), AgentBaseElixirCost(elixirCost)

{
    updateimagUrl(imageUrl);
    shootTimer = new QTimer(this);

}

AgentBase::AgentBase(const AgentBase &other): AgentBasePower(other.AgentBasePower), AgentBaseFireRate(other.AgentBaseFireRate),
    AgentBaseimageUrl(other.AgentBaseimageUrl)
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


void AgentBase::shootAt(const QVector<Enemy*>& enemies)
{
    if (enemies.isEmpty()) return;

    Enemy* target = enemies.first(); // به عنوان مثال: شلیک به اولین انمی در لیست
    if (!target || !target->isalive()) return;

    Bullet* bullet = new Bullet(parentWidget(), AgentBasePower); // تنظیم قدرت گلوله
    bullet->setGeometry(geometry().center().x() - 5, geometry().y() - 20, 10, 20);
    bullet->show();
    bullet->shoot(this->pos(), target); // شروع به شلیک تیر
}

void AgentBase::stopShooting()
{
    shootTimer->stop(); // متوقف کردن تایمر شلیک
}

void AgentBase::startShooting()
{

    shootTimer->start(AgentBaseFireRate * 1000); // شروع تایمر شلیک

}

