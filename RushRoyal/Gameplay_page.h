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
    void incrementEnemyKilled();
    void updatePot(int, int);
    QVector<Enemy*> enemies;
    QList<int> levels;



protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void checkCollisions();
    void updateElixir();
    void removeEnemies(const QVector<Enemy*>& enemiesToRemove);
    void removeBombTrap(AgentBase* agent);


    void on_PGolmushaki_clicked();

    void on_PGorbemahi_clicked();

    void on_PKalam_clicked();

    void on_PGandom_clicked();

    void on_PBomb_clicked();

    void on_PTrap_clicked();

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
    AgentBase *last_clicked_agent;
    int last_clicked_index;
    Eraser *eraser;
    Freezer *freezer;
    Disarmer *disarmer;
    QTimer *elixirTimer;
    QLabel *elixirLabel;
    QLabel *enemyCountLabel1, *enemyCountLabel2, *enemyCountLabel3;
    QLabel *elixirText;
    QLabel *enemyImage;
    QLabel *waveProgressBackground;
    QLabel *waveProgressForeground;
    QLabel *waveProgressZombei;
    int elixir;
    int count_enemi;
    int wave;
    int usedElixir;
    int bossSpawned;
    bool waveInProgress;
    int enemi_wave;
    bool isGameOver;
    int enemyReachedEndCount;
    int enemiesKilled;
    int gandomLvl = 1,bombLvl = 1,trapLvl = 1,golmoshakiLvl = 1,kalamLvl = 1,gorbemahiLvl = 1;
    const int maxEnemiesAllowedToReachEnd = 3;
    void checkGameOver();
    void updateEnemyCountLabel();
    void updateAgentsEnemies();
    void updateWaveProgress();
    friend class Freezer;
    friend class Eraser;


};

#endif // GAMEPLAY_PAGE_H
