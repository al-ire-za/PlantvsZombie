#ifndef RUNNER_H
#define RUNNER_H

#include "Enemy.h"

namespace Ui {
class Runner;
}

class Runner : public Enemy
{
    Q_OBJECT

public:
    Runner(QWidget *parent = nullptr, int health = 50, double speed = 1.00);
    Runner(const Runner &other);
    virtual ~Runner();
    void move() override;

private:
    Ui::Runner *ui;
};

#endif // RUNNER_H
