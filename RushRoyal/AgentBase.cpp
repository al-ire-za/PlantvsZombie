#include "AgentBase.h"
#include "Bullet.h"
#include <QTimer>

AgentBase::AgentBase(QWidget *parent, const QString &imageUrl, int power, int firerate)
    : QLabel(parent), AgentBaseimageUrl(imageUrl), AgentBasePower(power), AgentBaseFireRate(firerate)

{
    updateimagUrl(imageUrl);

}

AgentBase::AgentBase(const AgentBase &other): AgentBasePower(other.AgentBasePower), AgentBaseFireRate(other.AgentBaseFireRate),
    AgentBaseimageUrl(other.AgentBaseimageUrl)
{
    updateimagUrl(other.AgentBaseimageUrl);
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
    setStyleSheet("background-image: url(" + image + "); background-color: rgb(238, 145, 84);");
}


void AgentBase::shootAt(const QVector<Enemy*>& enemies)
{
    if (enemies.isEmpty()) return;

    Enemy* target = enemies.first(); // به عنوان مثال: شلیک به اولین انمی در لیست
    if (!target) return;

    QPointF direction = target->geometry().center() - geometry().center();
    qreal length = std::sqrt(direction.x() * direction.x() + direction.y() * direction.y());
    direction /= length; // نرمال کردن جهت برای حرکت یکنواخت

    Bullet* bullet = new Bullet(parentWidget(), AgentBasePower, direction * 10); // تنظیم جهت و سرعت گلوله
    bullet->setGeometry(geometry().center().x() - 5, geometry().y() - 20, 10, 20);
    bullet->show();
}

