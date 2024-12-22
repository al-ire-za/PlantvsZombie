#ifndef GAMEPLAY_PAGE_H
#define GAMEPLAY_PAGE_H

#include <QMainWindow>
#include <QLabel>
#include <QPoint>
#include "AgentBase.h"
#include "Enemy.h"



namespace Ui {
class Gameplay_page;
}

class Gameplay_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gameplay_page(QWidget *parent = nullptr);
    ~Gameplay_page();
    void create_enemi();
    void move_enemi(Enemy *enemi);
    void logEvent(const QString &event);
    void createRandomAgent(AgentBase *&agent);
    void updateAgentChoice(AgentBase *&currentChoice, int index);
    void initializeAgents();
    void printAgentBoard() const;
    void removeRandomAgentFromBoard();
    void startNextWave();


protected:
    void mousePressEvent(QMouseEvent *event) override;



private:
    Ui::Gameplay_page *ui;
    QTimer *timer;
    QVector<AgentBase*> agents;
    QVector<AgentBase*> agent_board;
    AgentBase *current_choice;
    AgentBase *agent_choice1;
    AgentBase *agent_choice2;
    AgentBase *agent_choice3;
    AgentBase *agent_choice4;
    QVector<Enemy*> enemies;
    int count_enemi;
    int wave;
    bool bossSpawned;
    void updateAgentsEnemies();


};

#endif // GAMEPLAY_PAGE_H
