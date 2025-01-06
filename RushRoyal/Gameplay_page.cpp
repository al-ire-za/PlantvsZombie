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
    , ui(new Ui::Gameplay_page),count_enemi(0), wave(1), bossSpawned(false), elixir(1000), waveInProgress(true), enemiesKilled(0), last_clicked_agent(nullptr),last_clicked_index(-1)
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

    levels.resize(6);
    for(int i = 0 ; i < levels.size(); i++){
        levels[i] = 1;
    }

    agent_choice1 = new Golmoshaki(this);
    agent_choice1->setGeometry(startx_agent_choice, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    agent_choice2 = new Gorbemahi(this);
    agent_choice2->setGeometry(startx_agent_choice + spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    agent_choice3 = new Gandom(this);
    agent_choice3->setGeometry(startx_agent_choice + 2 * spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    agent_choice4 = new Trap(this);
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
    timer->start(2000);


    QTimer *collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &Gameplay_page::checkCollisions);
    collisionTimer->start(50);
    initializeAgents();
}

void Gameplay_page::initializeAgents() {
    agents.append(new Gorbemahi());
    agents.append(new Gandom());
    agents.append(new Golmoshaki());
    agents.append(new Bomb());
    agents.append(new Trap());
    agents.append(new Kalam());

}


void Gameplay_page::on_PGolmushaki_clicked()
{

    QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

    for(auto agent_choice : agent_choices) {
        if(auto golmoushaki = dynamic_cast<Golmoshaki*>(agent_choice)) {
            agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/golmoshaki%1.png);").arg(levels[0]+1));
            agent_choice->setpower(15 * pow(2, (levels[0] - 1)));
        }
    }


    ui->LGolmushaki->setStyleSheet(QString("background-image: url(:/prefix2/images/golmoshaki%1.png);").arg(levels[0]+1));


    if (elixir < levels[0] * 2){

    }
    else{
        if (levels[0] <= 5){
            if (levels[0] == 4){
                ui->PGolmushaki->setEnabled(false);
            }
            elixir -= levels[0] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[0] += 1;
            agents[2]->setpower(15 * pow(2, (levels[0] - 1)));
            QString buttonText = ui->PGolmushaki->text();
            int currentNumber = buttonText.toInt();
            currentNumber += 1;
            ui->PGolmushaki->setText(QString::number(currentNumber));

        }

        for (AgentBase *t : agent_board) {
            if (auto golmoshaki = dynamic_cast<Golmoshaki*>(t)) {
                golmoshaki->setpower(15 * pow(2 ,(levels[0] - 1)));
                golmoshaki->setStyleSheet(QString("background-image: url(:/prefix2/images/golmoshaki%1.png);").arg(levels[0]));
            }
        }
        qDebug() << "Power: " << agents[2]->getpower();
        }
}


void Gameplay_page::on_PGorbemahi_clicked()
{
    QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

    for(auto agent_choice : agent_choices) {
        if(auto gorbehmahi = dynamic_cast<Gorbemahi*>(agent_choice)) {
            agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/gorbemahi%1.png);").arg(levels[1]+1));
            agent_choice->setpower(30 * pow(2, (levels[1] - 1)));
        }
    }
    ui->LGorbehmahi->setStyleSheet(QString("background-image: url(:/prefix2/images/gorbemahi%1.png);").arg(levels[1] + 1));
    if (elixir < levels[1] * 2){

    }
    else{
        if (levels[1] <= 5){
            if (levels[1] == 4){
                ui->PGorbemahi->setEnabled(false);
            }
            elixir -= levels[1] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[1] += 1;
            agents[0]->setpower(30 * pow(2, (levels[1] - 1)));
            QString buttonText = ui->PGorbemahi->text();
            int currentNumber = buttonText.toInt();
            currentNumber += 1;
            ui->PGorbemahi->setText(QString::number(currentNumber));

        }

        for (AgentBase *t : agent_board) {
            if (auto gorbehmahi = dynamic_cast<Gorbemahi*>(t)) {
                gorbehmahi->setpower(30 * pow(2 ,(levels[1] - 1)));
                gorbehmahi->setStyleSheet(QString("background-image: url(:/prefix2/images/gorbemahi%1.png);").arg(levels[1]));
            }
        }
        qDebug() << "Power: " << agents[0]->getpower();
    }
}

void Gameplay_page::on_PKalam_clicked()
{

    QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

    for(auto agent_choice : agent_choices) {
        if(auto kalam = dynamic_cast<Kalam*>(agent_choice)) {
            agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/kalam%1.png);").arg(levels[2]+1));
            agent_choice->setpower(22 * pow(2, (levels[2] - 1)));
        }
    }
    ui->LKalam->setStyleSheet(QString("background-image: url(:/prefix2/images/kalam%1.png);").arg(levels[2] + 1));
    if (elixir < levels[2] * 2){

    }
    else{
        if (levels[2] <= 5){
            if (levels[2] == 4){
                ui->PKalam->setEnabled(false);
            }
            elixir -= levels[2] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[2] += 1;
            agents[5]->setpower(22 * pow(2, (levels[2] - 1)));
            QString buttonText = ui->PKalam->text();
            int currentNumber = buttonText.toInt();
            currentNumber += 1;
            ui->PKalam->setText(QString::number(currentNumber));

        }

        for (AgentBase *t : agent_board) {
            if (auto kalam = dynamic_cast<Kalam*>(t)) {
                kalam->setpower(22 * pow(2 ,(levels[2] - 1)));
                kalam->setStyleSheet(QString("background-image: url(:/prefix2/images/kalam%1.png);").arg(levels[2]));
            }
        }
        qDebug() << "Power: " << agents[5]->getpower();
    }
}


void Gameplay_page::on_PGandom_clicked()
{
    QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

    for(auto agent_choice : agent_choices) {
        if(auto gandom = dynamic_cast<Gandom*>(agent_choice)) {
            agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/gandom%1.png);").arg(levels[3]+1));
            agent_choice->setpower(15 * pow(2, (levels[3] - 1)));
        }
    }
    ui->LGandom->setStyleSheet(QString("background-image: url(:/prefix2/images/gandom%1.png);").arg(levels[3] + 1));
    if (elixir < levels[3] * 2){

    }
    else{
        if (levels[3] <= 5){
            if (levels[3] == 4){
                ui->PGandom->setEnabled(false);
            }
            elixir -= levels[3] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[3] += 1;
            agents[1]->setpower(15 * pow(2, (levels[3] - 1)));
            QString buttonText = ui->PGandom->text();
            int currentNumber = buttonText.toInt();
            currentNumber += 1;
            ui->PGandom->setText(QString::number(currentNumber));

        }

        for (AgentBase *t : agent_board) {
            if (auto gandom = dynamic_cast<Gandom*>(t)) {
                gandom->setpower(15 * pow(2 ,(levels[3] - 1)));
                gandom->setStyleSheet(QString("background-image: url(:/prefix2/images/gandom%1.png);").arg(levels[3]));
            }
        }
        qDebug() << "Power: " << agents[1]->getpower();
    }
}


void Gameplay_page::on_PBomb_clicked()
{
    QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

    for(auto agent_choice : agent_choices) {
        if(auto bomb = dynamic_cast<Bomb*>(agent_choice)) {
            agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/bomb%1.png);").arg(levels[4]+1));
            bomb->setpowerkill(levels[4] + 2);
        }
    }
    ui->LBomb->setStyleSheet(QString("background-image: url(:/prefix2/images/bomb%1.png);").arg(levels[4] + 1));
    if (elixir < levels[4] * 2){

    }
    else{
        if (levels[4] <= 5){
            if (levels[4] == 4){
                ui->PBomb->setEnabled(false);
            }
            elixir -= levels[4] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[4] += 1;
            Bomb* bomb = dynamic_cast<Bomb*>(agents[3]);
            bomb->setpowerkill(levels[4] + 1);
            QString buttonText = ui->PBomb->text();
            int currentNumber = buttonText.toInt();
            currentNumber += 1;
            ui->PBomb->setText(QString::number(currentNumber));

        }


    }
}



void Gameplay_page::on_PTrap_clicked()
{
    QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

    for(auto agent_choice : agent_choices) {
        if(auto trap = dynamic_cast<Trap*>(agent_choice)) {
            agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/trap%1.png);").arg(levels[5]+1));
            trap->setpowerkill(levels[5] + 2);
        }
    }

    ui->LTrap->setStyleSheet(QString("background-image: url(:/prefix2/images/trap%1.png);").arg(levels[5] + 1));
    if (elixir < levels[5] * 2){

    }
    else{
        if (levels[5] <= 5){
            if (levels[5] == 4){
                ui->PTrap->setEnabled(false);
            }
            elixir -= levels[5] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[5] += 1;
            Trap* trap = dynamic_cast<Trap*>(agents[4]);
            trap->setpowerkill(levels[5] + 1);
            QString buttonText = ui->PTrap->text();
            int currentNumber = buttonText.toInt();
            currentNumber += 1;
            ui->PTrap->setText(QString::number(currentNumber));

        }


    }
}

void Gameplay_page::createRandomAgent(AgentBase *&agent) {
    QList<QString> existingAgents;
    QList<QString> allAgents = {"Gorbemahi", "Gandom", "Golmoshaki", "Bomb", "Trap", "Kalam"};


    for (auto chosenAgent : {agent_choice1, agent_choice2, agent_choice3, agent_choice4}) {
        if (chosenAgent != nullptr) {
            existingAgents.append(chosenAgent->metaObject()->className());
        }
    }


    QList<QString> remainingAgents;
    for (const auto &agentName : allAgents) {
        if (!existingAgents.contains(agentName)) {
            remainingAgents.append(agentName);
        }
    }


    if (!remainingAgents.isEmpty()) {
        int randomIndex = std::rand() % remainingAgents.size();
        QString chosenAgentName = remainingAgents[randomIndex];

        if (chosenAgentName == "Gorbemahi") {
            agent = new Gorbemahi(this);
        } else if (chosenAgentName == "Gandom") {
            agent = new Gandom(this);
        } else if (chosenAgentName == "Golmoshaki") {
            agent = new Golmoshaki(this);
        } else if (chosenAgentName == "Bomb") {
            agent = new Bomb(this);
        } else if (chosenAgentName == "Trap") {
            agent = new Trap(this);
        } else if (chosenAgentName == "Kalam") {
            agent = new Kalam(this);
        }
    } else {

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
}



// ezafe karadan agent random be agent choice
void Gameplay_page::updateAgentChoice(AgentBase *&currentChoice, int index){
    AgentBase *new_agentChoice = nullptr;

    createRandomAgent(new_agentChoice);

    if(auto golmoushaki = dynamic_cast<Golmoshaki*>(new_agentChoice)){
        new_agentChoice->setpower(15 * pow(2, (levels[0] - 1)));
        new_agentChoice->setStyleSheet(QString("background-image: url(:/prefix2/images/golmoshaki%1.png);").arg(levels[0]));
    }

    if(auto gorbemahi = dynamic_cast<Gorbemahi*>(new_agentChoice)){
        new_agentChoice->setpower(30 * pow(2, (levels[1] - 1)));
        new_agentChoice->setStyleSheet(QString("background-image: url(:/prefix2/images/gorbemahi%1.png);").arg(levels[1]));

    }

    if(auto kalam = dynamic_cast<Kalam*>(new_agentChoice)){
        new_agentChoice->setpower(22 * pow(2, (levels[2] - 1)));
        new_agentChoice->setStyleSheet(QString("background-image: url(:/prefix2/images/kalam%1.png);").arg(levels[2]));
    }

    if(auto gandom = dynamic_cast<Gandom*>(new_agentChoice)){
        new_agentChoice->setpower(15 * pow(2, (levels[3] - 1)));
        new_agentChoice->setStyleSheet(QString("background-image: url(:/prefix2/images/gandom%1.png);").arg(levels[3]));
    }

    if(auto bomb = dynamic_cast<Bomb*>(new_agentChoice)){
        bomb->setpowerkill(levels[4] + 1);
        bomb->setStyleSheet(QString("background-image: url(:/prefix2/images/bomb%1.png);").arg(levels[4]));

    }

    if(auto trap = dynamic_cast<Trap*>(new_agentChoice)){
        trap->setpowerkill(levels[5] + 1);
        trap->setStyleSheet(QString("background-image: url(:/prefix2/images/trap%1.png);").arg(levels[5]));

    }

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
            baseSpeed = 1.50;
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

        if (wave % 2 == 1 && !bossSpawned) {
            createBoss();

        }

        if (count_enemi % 10 == 0 && count_enemi != 0) {
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
        int bossType = 1/* std::rand() % 3*/;
        Enemy *boss_enemy = nullptr;

        int baseHealth = 0;
        double baseSpeed = 0.0;

        switch (bossType) {
        case 0:
            baseHealth = 2000;
            baseSpeed = 1.25;
            break;
        case 1:
            baseHealth = 2000;
            baseSpeed = 1.25;
            break;
        case 2:
            baseHealth = 2000;
            baseSpeed = 1.25;
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
            // checkGameOver();
        }
        enemy->reduceHealth(enemy->gethealth());

        // enemy->deleteLater();
    });

    group->start();
}

void Gameplay_page::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton) {
        QString logMessage;

        for (int i = 0; i < 16; ++i) {
            int x = startX + (i % 4) * xOffset;
            int y = startY + (i / 4) * yOffset;

            QRect rect(x, y, width_agent_board, height_agent_board);
            if (rect.contains(event->pos()) && agent_board[i] != nullptr) {
                AgentBase *targetAgent = agent_board[i];
                if (last_clicked_agent != nullptr && last_clicked_agent->metaObject()->className() == targetAgent->metaObject()->className()
                    && targetAgent->getlevelspeedup() < 5 && targetAgent->getlevelspeedup() == last_clicked_agent->getlevelspeedup()) {

                    if (Golmoshaki* golmushaki = dynamic_cast<Golmoshaki*>(targetAgent)) {
                        golmushaki->setlevelspeedup(golmushaki->getlevelspeedup() + 1);
                        qDebug() << "level: " << golmushaki->getlevelspeedup();
                        golmushaki->setAgentBaseFireRate(golmushaki->getAgentBaseFireRate() / 2);
                        golmushaki->shot();
                        agent_board[last_clicked_index]->deleteLater();
                    }

                    if (Gorbemahi* gorbemahi = dynamic_cast<Gorbemahi*>(targetAgent)) {
                        gorbemahi->setlevelspeedup(gorbemahi->getlevelspeedup() + 1);
                        qDebug() << "level: " << gorbemahi->getlevelspeedup();
                        gorbemahi->setAgentBaseFireRate(gorbemahi->getAgentBaseFireRate() / 2);
                        gorbemahi->shot();
                        agent_board[last_clicked_index]->deleteLater();
                    }

                    if (Gandom* gandom = dynamic_cast<Gandom*>(targetAgent)) {
                        gandom->setlevelspeedup(gandom->getlevelspeedup() + 1);
                        qDebug() << "level: " << gandom->getlevelspeedup();
                        gandom->setAgentBaseFireRate(gandom->getAgentBaseFireRate() / 2);
                        gandom->shot();
                        agent_board[last_clicked_index]->deleteLater();
                    }

                    if (Kalam* kalam = dynamic_cast<Kalam*>(targetAgent)) {
                        kalam->setlevelspeedup(kalam->getlevelspeedup() + 1);
                        qDebug() << "level: " << kalam->getlevelspeedup();
                        kalam->setAgentBaseFireRate(kalam->getAgentBaseFireRate() / 2);
                        kalam->shot();
                        agent_board[last_clicked_index]->deleteLater();
                    }

                    agent_board[last_clicked_index] = nullptr;
                    logMessage = QString("Merged agent at index %1, new speed: %2.").arg(i).arg(targetAgent->getAgentBaseFireRate());
                    logEvent(logMessage);
                    last_clicked_agent = nullptr;
                    last_clicked_index = -1;
                } else {
                    last_clicked_agent = targetAgent;
                    last_clicked_index = i;
                }
                return;
            }
        }

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
            (current_choice->styleSheet().contains("bomb") ||
             current_choice->styleSheet().contains("trap"))) {

            int requiredElixir = current_choice->getElixirCost();

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
                            if (Golmoshaki* golmushaki = dynamic_cast<Golmoshaki*>(current_choice)) {
                                golmushaki->shot();
                            }
                            if (Gorbemahi* gorbemahi = dynamic_cast<Gorbemahi*>(current_choice)) {
                                gorbemahi->shot();
                            }
                            if (Gandom* gandom = dynamic_cast<Gandom*>(current_choice)) {
                                gandom->shot();
                            }
                            if (Kalam* kalam = dynamic_cast<Kalam*>(current_choice)) {
                                kalam->shot();
                            }

                            updateAgentChoice(current_choice, (current_choice == agent_choice1) ? 0 :
                                                                  (current_choice == agent_choice2) ? 1 :
                                                                  (current_choice == agent_choice3) ? 2 : 3);

                            elixir -= requiredElixir;
                            usedElixir += requiredElixir;
                            elixirLabel->setText(QString::number(elixir));
                            logMessage = QString("Placed agent on the board at index %1.").arg(i);
                            logEvent(logMessage);

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
                    if (bomb->getcollisionCount() >= bomb->getpowerkill()) {
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
                if (trap->getcollisionCount() >= trap->getpowerkill()) {
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
        enemiesKilled++;

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
    enemiesKilled++;
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
        ResultWindow *resultwindow = new ResultWindow(wave,enemiesKilled,usedElixir,enemiesKilled);
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



