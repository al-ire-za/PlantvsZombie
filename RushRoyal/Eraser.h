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
    Eraser(QWidget *parent = nullptr);
    Eraser(const Eraser &other);
    virtual ~Eraser();
    void move() override;

private:
    Ui::Eraser *ui;
};

#endif // ERASER_H
