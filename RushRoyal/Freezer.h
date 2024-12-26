#ifndef FREEZER_H
#define FREEZER_H

#include "Enemy.h"
#include "AgentBase.h"

namespace Ui {
class Freezer;
}

class Freezer : public Enemy
{
    Q_OBJECT

public:
    Freezer(QWidget *parent = nullptr);
    Freezer(const Freezer &other);
    virtual ~Freezer();
    void move() override;


private slots:
    void freezeRandomAgent();
    void unfreezeAllAgents();

private:
    Ui::Freezer *ui;
    QTimer *freezeTimer;
    QVector<AgentBase*> frozenAgents;
    friend class Gameplay_page;
};

#endif // FREEZER_H
