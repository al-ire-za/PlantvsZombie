#include "Gameplay_page.h"
#include "ui_Gameplay_page.h"
#include "ResultWindow.h"
#include "Gorbemahi.h"
#include "Gandom.h"
#include "Golmoshaki.h"
#include "Bomb.h"
#include "Trap.h"
#include "Enemy.h"
#include "Kalam.h"
#include "Eraser.h"
#include "Freezer.h"
#include "Disarmer.h"
#include "Runner.h"
#include "Shielder.h"
#include <QGuiApplication>
#include <QScreen>
#include <QLabel>
#include <QFrame>
#include <QPropertyAnimation>
#include <QTime>
#include <QSequentialAnimationGroup>
#include <QVector>
#include <QDebug>
#include <QTimer>
#include <QMouseEvent>
#include <QPoint>
#include <QFile>
#include <QTextStream>
#include <QThread>



const int width_aghent_choice = 90;
const int hight_aghent_choice = 80;
const int startx_agent_choice = 385;
const int starty_aghant_choice = 640;
const int spacing = 100;


const int width_agent_board = 90;
const int height_agent_board = 80;
const int startX = 350;
const int startY = 250;
const int xOffset = 140;
const int yOffset = 90;


Gameplay_page::Gameplay_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gameplay_page),count_enemi(0), wave(1), bossSpawned(false), elixir(5), waveInProgress(true)
{
    ui->setupUi(this);
    setMaximumSize(1200, 800);
    setMinimumSize(1200, 800);
    std::srand(time(NULL));
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenRect = screen->availableGeometry();
    int x = (screenRect.width() - width()) / 2;
    int y = (screenRect.height() - height()) / 2;
    move(x, y);


    enemyReachedEndCount = 0;
    enemyCountLabel = new QLabel(this);
    enemyCountLabel->setObjectName("enemyCountLabel");
    enemyCountLabel->setGeometry(1010,600, 60, 20);
    enemyCountLabel->setText("0");
    enemyCountLabel->setStyleSheet("background-color: white; border: 2px solid black; font: bold 14px; text-align: center;");

    agent_choice1 = new Gorbemahi(this);
    agent_choice1->setGeometry(startx_agent_choice, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    agent_choice2 = new Golmoshaki(this);
    agent_choice2->setGeometry(startx_agent_choice + spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    agent_choice3 = new Kalam(this);
    agent_choice3->setGeometry(startx_agent_choice + 2 * spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    agent_choice4 = new Bomb(this);
    agent_choice4->setGeometry(startx_agent_choice + 3 * spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);


    eraser = nullptr;
    disarmer = nullptr;
    freezer = nullptr;

    agent_board.resize(16);
    for (int i = 0; i < 16; ++i) {
        agent_board[i] = nullptr;

    }

    current_choice = nullptr;
    isGameOver = false;
    usedElixir = 0;
    elixirLabel = new QLabel(this);
    elixirLabel->setGeometry(790, 655, 50, 50);
    elixirLabel->setStyleSheet("background-image: url(:/prefix2/images/banafsh.png); border-radius: 25px; color: white; text-align: center;font-weight: bold;");
    elixirLabel->setAlignment(Qt::AlignCenter);
    elixirLabel->setText(QString::number(elixir));
    elixirLabel->show();

    elixirTimer = new QTimer(this);
    connect(elixirTimer, &QTimer::timeout, this, &Gameplay_page::updateElixir);
    elixirTimer->start(2000);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gameplay_page::create_enemi);
    timer->start(2000); //5000

    shootTimer = new QTimer(this);
    connect(shootTimer, &QTimer::timeout, this, &Gameplay_page::agentShoot);
    shootTimer->start(1000); // هر 1 ثانیه ایجنت‌ها شلیک کنند

    QTimer *collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &Gameplay_page::checkCollisions);
    collisionTimer->start(50); // هر 50 میلی‌ثانیه برخوردها را بررسی می‌کند
}

void Gameplay_page::agentShoot()
{
    for (AgentBase* agent : agent_board) {
        if (agent != nullptr) {
            agent->shootAt(enemies);
        }
    }
}


void Gameplay_page::create_enemi()
{
    if (waveInProgress) {
        Enemy *new_enemy = nullptr;
        int enemyType = std::rand() % 2;

        int baseHealth = 0;
        double baseSpeed = 0.0;

        switch (enemyType) {
        case 0:
            baseHealth = 50;
            baseSpeed = 1.5;
            break;
        case 1:
            baseHealth = 100;
            baseSpeed = 1.5;
            break;
        }

        int currentHealth = static_cast<int>(baseHealth * std::pow(1.1, wave - 1));
        double currentSpeed = baseSpeed * std::pow(1.1, wave - 1);

        switch (enemyType) {
        case 0:
            new_enemy = new Runner(this, currentHealth, currentSpeed);
            break;
        case 1:
            new_enemy = new Shielder(this, currentHealth, currentSpeed);
            break;
        }

        if (new_enemy != nullptr) {
            new_enemy->setGeometry(220, 700, 90, 80);
            new_enemy->show();
            enemies.append(new_enemy);
            move_enemi(new_enemy);
            logEvent(QString("Enemy (type %1) #%2 created.").arg(enemyType).arg(++count_enemi));
        } else {
            logEvent("Failed to create new enemy.");
        }

        if (wave % 2 == 0 && !bossSpawned) {
            createBoss();

        }

        if (count_enemi % 5 == 0 && count_enemi != 0) {
            waveInProgress = false;
            logEvent(QString("Wave %1 completed.").arg(wave));
            checkWaveCompletion();
        } else {
            timer->start(500);
        }
    }
}

void Gameplay_page::createBoss()
{
    if (!bossSpawned) {
        int bossType = std::rand() % 3;
        Enemy *boss_enemy = nullptr;

        int baseHealth = 0;
        double baseSpeed = 0.0;

        switch (bossType) {
        case 0:
            baseHealth = 2000;
            baseSpeed = 0.25;
            break;
        case 1:
            baseHealth = 2000;
            baseSpeed = 0.25;
            break;
        case 2:
            baseHealth = 2000;
            baseSpeed = 0.25;
            break;
        }

        int currentHealth = static_cast<int>(baseHealth * std::pow(1.1, wave - 1));
        double currentSpeed = baseSpeed * std::pow(1.1, wave - 1);

        switch (bossType) {
        case 0:
            boss_enemy = new Eraser(this, currentHealth, currentSpeed);
            break;
        case 1:
            boss_enemy = new Freezer(this, currentHealth, currentSpeed);
            break;
        case 2:
            boss_enemy = new Disarmer(this, currentHealth, currentSpeed);
            break;
        }


        if (boss_enemy != nullptr) {
            boss_enemy->setGeometry(220, 700, 90, 80);
            boss_enemy->show();
            enemies.append(boss_enemy);
            move_enemi(boss_enemy);
            logEvent(QString("Boss enemy (type %1) created.").arg(bossType));
            bossSpawned = true;

            QTimer *abilityTimer = new QTimer(this);
            switch (bossType) {
            case 0:
                connect(abilityTimer, &QTimer::timeout, eraser, &Eraser::removeRandomAgent);
                break;
            case 1:
                connect(abilityTimer, &QTimer::timeout, freezer, &Freezer::freezeRandomAgent);
                break;
            case 2:
                connect(abilityTimer, &QTimer::timeout, disarmer, &Disarmer::disarmTrapsAndBombs);
                break;
            }
            abilityTimer->start(5000);
        } else {
            logEvent("Failed to create boss enemy.");
        }
    }
}

void Gameplay_page::checkWaveCompletion()
{
    if (enemies.isEmpty()) {
        waveInProgress = false;
        QTimer::singleShot(3000, this, [this]() {
            wave++;
            count_enemi = 0;
            bossSpawned = false;
            waveInProgress = true;
            logEvent(QString("Starting wave %1...").arg(wave));
            create_enemi();
        });
    }
}

void Gameplay_page::move_enemi(Enemy *enemy) {
    double durationFactor = 1000.0 / enemy->getspeed();

    QPropertyAnimation *animation1 = new QPropertyAnimation(enemy, "geometry");
    animation1->setDuration(static_cast<int>(durationFactor * 5));
    animation1->setStartValue(QRect(215, 700, 90, 80));
    animation1->setEndValue(QRect(215, 140, 90, 80));

    QPropertyAnimation *animation2 = new QPropertyAnimation(enemy, "geometry");
    animation2->setDuration(static_cast<int>(durationFactor * 5));
    animation2->setStartValue(QRect(215, 140, 90, 80));
    animation2->setEndValue(QRect(900, 140, 90, 80));

    QPropertyAnimation *animation3 = new QPropertyAnimation(enemy, "geometry");
    animation3->setDuration(static_cast<int>(durationFactor * 5));
    animation3->setStartValue(QRect(900, 140, 90, 80));
    animation3->setEndValue(QRect(900, 625, 90, 80));

    QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);
    group->addAnimation(animation1);
    group->addAnimation(animation2);
    group->addAnimation(animation3);

    connect(group, &QSequentialAnimationGroup::finished, this, [this, enemy]() {
        enemies.removeOne(enemy);
        enemy->hide();
        checkWaveCompletion();
        if (enemy->isalive()){
            enemyReachedEndCount++;
            updateEnemyCountLabel();
            checkGameOver();
        }
        enemy->reduceHealth(enemy->gethealth());

        // enemy->deleteLater();
    });

    group->start();
}

void Gameplay_page::mousePressEvent(QMouseEvent *event)
{
    initializeAgents();

    if (event->button() == Qt::LeftButton) {
        QString logMessage;

        for (int i = 0; i < 4; ++i) {
            int xStart = startx_agent_choice + i * spacing;
            int xEnd = xStart + width_aghent_choice;
            int yStart = starty_aghant_choice;
            int yEnd = yStart + hight_aghent_choice;

            if (event->pos().x() >= xStart && event->pos().x() <= xEnd && event->pos().y() >= yStart && event->pos().y() <= yEnd) {
                AgentBase *agentChoice = (i == 0) ? agent_choice1 :
                                             (i == 1) ? agent_choice2 :
                                             (i == 2) ? agent_choice3 : agent_choice4;

                if (current_choice == agentChoice) {
                    current_choice = nullptr;
                    logMessage = QString("Agent choice %1 deselected.").arg(i + 1);
                    logEvent(logMessage);
                } else {
                    current_choice = agentChoice;
                    logMessage = QString("Agent choice %1 selected.").arg(i + 1);
                    logEvent(logMessage);
                }
                break;
            }
        }


        if (current_choice &&
            (current_choice->styleSheet().contains("background-image: url(:/prefix2/images/bomb.png);") ||
             current_choice->styleSheet().contains("background-image: url(:/prefix2/images/trap.png);"))) {

            int requiredElixir = current_choice->getElixirCost();  // استفاده از getElixirCost

            if (elixir >= requiredElixir &&
                ((event->pos().x() >= 210 && event->pos().x() <= 300 && event->pos().y() >= 140 && event->pos().y() <= 640) ||
                 (event->pos().x() >= 310 && event->pos().x() <= 890 && event->pos().y() >= 140 && event->pos().y() <= 220) ||
                 (event->pos().x() >= 900 && event->pos().x() <= 990 && event->pos().y() >= 150 && event->pos().y() <= 620))) {

                int centerX = event->pos().x();
                int centerY = event->pos().y();

                if (event->pos().x() >= 210 && event->pos().x() <= 300 && event->pos().y() >= 140 && event->pos().y() <= 640) {
                    centerX = (210 + 300) / 2;
                    centerY = event->pos().y();
                } else if (event->pos().x() >= 310 && event->pos().x() <= 890 && event->pos().y() >= 140 && event->pos().y() <= 220) {
                    centerX = event->pos().x();
                    centerY = (140 + 220) / 2;
                } else if (event->pos().x() >= 900 && event->pos().x() <= 990 && event->pos().y() >= 150 && event->pos().y() <= 620) {
                    centerX = (900 + 990) / 2;
                    centerY = event->pos().y();
                }

                int adjustedX = centerX - (current_choice->width() / 2);
                int adjustedY = centerY - (current_choice->height() / 2);

                current_choice->move(adjustedX, adjustedY);
                logMessage = "Placed bomb on the map at position: (" + QString::number(event->pos().x()) + ", " + QString::number(event->pos().y()) + ").";
                logEvent(logMessage);
                elixir -= requiredElixir;
                usedElixir += requiredElixir;
                elixirLabel->setText(QString::number(elixir));
                updateAgentChoice(current_choice, (current_choice == agent_choice1) ? 0 :
                                                      (current_choice == agent_choice2) ? 1 :
                                                      (current_choice == agent_choice3) ? 2 : 3);

                if (Bomb* bomb = dynamic_cast<Bomb*>(current_choice)) {
                    bomb->startTimer();
                }
                current_choice = nullptr;
            }
        }

        if (current_choice && !current_choice->styleSheet().contains("bomb") && !current_choice->styleSheet().contains("trap")) {
            int requiredElixir = current_choice->getElixirCost();

            if (elixir >= requiredElixir) {
                for (int i = 0; i < 16; ++i) {
                    int x = startX + (i % 4) * xOffset;
                    int y = startY + (i / 4) * yOffset;

                    QRect rect(x, y, width_agent_board, height_agent_board);
                    if (rect.contains(event->pos())) {
                        if (agent_board[i] == nullptr) {
                            current_choice->setParent(this);
                            current_choice->setGeometry(rect);
                            current_choice->show();
                            agent_board[i] = current_choice;
                            updateAgentChoice(current_choice, (current_choice == agent_choice1) ? 0 :
                                                                  (current_choice == agent_choice2) ? 1 :
                                                                  (current_choice == agent_choice3) ? 2 : 3);

                            elixir -= requiredElixir;
                            usedElixir += requiredElixir;
                            elixirLabel->setText(QString::number(elixir));
                            logMessage = QString("Placed agent on the board at index %1.").arg(i);
                            logEvent(logMessage);
                            current_choice->startShooting();
                            current_choice = nullptr;
                        }
                    }
                }
            } else {
                logMessage = "Not enough elixir to place the agent.";
                logEvent(logMessage);
            }
        }
    }
}

// sabt log hay bazi
void Gameplay_page::logEvent(const QString &event) {
    QFile file("game_log.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << event << "\n";
        file.close();
    }
}

// ezafe kardan agent ha be vector agents
void Gameplay_page::initializeAgents() {
    agents.append(new Gorbemahi(this));
    agents.append(new Gandom(this));
    agents.append(new Golmoshaki(this));
    agents.append(new Bomb(this));
    agents.append(new Trap(this));
    agents.append(new Kalam(this));
}


// random ezafe kardan agent ba estefade az yek index random ba dar nazar gereftan size vector agents
void Gameplay_page::createRandomAgent(AgentBase *&agent) {
    int randomIndex = std::rand() % agents.size();

    if (auto gorbemahi = dynamic_cast<Gorbemahi*>(agents[randomIndex])) {
        agent = new Gorbemahi(this);
    } else if (auto gandom = dynamic_cast<Gandom*>(agents[randomIndex])) {
        agent = new Gandom(this);
    } else if (auto golmoshaki = dynamic_cast<Golmoshaki*>(agents[randomIndex])) {
        agent = new Golmoshaki(this);
    } else if (auto bomb = dynamic_cast<Bomb*>(agents[randomIndex])) {
        agent = new Bomb(this);
    } else if (auto trap = dynamic_cast<Trap*>(agents[randomIndex])) {
        agent = new Trap(this);
    } else if (auto kalam = dynamic_cast<Kalam*>(agents[randomIndex])) {
        agent = new Kalam(this);
    }
}


// ezafe karadan agent random be agent choice
void Gameplay_page::updateAgentChoice(AgentBase *&currentChoice, int index){
    AgentBase *new_agentChoice = nullptr;
    createRandomAgent(new_agentChoice);

    if (new_agentChoice) {
        new_agentChoice->setGeometry(startx_agent_choice + index * spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);

        if (currentChoice == agent_choice1) {
            agent_choice1 = new_agentChoice;
        } else if (currentChoice == agent_choice2) {
            agent_choice2 = new_agentChoice;
        } else if (currentChoice == agent_choice3) {
            agent_choice3 = new_agentChoice;
        } else if (currentChoice == agent_choice4) {
            agent_choice4 = new_agentChoice;
        }
        new_agentChoice->show();
    }
}

// ezafi bayad pak beshe
void Gameplay_page::printAgentBoard() const{
    qDebug() << "Agent Board State:";
    for (int i = 0; i < agent_board.size(); ++i) {
        if (agent_board[i]) {
            qDebug() << "Index" << i << ":" << agent_board[i]->metaObject()->className();
        } else {
            qDebug() << "Index: " << i << " khalii";
        }
    }
}

void Gameplay_page::checkCollisions()
{

    for (AgentBase* agent : findChildren<AgentBase*>()) {
        if (Bomb* bomb = dynamic_cast<Bomb*>(agent)) {
            bomb->checkCollision(enemies);


            if (!bomb->getTimer()->isActive()) {
                connect(bomb, &Bomb::removeEnemies, this, &Gameplay_page::removeEnemies);
                connect(bomb, &Bomb::removeEnemies, this, [=]() {
                    if (bomb->getcollisionCount() >= 2) {
                        removeBombTrap(bomb);
                    }
                });
                connect(bomb, &Bomb::bombExpired, this, [=]() {
                    removeBombTrap(bomb);
                });

            }
        } else if (Trap* trap = dynamic_cast<Trap*>(agent)) {
            trap->checkCollision(enemies);
            connect(trap, &Trap::removeEnemies, this, &Gameplay_page::removeEnemies);
            connect(trap, &Trap::removeEnemies, this, [=]() {
                if (trap->getcollisionCount() >= 2) {
                    removeBombTrap(trap);
                }
            });
        }
    }

    for (Enemy* enemy : enemies) {
        if (Disarmer* disarmer = dynamic_cast<Disarmer*>(enemy)) {
            disarmer->disarmTrapsAndBombs();
        }
    }
}

void Gameplay_page::removeBombTrap(AgentBase* agent) {
    agent->hide();
    agent->deleteLater();
}

void Gameplay_page::removeEnemies(const QVector<Enemy*>& enemiesToRemove)
{
    for (Enemy* enemy : enemiesToRemove) {

        if (dynamic_cast<Disarmer*>(enemy)) {
            continue;
        }
        enemies.removeOne(enemy);
        enemy->hide();
        enemy->reduceHealth(enemy->gethealth());

        // enemy->deleteLater();
    }
}


void Gameplay_page::removeAgentFromBoard(AgentBase* agent)
{
    for (int i = 0; i < agent_board.size(); ++i) {
        if (agent_board[i] == agent) {
            agent_board[i] = nullptr;
            delete agent;
            break;
        }
    }
}

void Gameplay_page::updateElixir()
{
    if (elixir < 10) {
        elixir += 1;
        if (elixir > 10) elixir = 10;
        elixirLabel->setText(QString::number(elixir));
    }
}

void Gameplay_page::onEnemyKilled(Enemy* enemy)
{
    enemies.removeOne(enemy);
    enemy->hide();
    enemy->stopAllTimers();
    enemy->disable();
    enemy->reduceHealth(enemy->gethealth());
    // enemy->deleteLater();
    logEvent(QString("Enemy (type %1) killed.").arg(typeid(*enemy).name()));
    checkWaveCompletion();
}

void Gameplay_page::checkGameOver()
{
    if (isGameOver) return;
    if (enemyReachedEndCount >= maxEnemiesAllowedToReachEnd) {
        logEvent("Game Over: Too many enemies reached the end.");
        ResultWindow *resultwindow = new ResultWindow(wave,count_enemi,usedElixir,enemyReachedEndCount);
        resultwindow->show();
        isGameOver = true;
        QTimer::singleShot(0, this, &QMainWindow::close);
    }
}

void Gameplay_page::updateEnemyCountLabel()
{
    enemyCountLabel->setText(QString("%1").arg(enemyReachedEndCount));
}

Gameplay_page::~Gameplay_page()
{
    delete ui;

}
