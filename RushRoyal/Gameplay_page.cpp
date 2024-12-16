#include "Gameplay_page.h"
#include "ui_Gameplay_page.h"
#include "Gorbemahi.h"
#include "Gandom.h"
#include "Golmoshaki.h"
#include "Bomb.h"
#include "Bombice.h"
#include "Soldierenemy.h"
#include "Bossenemy.h"
#include "Enemy.h"
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



const int width_aghent_choice = 90;
const int hight_aghent_choice = 80;
const int startx_agent_choice = 410;
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
    , ui(new Ui::Gameplay_page),count_enemi(0), wave(1), bossSpawned(false)
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

    initializeAgents();

    agent_choice1 = new Gorbemahi(this);
    agent_choice1->setGeometry(startx_agent_choice, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    agent_choice2 = new Gandom(this);
    agent_choice2->setGeometry(startx_agent_choice + spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    agent_choice3 = new Golmoshaki(this);
    agent_choice3->setGeometry(startx_agent_choice + 2 * spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    agent_choice4 = new Bomb(this);
    agent_choice4->setGeometry(startx_agent_choice + 3 * spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);


    agent_board.resize(16);
    for (int i = 0; i < 16; ++i) {
        agent_board[i] = nullptr;

    }

    current_choice = nullptr;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gameplay_page::create_enemi);

    timer->start(2000); //5000
}

// sakht enemy boss v renemy soldier
void Gameplay_page::create_enemi() {
    Enemy *new_enemy = nullptr;

    new_enemy = new SoldierEnemy(this);
    new_enemy->setGeometry(220, 700, 90, 80);
    new_enemy->show();
    enemies.append(new_enemy);
    move_enemi(new_enemy);
    logEvent(QString("Soldier enemy #%1 created.").arg(++count_enemi));

    connect(new_enemy, &Enemy::enemyDefeated, this, &Gameplay_page::onEnemyDefeated);

    if (wave % 2 == 0 && !bossSpawned) {
        new_enemy = new BossEnemy(this);
        new_enemy->setGeometry(220, 700, 90, 80);
        new_enemy->show();
        enemies.append(new_enemy);
        move_enemi(new_enemy);
        logEvent(QString("Boss enemy created."));
        count_enemi++;
        bossSpawned = true;
        removeRandomAgentFromBoard();

        connect(new_enemy, &Enemy::enemyDefeated, this, &Gameplay_page::onEnemyDefeated);
    }

    if (count_enemi % 5 == 0) {
        wave++;
        count_enemi = 0;
        bossSpawned = false;
        logEvent(QString("Wave %1 completed.").arg(wave));
        printAgentBoard();
        timer->stop();
        QTimer::singleShot(10000, this, &Gameplay_page::startNextWave);
    } else {
        timer->start(500);
    }
}

// shoroe wave baadi
void Gameplay_page::startNextWave() {
    create_enemi();
}

// harekat enemy ha
void Gameplay_page::move_enemi(Enemy *enemy) {
    double durationFactor = 1000.0 / enemy->getspeed();

    QPropertyAnimation *animation1 = new QPropertyAnimation(enemy, "geometry");
    animation1->setDuration(static_cast<int>(durationFactor * 4));
    animation1->setStartValue(QRect(215, 700, 90, 80));
    animation1->setEndValue(QRect(215, 140, 90, 80));

    QPropertyAnimation *animation2 = new QPropertyAnimation(enemy, "geometry");
    animation2->setDuration(static_cast<int>(durationFactor * 4));
    animation2->setStartValue(QRect(215, 140, 90, 80));
    animation2->setEndValue(QRect(900, 140, 90, 80));

    QPropertyAnimation *animation3 = new QPropertyAnimation(enemy, "geometry");
    animation3->setDuration(static_cast<int>(durationFactor * 4));
    animation3->setStartValue(QRect(900, 140, 90, 80));
    animation3->setEndValue(QRect(900, 625, 90, 80));

    QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);
    group->addAnimation(animation1);
    group->addAnimation(animation2);
    group->addAnimation(animation3);

    connect(group, &QSequentialAnimationGroup::finished, this, [this, enemy]() {
        if (enemies.contains(enemy)) {
            removeEnemy(enemy);
        }
        if (enemies.isEmpty()) {
            logEvent("All enemies defeated. Preparing for next wave.");
            QTimer::singleShot(1000, this, &Gameplay_page::startNextWave);
        }
    });

    group->start();

}

// hazf enemy ha
void Gameplay_page::removeEnemy(Enemy* enemy) {
    if (enemies.contains(enemy)) {
        enemies.removeOne(enemy);
        enemy->hide();
        enemy->deleteLater();
    }

    if (enemies.isEmpty()) {
        logEvent("All enemies defeated. Preparing for next wave.");
        QTimer::singleShot(1000, this, &Gameplay_page::startNextWave);
    }
}

// sakht glole v shelik
void Gameplay_page::onBulletFired(int damage, const QRect &startRect) {
    Enemy* targetEnemy = nullptr;
    int maxDistance = -1;

    for (auto enemy : enemies) {
        int distanceTravelled = enemy->y();
        if (distanceTravelled > maxDistance) {
            maxDistance = distanceTravelled;
            targetEnemy = enemy;
        }
    }

    if (targetEnemy) {
        QLabel *bullet = new QLabel(this);
        bullet->setStyleSheet("background-color: yellow;");
        bullet->setGeometry(startRect.x() + startRect.width() / 2 - 5, startRect.y() - 10, 10, 10);
        bullet->setProperty("damage", damage);
        bullet->show();

        QPropertyAnimation *animation = new QPropertyAnimation(bullet, "geometry");
        animation->setDuration(1000);
        animation->setStartValue(bullet->geometry());
        animation->setEndValue(QRect(targetEnemy->x() + targetEnemy->width() / 2 - 5, targetEnemy->y() + targetEnemy->height() / 2 - 5, bullet->width(), bullet->height()));

        connect(animation, &QPropertyAnimation::finished, bullet, &QLabel::deleteLater);
        connect(animation, &QPropertyAnimation::finished, this, &Gameplay_page::checkBulletCollision);
        animation->start();
    }
}

// check kardan barkhord glole
void Gameplay_page::checkBulletCollision() {
    QList<Enemy*> enemiesToRemove;

    for (auto enemy : enemies) {
        for (auto bullet : findChildren<QLabel*>()) {
            if (bullet->styleSheet().contains("background-color: yellow;") && bullet->geometry().intersects(enemy->geometry())) {
                int damage = bullet->property("damage").toInt();
                enemy->takeDamage(damage);
                bullet->hide();
                bullet->deleteLater();
                if (enemy->gethealth() <= 0) {
                    logEvent("Enemy defeated!");
                    enemiesToRemove.append(enemy);
                }
            }
        }
    }

    for (auto enemy : enemiesToRemove) {
        removeEnemy(enemy);
    }
}


// signal koshte shodan enemy
void Gameplay_page::onEnemyDefeated() {
    logEvent("Enemy defeated!");
    if (enemies.isEmpty()) {
        QTimer::singleShot(1000, this, &Gameplay_page::startNextWave);
    }
}


// event hay mouse baray jaygozari agent ha
void Gameplay_page :: mousePressEvent(QMouseEvent *event){

    if(event->button() == Qt::LeftButton){
        QString logMessage;

        // bedast avardan agent choice
        if (event->pos().x() >= 410 && event->pos().x() <= 500 && event->pos().y() >= 640 && event->pos().y() <= 720){
            if (current_choice == agent_choice1) {
                current_choice = nullptr;
                logMessage = "Agent choice 1 deselected.";
                logEvent(logMessage);
            } else {
                current_choice = agent_choice1;
                logMessage = "Agent choice 1 selected.";
                logEvent(logMessage);
            }
        }
        if (event->pos().x() >= 510 && event->pos().x() <= 600 && event->pos().y() >= 640 && event->pos().y() <= 720){
            if (current_choice == agent_choice2) {
                current_choice = nullptr;
                logMessage = "Agent choice 2 deselected.";
                logEvent(logMessage);
            } else {
                current_choice = agent_choice2;
                logMessage = "Agent choice 2 selected.";
                logEvent(logMessage);
            }
        }
        if (event->pos().x() >= 610 && event->pos().x() <= 700 && event->pos().y() >= 640 && event->pos().y() <= 720){
            if (current_choice == agent_choice3) {
                current_choice = nullptr;
                logMessage = "Agent choice 3 deselected.";
                logEvent(logMessage);
            } else {
                current_choice = agent_choice3;
                logMessage = "Agent choice 3 selected.";
                logEvent(logMessage);
            }
        }
        if (event->pos().x() >= 710 && event->pos().x() <= 800 && event->pos().y() >= 640 && event->pos().y() <= 720){
            if (current_choice == agent_choice4) {
                current_choice = nullptr;
                logMessage = "Agent choice 4 deselected.";
                logEvent(logMessage);
            } else {
                current_choice = agent_choice4;
                logMessage = "Agent choice 4 selected.";
                logEvent(logMessage);
            }
        }

        // bomb v bomb ice gozashtan roye map bazi
        if (current_choice &&
            (current_choice->styleSheet().contains("background-image: url(:/prefix2/images/bomb.png);")||
            current_choice->styleSheet().contains("background-image: url(:/prefix2/images/bomb_ice.png);"))) {

            if ((event->pos().x() >= 210 && event->pos().x() <= 300 && event->pos().y() >= 140 && event->pos().y() <= 640) ||
                (event->pos().x() >= 310 && event->pos().x() <= 890 && event->pos().y() >= 140 && event->pos().y() <= 220) ||
                (event->pos().x() >= 900 && event->pos().x() <= 990 && event->pos().y() >= 150 && event->pos().y() <= 620)) {

                current_choice->move(event->pos().x(), event->pos().y());
                logMessage = "Placed bomb on the map at position: (" + QString::number(event->pos().x()) + ", " + QString::number(event->pos().y()) + ").";
                logEvent(logMessage);
                updateAgentChoice(current_choice, (current_choice == agent_choice1) ? 0 :
                                                      (current_choice == agent_choice2) ? 1 :
                                                      (current_choice == agent_choice3) ? 2 : 3);
                current_choice = nullptr;

            }
        }

        // agent gozas roye agent board
        if (current_choice && !current_choice->styleSheet().contains("bomb")) {
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

                        logMessage = QString("Changed tile agent board at index %1 to new agent.").arg(i);
                        logEvent(logMessage);
                        connect(current_choice, &AgentBase::bulletFired, this, &Gameplay_page::onBulletFired);
                        current_choice->startShooting();
                        current_choice = nullptr;
                    }
                }
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
    agents.append(new Bombice(this));
}

// random ezafe kardan agent ba estefade az yek index random ba dar nazar gereftan size vector agents
void Gameplay_page::createRandomAgent(AgentBase *&agent){
    int randomIndex = std::rand() % agents.size();

    if (auto gorbemahi = dynamic_cast<Gorbemahi*>(agents[randomIndex])) {
        agent = new Gorbemahi(this);
    } else if (auto gandom = dynamic_cast<Gandom*>(agents[randomIndex])) {
        agent = new Gandom(this);
    } else if (auto golmoshaki = dynamic_cast<Golmoshaki*>(agents[randomIndex])) {
        agent = new Golmoshaki(this);
    } else if (auto bomb = dynamic_cast<Bomb*>(agents[randomIndex])) {
        agent = new Bomb(this);
    } else if (auto bombice = dynamic_cast<Bombice*>(agents[randomIndex])) {
        agent = new Bombice(this);
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

// hazf shodan random agent roye agent board ba amadan agent boss dar wave hay zoje
void Gameplay_page::removeRandomAgentFromBoard() {
    QVector<int> occupiedIndices;
    for (int i = 0; i < agent_board.size(); ++i) {
        if (agent_board[i] != nullptr) {
            occupiedIndices.append(i);
        }
    }

    if (!occupiedIndices.isEmpty()) {
        int randomIndex = occupiedIndices[std::rand() % occupiedIndices.size()];
        agent_board[randomIndex]->stopShooting();
        agent_board[randomIndex]->hide();
        logEvent(QString("Agent removed from agent_board at index %1.").arg(randomIndex));
        agent_board[randomIndex] = nullptr;
    }
}


Gameplay_page::~Gameplay_page()
{
    delete ui;
}
