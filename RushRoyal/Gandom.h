#ifndef GANDOM_H
#define GANDOM_H

#include "AgentBase.h"
#include "Gameplay_page.h"


namespace Ui {
class Gandom;
}

class Gandom : public AgentBase
{
    Q_OBJECT

public:
    Gandom(QWidget *parent = nullptr);
    Gandom(const Gandom &other);
    void shootAt() ;
    int getElixirCost() const override;
    virtual ~Gandom();
    int type() const override { return 1;}
    QTimer *timett;
    void shot();

private:
    Ui::Gandom *ui;
    int calculateDistanceToFinish(Enemy* enemy);
    Enemy* findFurthestEnemy(Gameplay_page* gamePage);
};

#endif // GANDOM_H
