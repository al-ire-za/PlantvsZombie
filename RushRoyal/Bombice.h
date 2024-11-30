#ifndef BOMBICE_H
#define BOMBICE_H

#include "Agentbase.h"

namespace Ui {
class Bombice;
}

class Bombice : public AgentBase
{
    Q_OBJECT

public:
    explicit Bombice(QWidget *parent = nullptr);
    ~Bombice();

private:
    Ui::Bombice *ui;
};

#endif // BOMBICE_H
