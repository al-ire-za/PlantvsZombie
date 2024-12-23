#include "Bullet.h"

Bullet::Bullet(QWidget *parent, int damage, const QPointF& direction)
    : QLabel(parent), damage(damage), direction(direction)
{
    setPixmap(QPixmap(":/prefix2/images/bullet.png")); // تصویر گلوله را تنظیم کنید
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::moveBullet);
    timer->start(50); // هر 50 میلی‌ثانیه حرکت کند
}

Bullet::~Bullet()
{
}

int Bullet::getDamage() const
{
    return damage;
}

void Bullet::moveBullet()
{
    // حرکت گلوله در جهت مشخص شده
    move(x() + direction.x(), y() + direction.y());
    if (x() < 0 || y() < 0 || x() > parentWidget()->width() || y() > parentWidget()->height()) {
        destroyBullet(); // حذف گلوله وقتی از صفحه خارج می‌شود
    }
}

void Bullet::destroyBullet()
{
    delete this; // حذف گلوله
}

