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
    explicit Gorbemahi(QWidget *parent = nullptr);
    ~Gorbemahi();

private:
    Ui::Gorbemahi *ui;
};

#endif // GORBEMAHI_H
