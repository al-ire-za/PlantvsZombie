#ifndef ENEMY_H
#define ENEMY_H

#include <QLabel>
#include <QSequentialAnimationGroup>


namespace Ui {
class Enemy;
}

class Enemy : public QLabel
{
    Q_OBJECT

public:
    Enemy(QWidget *parent = nullptr, int health = 100, double speed = 1, const QString &imageUrl = "");
    Enemy(const Enemy &other);
    virtual ~Enemy();
    virtual void move();
    int gethealth() const;
    double getspeed() const;
    void updateimage(const QString &imageUrl);
    void reduceHealth(int amount);
    bool isalive() const;
    void disable();
    void stopAllTimers();
    int preventBugForEnemyKillNum = 0;

protected:
    Ui::Enemy *ui;
    int EnemyHealth;
    double EnemySpeed;
    QString EnemyImageUrl;
    QSequentialAnimationGroup *animationGroup;
};

#endif // ENEMY_H
