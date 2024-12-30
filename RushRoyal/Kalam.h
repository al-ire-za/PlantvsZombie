#ifndef KALAM_H
#define KALAM_H

#include <QLabel>
#include "AgentBase.h"

namespace Ui {
class Kalam;
}

class Kalam : public AgentBase
{
    Q_OBJECT

public:
    Kalam(QWidget *parent = nullptr);
    Kalam(const Kalam &other);
    void shootAt(const QVector<Enemy*>& enemies) override;
    int getElixirCost() const override;
    virtual ~Kalam();
    int type() const override { return 4;}

private:
    Ui::Kalam *ui;
};

#endif // KALAM_H
