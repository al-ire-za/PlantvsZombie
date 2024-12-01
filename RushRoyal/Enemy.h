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
    Enemy(QWidget *parent = nullptr, int health = 100, int speed = 1, const QString &imageUrl = "");
    Enemy(const Enemy &other);
    virtual ~Enemy();
    virtual void move();
    int gethealth() const;
    int getspeed() const;
    void updateimage(const QString &imageUrl);

protected:
    Ui::Enemy *ui;
    int EnemyHealth;
    int EnemySpeed;
    QString EnemyImageUrl;
    QSequentialAnimationGroup *animationGroup;
};

#endif // ENEMY_H
