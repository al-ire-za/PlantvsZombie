#ifndef GAMEPLAY_PAGE_H
#define GAMEPLAY_PAGE_H

#include <QMainWindow>
#include <QLabel>
#include <QPoint>
#include "AgentBase.h"
#include "Enemy.h"
#include "Disarmer.h"
#include "Eraser.h"
#include "Freezer.h"



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
    void startNextWave();
    void removeAgentFromBoard(AgentBase* agent);
    void checkWaveCompletion();


protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void checkCollisions();
    void agentShoot();
    void updateElixir();
    void removeEnemies(const QVector<Enemy*>& enemiesToRemove);
    void removeBombTrap(AgentBase* agent);
    void createBoss();

public slots:
    void onEnemyKilled(Enemy* enemy);


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
    Eraser *eraser;
    Freezer *freezer;
    Disarmer *disarmer;
    QVector<Enemy*> enemies;
    QTimer *elixirTimer;
    QLabel *elixirLabel;
    QTimer *shootTimer;
    QLabel *enemyCountLabel;
    int elixir;
    int count_enemi;
    int wave;
    bool bossSpawned;
    bool waveInProgress;
    int enemyReachedEndCount;
    const int maxEnemiesAllowedToReachEnd = 3;
    void checkGameOver();
    void updateEnemyCountLabel();
    void updateAgentsEnemies();
    friend class Freezer;
    friend class Eraser;


};

#endif // GAMEPLAY_PAGE_H
