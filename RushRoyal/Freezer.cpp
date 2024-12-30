#include "Freezer.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QTimer>
#include "Gameplay_page.h"
Freezer::Freezer(QWidget *parent, int health, double speed)
    : Enemy(parent, health, speed, ":/prefix2/images/boss ezafiai1.png")
{
    freezeTimer = new QTimer(this);
    connect(freezeTimer, &QTimer::timeout, this, &Freezer::freezeRandomAgent);
    freezeTimer->start(5000);
}

Freezer::Freezer(const Freezer &other)
    : Enemy(other)
{
    freezeTimer = new QTimer(this);
    connect(freezeTimer, &QTimer::timeout, this, &Freezer::freezeRandomAgent);
    freezeTimer->start(5000);
}

Freezer::~Freezer()
{
    unfreezeAllAgents();
}


void Freezer::freezeRandomAgent()
{
    if (!this->isalive()) {
        return;
    }
    Gameplay_page* gamePage = qobject_cast<Gameplay_page*>(parentWidget());
    if (gamePage) {
        QVector<int> occupiedIndices;
        for (int i = 0; i < gamePage->agent_board.size(); ++i) {
            if (gamePage->agent_board[i] != nullptr) {
                occupiedIndices.append(i);
            }
        }

        if (!occupiedIndices.isEmpty()) {
            int randomIndex = occupiedIndices[std::rand() % occupiedIndices.size()];
            AgentBase* agent = gamePage->agent_board[randomIndex];
            if (agent) {
                agent->setFrozen(true);
                frozenAgents.append(agent);
                gamePage->logEvent(QString("Agent frozen at index %1.").arg(randomIndex));
            }
        }
    }
}

void Freezer::unfreezeAllAgents()
{
    for (AgentBase* agent : frozenAgents) {
        agent->setFrozen(false); // بازگرداندن ایجنت‌ها به حالت عادی
    }
    frozenAgents.clear();
}


void Freezer::move() {

}
