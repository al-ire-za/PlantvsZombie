#ifndef GOLMOSHAKI_H
#define GOLMOSHAKI_H

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
    void shootAt(const QVector<Enemy*>& enemies) override;
    int getElixirCost() const override;
    virtual ~Golmoshaki();
    int type() const override { return 2;}

private:
    Ui::Golmoshaki *ui;
};

#endif // GOLMOSHAKI_H
