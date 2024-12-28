#ifndef BULLET_H
#define BULLET_H

#include "Enemy.h"
#include <QLabel>
#include <QTimer>
#include <QPropertyAnimation>

class Bullet : public QLabel {
    Q_OBJECT

public:
    explicit Bullet(QWidget *parent = nullptr, int damage = 10);
    void shoot(const QPoint &start, Enemy *targetenemy);
    int getdamage() const;

private slots:
    void moveBullet();
    void onAnimationFinished();
    void checkTarget();

signals:
    void enemyKilled(Enemy* enemy);


private:
    QPropertyAnimation *animation;
    Enemy *targetenemy;
    QTimer *moveTimer;
    QTimer *checkTimer;
    int damage;
};

#endif


