#ifndef DISARMER_H
#define DISARMER_H
#include "Enemy.h"

namespace Ui {
class Disarmer;
}

class Disarmer : public Enemy
{
    Q_OBJECT

public:
    Disarmer(QWidget *parent = nullptr, int health = 2000, double speed = 0.25);
    Disarmer(const Disarmer &other);
    virtual ~Disarmer();
    void move() override;

private slots:
    void disarmTrapsAndBombs();

private:
    Ui::Disarmer *ui;
    QTimer *disarmTimer;
    friend class Gameplay_page;
};

#endif // DISARMER_H
