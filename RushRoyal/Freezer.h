#ifndef FREEZER_H
#define FREEZER_H

#include "Enemy.h"

namespace Ui {
class Freezer;
}

class Freezer : public Enemy
{
    Q_OBJECT

public:
    Freezer(QWidget *parent = nullptr);
    Freezer(const Freezer &other);
    virtual ~Freezer();
    void move() override;

private:
    Ui::Freezer *ui;
};

#endif // FREEZER_H
