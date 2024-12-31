#ifndef GORBEMAHI_H
#define GORBEMAHI_H

#include "AgentBase.h"

namespace Ui {
class Gorbemahi;
}

class Gorbemahi : public AgentBase
{
    Q_OBJECT

public:
    Gorbemahi(QWidget *parent = nullptr);
    Gorbemahi(const Gorbemahi &other);
    void shootAt(const QVector<Enemy*>& enemies) override;
    int getElixirCost() const override;
    virtual ~Gorbemahi();
    int type() const override { return 3;}

private:
    Ui::Gorbemahi *ui;
};

#endif // GORBEMAHI_H
