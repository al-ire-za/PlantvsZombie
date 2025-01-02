#include "Eraser.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QTimer>
#include "Gameplay_page.h"

Eraser::Eraser(QWidget *parent, int health, double speed)
    : Enemy(parent, health, speed, ":/prefix2/images/Eraser.png")
{
    eraseTimer = new QTimer(this);
    connect(eraseTimer, &QTimer::timeout, this, &Eraser::removeRandomAgent);
    eraseTimer->start(3000);
}

Eraser::Eraser(const Eraser &other)
    : Enemy(other)
{
    eraseTimer = new QTimer(this);
    connect(eraseTimer, &QTimer::timeout, this, &Eraser::removeRandomAgent);
    eraseTimer->start(3000);
}

void Eraser::removeRandomAgent()
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
                gamePage->removeAgentFromBoard(agent);  // استفاده از تابع برای حذف ایجنت
                gamePage->logEvent(QString("Agent removed from agent_board at index %1 by Eraser.").arg(randomIndex));
            }
        }
    }
}

Eraser::~Eraser() {
    delete eraseTimer;
}

void Eraser::move() {

}
