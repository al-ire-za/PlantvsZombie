#ifndef GANDOM_H
#define GANDOM_H

#include "Agentbase.h"


namespace Ui {
class Gandom;
}

class Gandom : public AgentBase
{
    Q_OBJECT

public:
    explicit Gandom(QWidget *parent = nullptr);
    ~Gandom();

private:
    Ui::Gandom *ui;
};

#endif // GANDOM_H
