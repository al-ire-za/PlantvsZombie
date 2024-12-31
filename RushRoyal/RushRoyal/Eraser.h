#ifndef ERASER_H
#define ERASER_H

#include "Enemy.h"

namespace Ui {
class Eraser;
}

class Eraser : public Enemy
{
    Q_OBJECT

public:
    Eraser(QWidget *parent = nullptr, int health = 2000, double speed = 0.25);
    Eraser(const Eraser &other);
    virtual ~Eraser();
    void move() override;

private slots:
    void removeRandomAgent();


private:
    Ui::Eraser *ui;
    QTimer *eraseTimer;
    friend class Gameplay_page;
};

#endif // ERASER_H
