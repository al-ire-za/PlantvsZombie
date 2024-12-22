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
    Disarmer(QWidget *parent = nullptr);
    Disarmer(const Disarmer &other);
    virtual ~Disarmer();
    void move() override;

private:
    Ui::Disarmer *ui;
};

#endif // DISARMER_H
