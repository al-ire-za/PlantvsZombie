#ifndef GORBEMAHI_H
#define GORBEMAHI_H

#include "Agentbase.h"

namespace Ui {
class Gorbemahi;
}

class Gorbemahi : public AgentBase
{
    Q_OBJECT

public:
    Gorbemahi(QWidget *parent = nullptr);
    Gorbemahi(const Gorbemahi &other);
    virtual ~Gorbemahi();

private:
    Ui::Gorbemahi *ui;
};

#endif // GORBEMAHI_H
