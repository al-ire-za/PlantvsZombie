#ifndef GOLMOSHAKI_H
#define GOLMOSHAKI_H

#include "Agentbase.h"


namespace Ui {
class Golmoshaki;
}

class Golmoshaki : public AgentBase
{
    Q_OBJECT

public:
    explicit Golmoshaki(QWidget *parent = nullptr);
    ~Golmoshaki();

private:
    Ui::Golmoshaki *ui;
};

#endif // GOLMOSHAKI_H
