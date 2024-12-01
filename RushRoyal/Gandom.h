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
    Gandom(QWidget *parent = nullptr);
    Gandom(const Gandom &other);
    virtual ~Gandom();

private:
    Ui::Gandom *ui;
};

#endif // GANDOM_H
