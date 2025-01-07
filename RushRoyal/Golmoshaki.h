#ifndef GOLMOSHAKI_H
#define GOLMOSHAKI_H

#include "Gameplay_page.h"

#include "AgentBase.h"


namespace Ui {
class Golmoshaki;
}

class Golmoshaki : public AgentBase
{
    Q_OBJECT

public:
    Golmoshaki(QWidget *parent = nullptr);
    Golmoshaki(const Golmoshaki &other);
    //void shootAt(const QVector<Enemy*>& enemies) override;
    void shootAt();
    int getElixirCost() const override;
    virtual ~Golmoshaki();
    int type() const override { return 2;}
    QTimer *timett;
    void shot();

private:
    Ui::Golmoshaki *ui;
    int calculateDistanceToFinish(Enemy* enemy);
    Enemy* findClosestEnemy(Gameplay_page* gamePage);
};

#endif // GOLMOSHAKI_H
