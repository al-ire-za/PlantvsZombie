
#include "Bullet.h"
#include "Enemy.h"

Bullet::Bullet(QWidget *parent, int damage)
    : QLabel(parent), animation(new QPropertyAnimation(this, "pos")), moveTimer(new QTimer(this)), checkTimer(new QTimer(this)), damage(damage) {
    setStyleSheet("background-color: black; border-radius: 5%;");
    setFixedSize(10, 10);
    connect(moveTimer, &QTimer::timeout, this, &Bullet::moveBullet);
    connect(animation, &QPropertyAnimation::finished, this, &Bullet::onAnimationFinished);
    connect(checkTimer, &QTimer::timeout, this, &Bullet::checkTarget);
}

void Bullet::shoot(const QPoint &start, Enemy *targetenemy) {
    this->targetenemy = targetenemy;
    move(start);
    show();

    animation->setDuration(2000);
    moveTimer->start(20);
}

void Bullet::moveBullet() {
    if (targetenemy) {
        QPoint targetPos = targetenemy->pos() + QPoint(targetenemy->width() / 2, targetenemy->height() / 2);
        QPoint currentPos = pos() + QPoint(width() / 2, height() / 2);

        int dx = targetPos.x() - currentPos.x();
        int dy = targetPos.y() - currentPos.y();

        currentPos.setX(currentPos.x() + dx / 10);
        currentPos.setY(currentPos.y() + dy / 10);

        move(currentPos - QPoint(width() / 2, height() / 2));

        if ((currentPos - (targetenemy->pos() + QPoint(targetenemy->width() / 2, targetenemy->height() / 2))).manhattanLength() < 60) {
            targetenemy->reduceHealth(damage); // کاهش سلامت انمی
            moveTimer->stop();
            delete this;
        }
    }
}

void Bullet::onAnimationFinished() {
    this->hide();
    delete this;
}

void Bullet::checkTarget() {
    if (!targetenemy->isalive()) {
        checkTimer->stop();
        this->hide();
        delete this;
    }
}
