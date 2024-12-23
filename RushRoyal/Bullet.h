#ifndef BULLET_H
#define BULLET_H

#include <QLabel>
#include <QTimer>
#include <QPointF>

class Bullet : public QLabel
{
    Q_OBJECT

public:
    Bullet(QWidget *parent = nullptr, int damage = 10, const QPointF& direction = QPointF());
    ~Bullet();

    int getDamage() const;

public slots:
    void moveBullet();
    void destroyBullet();

private:
    int damage;
    QTimer *timer;
    QPointF direction;
};

#endif // BULLET_H
