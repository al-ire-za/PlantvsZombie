#ifndef TRAP_H
#define TRAP_H

#include "AgentBase.h"

namespace Ui {
class Trap;
}

class Trap : public AgentBase
{
    Q_OBJECT

public:
    Trap(QWidget *parent = nullptr);
    Trap(const Trap &other);
    virtual ~Trap();

private:
    Ui::Trap *ui;
};

#endif // TRAP_H
