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
#include "database_helpers.h"
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
const int startx_agent_choice = 370;
const int starty_aghant_choice = 630;
const int spacing = 100;


const int width_agent_board = 90;
const int height_agent_board = 80;
const int startX = 350;
const int startY = 250;
const int xOffset = 140;
const int yOffset = 90;


Gameplay_page::Gameplay_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gameplay_page),count_enemi(0), wave(1), bossSpawned(0), elixir(7), waveInProgress(true), enemiesKilled(0), last_clicked_agent(nullptr),last_clicked_index(-1)
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

    enemi_wave = 20;

    enemyReachedEndCount = 3;
    enemyCountLabel1 = new QLabel(this);
    //enemyCountLabel1->setObjectName("enemyCountLabel");
    enemyCountLabel1->setGeometry(1005,580, 40, 36);
    //enemyCountLabel1->setText("3");
    enemyCountLabel1->setStyleSheet("background-image: url(:/prefix2/images/heart.png); font: bold 16px;");
    //enemyCountLabel1->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    enemyCountLabel2 = new QLabel(this);
    enemyCountLabel2->setGeometry(1005,545, 40, 36);
    enemyCountLabel2->setStyleSheet("background-image: url(:/prefix2/images/heart.png); font: bold 16px;");

    enemyCountLabel3 = new QLabel(this);
    enemyCountLabel3->setGeometry(1005,510, 40, 36);
    enemyCountLabel3->setStyleSheet("background-image: url(:/prefix2/images/heart.png); font: bold 16px;");


    // Wave progress bar
    waveProgressBackground = new QLabel(this);
    waveProgressBackground->setGeometry(440, 75, 320, 30);
    waveProgressBackground->setStyleSheet("background: transparent; background-color : rgb(0, 0, 0); border: 8px solid rgb(80, 80, 80); border-radius: 7px;");

    waveProgressForeground = new QLabel(this);
    waveProgressForeground->setGeometry(440, 75, 0, 30);
    waveProgressForeground->setStyleSheet("background: transparent; background-color : rgb( 0, 150, 0); border: 8px solid rgb(80, 80, 80); border-radius: 7px;");

    waveProgressZombei = new QLabel(this);
    waveProgressZombei->setGeometry(445, 45, 70, 80);
    waveProgressZombei->setStyleSheet("background: transparent; background-image: url(:/prefix2/images/6_editai.png);");

    waveProgressBackground->show();
    waveProgressForeground->show();
    waveProgressZombei->show();



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
    elixirLabel->setGeometry(770, 632, 90, 80);
    elixirLabel->setStyleSheet("background: transparent; border-radius: 25px; color: black; text-align: center;font: bold 20px; background-image: url(:/prefix2/images/elixirLabel.png);");
    elixirLabel->setAlignment(Qt::AlignCenter);
    elixirLabel->setText(QString::number(elixir));
    elixirLabel->show();

    // background-image: url(:/prefix2/images/elixirLabel.png);

    elixirTimer = new QTimer(this);
    connect(elixirTimer, &QTimer::timeout, this, &Gameplay_page::updateElixir);
    elixirTimer->start(2000);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gameplay_page::create_enemi);
    timer->start(1000);


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

    if (elixir < levels[0] * 2){

    }
    else{
        ui->LGolmushaki->setStyleSheet(QString("background-image: url(:/prefix2/images/golmoshaki%1.png);").arg(levels[0]+1));
        QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

        for(auto agent_choice : agent_choices) {
            if(auto golmoushaki = dynamic_cast<Golmoshaki*>(agent_choice)) {
                agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/golmoshaki%1.png);").arg(levels[0]+1));
                agent_choice->setpower(15 * pow(2, (levels[0] - 1)));
            }
        }
        if (levels[0] <= 5){
            if (levels[0] == 4){
                ui->PGolmushaki->setEnabled(false);
            }
            elixir -= levels[0] * 2;
            usedElixir += levels[0] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[0] += 1;
            agents[2]->setpower(15 * pow(2, (levels[0] - 1)));
            int currentNumber = ++golmoshakiLvl;
            ui->PGolmushaki->setText("lvl."+QString::number(currentNumber));

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


    if (elixir < levels[1] * 2){

    }
    else{
        ui->LGorbehmahi->setStyleSheet(QString("background-image: url(:/prefix2/images/gorbemahi%1.png);").arg(levels[1] + 1));
        QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

        for(auto agent_choice : agent_choices) {
            if(auto gorbehmahi = dynamic_cast<Gorbemahi*>(agent_choice)) {
                agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/gorbemahi%1.png);").arg(levels[1]+1));
                agent_choice->setpower(30 * pow(2, (levels[1] - 1)));
            }
        }
        if (levels[1] <= 5){
            if (levels[1] == 4){
                ui->PGorbemahi->setEnabled(false);
            }
            elixir -= levels[1] * 2;
            usedElixir += levels[1] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[1] += 1;
            agents[0]->setpower(30 * pow(2, (levels[1] - 1)));
            int currentNumber = ++gorbemahiLvl;
            ui->PGorbemahi->setText("lvl."+QString::number(currentNumber));

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



    if (elixir < levels[2] * 2){

    }
    else{
        ui->LKalam->setStyleSheet(QString("background-image: url(:/prefix2/images/kalam%1.png);").arg(levels[2] + 1));
        QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

        for(auto agent_choice : agent_choices) {
            if(auto kalam = dynamic_cast<Kalam*>(agent_choice)) {
                agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/kalam%1.png);").arg(levels[2]+1));
                agent_choice->setpower(22 * pow(2, (levels[2] - 1)));
            }
        }
        if (levels[2] <= 5){
            if (levels[2] == 4){
                ui->PKalam->setEnabled(false);
            }
            elixir -= levels[2] * 2;
            usedElixir += levels[2] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[2] += 1;
            agents[5]->setpower(22 * pow(2, (levels[2] - 1)));
            int currentNumber = ++kalamLvl;
            ui->PKalam->setText("lvl."+QString::number(currentNumber));
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


    if (elixir < levels[3] * 2){

    }
    else{
            ui->LGandom->setStyleSheet(QString("background-image: url(:/prefix2/images/gandom%1.png);").arg(levels[3] + 1));
        QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

        for(auto agent_choice : agent_choices) {
            if(auto gandom = dynamic_cast<Gandom*>(agent_choice)) {
                agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/gandom%1.png);").arg(levels[3]+1));
                agent_choice->setpower(15 * pow(2, (levels[3] - 1)));
            }
        }
        if (levels[3] <= 5){
            if (levels[3] == 4){
                ui->PGandom->setEnabled(false);
            }
            elixir -= levels[3] * 2;
            usedElixir += levels[3] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[3] += 1;
            agents[1]->setpower(15 * pow(2, (levels[3] - 1)));
            int currentNumber = ++gandomLvl;
            ui->PGandom->setText("lvl."+QString::number(currentNumber));

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

    if (elixir < levels[4] * 2){

    }
    else{
        ui->LBomb->setStyleSheet(QString("background-image: url(:/prefix2/images/bomb%1.png);").arg(levels[4] + 1));
        QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

        for(auto agent_choice : agent_choices) {
            if(auto bomb = dynamic_cast<Bomb*>(agent_choice)) {
                agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/bomb%1.png);").arg(levels[4]+1));
                bomb->setpowerkill(levels[4] + 2);
            }
        }

        if (levels[4] <= 5){
            if (levels[4] == 4){
                ui->PBomb->setEnabled(false);
            }
            elixir -= levels[4] * 2;
            usedElixir += levels[4] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[4] += 1;
            Bomb* bomb = dynamic_cast<Bomb*>(agents[3]);
            bomb->setpowerkill(levels[4] + 1);
            int currentNumber = ++bombLvl;
            ui->PBomb->setText("lvl."+QString::number(currentNumber));
        }


    }
}



void Gameplay_page::on_PTrap_clicked()
{

    if (elixir < levels[5] * 2){

    }
    else{
         ui->LTrap->setStyleSheet(QString("background-image: url(:/prefix2/images/trap%1.png);").arg(levels[5] + 1));
        QList<AgentBase*> agent_choices = {agent_choice1, agent_choice2, agent_choice3, agent_choice4};

        for(auto agent_choice : agent_choices) {
            if(auto trap = dynamic_cast<Trap*>(agent_choice)) {
                agent_choice->setStyleSheet(QString("background-image: url(:/prefix2/images/trap%1.png);").arg(levels[5]+1));
                trap->setpowerkill(levels[5] + 2);
            }
        }
        if (levels[5] <= 5){
            if (levels[5] == 4){
                ui->PTrap->setEnabled(false);
            }
            elixir -= levels[5] * 2;
            usedElixir += levels[5] * 2;
            elixirLabel->setText(QString::number(elixir));
            levels[5] += 1;
            Trap* trap = dynamic_cast<Trap*>(agents[4]);
            trap->setpowerkill(levels[5] + 1);
            int currentNumber = ++trapLvl;
            ui->PTrap->setText("lvl."+QString::number(currentNumber));

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


void Gameplay_page::create_enemi(){
    Enemy *new_enemy = nullptr;
            int enemyType = std::rand() % 2;

            int baseHealth = 0;
            double baseSpeed = 0.0;

            switch (enemyType) {
            case 0:
                baseHealth = 50;
                baseSpeed = 1.0;
                break;
            case 1:
                baseHealth = 100;
                baseSpeed = 0.5;
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

            if(wave % 2 == 0 &&  bossSpawned == 0){
                int bossType =  std::rand() % 3;
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
                            new_enemy = new Eraser(this, currentHealth, currentSpeed);
                            bossSpawned = 1;
                            break;
                        case 1:
                            new_enemy = new Freezer(this, currentHealth, currentSpeed);
                            bossSpawned = 1 ;
                            break;
                        case 2:
                            new_enemy = new Disarmer(this, currentHealth, currentSpeed);
                            bossSpawned = 1;
                            break;
                        }
            }
            count_enemi += 1;
            enemies.append(new_enemy);
            new_enemy->setGeometry(220, 700, 90, 80);
            new_enemy->show();

            if(count_enemi == enemi_wave ){
                // saveWaveRecord(wave);
                // timer->setInterval(3000);
                timer->stop();
                count_enemi = 0;
                wave += 1;
                bossSpawned = 0;
            }else{
                timer->setInterval(300);
            }
            move_enemi(new_enemy);

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

        if(enemies.isEmpty()){
            timer->start(2000);
        }

        if (enemy->isalive()){
            enemyReachedEndCount--;
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

    if (event->button() == Qt::LeftButton) {
        QString logMessage;

        for (int i = 0; i < 16; ++i) {
            int x = startX + (i % 4) * xOffset;
            int y = startY + (i / 4) * yOffset;

            QRect rect(x, y, width_agent_board, height_agent_board);
            if (rect.contains(event->pos()) && agent_board[i] != nullptr) {
                AgentBase *targetAgent = agent_board[i];
                if (last_clicked_agent != nullptr && last_clicked_agent->metaObject()->className() == targetAgent->metaObject()->className()
                    && targetAgent->getlevelspeedup() < 4 && targetAgent->getlevelspeedup() == last_clicked_agent->getlevelspeedup()) {

                    if (Golmoshaki* golmushaki = dynamic_cast<Golmoshaki*>(targetAgent)) {
                        golmushaki->setlevelspeedup(golmushaki->getlevelspeedup() + 1);
                        updatePot(i, golmushaki->getlevelspeedup());
                        updatePot(last_clicked_index,1);
                        qDebug() << "level: " << golmushaki->getlevelspeedup();
                        golmushaki->setAgentBaseFireRate(golmushaki->getAgentBaseFireRate() / 2);
                        golmushaki->shot();
                        agent_board[last_clicked_index]->deleteLater();
                    }

                    if (Gorbemahi* gorbemahi = dynamic_cast<Gorbemahi*>(targetAgent)) {
                        gorbemahi->setlevelspeedup(gorbemahi->getlevelspeedup() + 1);
                        updatePot(i, gorbemahi->getlevelspeedup());
                        updatePot(last_clicked_index,1);
                        qDebug() << "level: " << gorbemahi->getlevelspeedup();
                        gorbemahi->setAgentBaseFireRate(gorbemahi->getAgentBaseFireRate() / 2);
                        gorbemahi->shot();
                        agent_board[last_clicked_index]->deleteLater();
                    }

                    if (Gandom* gandom = dynamic_cast<Gandom*>(targetAgent)) {
                        gandom->setlevelspeedup(gandom->getlevelspeedup() + 1);
                        updatePot(i, gandom->getlevelspeedup());
                        updatePot(last_clicked_index,1);
                        qDebug() << "level: " << gandom->getlevelspeedup();
                        gandom->setAgentBaseFireRate(gandom->getAgentBaseFireRate() / 2);
                        gandom->shot();
                        agent_board[last_clicked_index]->deleteLater();
                    }

                    if (Kalam* kalam = dynamic_cast<Kalam*>(targetAgent)) {
                        kalam->setlevelspeedup(kalam->getlevelspeedup() + 1);
                        updatePot(i, kalam->getlevelspeedup());
                        updatePot(last_clicked_index,1);
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
                    connect(bomb, &Bomb::enemyKilledByBomb, this, &Gameplay_page::incrementEnemyKilled);
                }
                if (Trap* trap = dynamic_cast<Trap*>(current_choice)) {
                    trap->startTimer();
                    connect(trap, &Trap::enemyKilledByTrap, this, &Gameplay_page::incrementEnemyKilled);
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
                                golmushaki->move(x - 3,y - 33);
                            }
                            if (Gorbemahi* gorbemahi = dynamic_cast<Gorbemahi*>(current_choice)) {
                                gorbemahi->shot();
                                gorbemahi->move(x - 7,y - 33);
                            }
                            if (Gandom* gandom = dynamic_cast<Gandom*>(current_choice)) {
                                gandom->shot();
                                gandom->move(x - 7,y - 33);
                            }
                            if (Kalam* kalam = dynamic_cast<Kalam*>(current_choice)) {
                                kalam->shot();
                                kalam->move(x - 10, y - 33);
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
            /*connect(trap, &Trap::bombExpired, this, [=]() {
                removeBombTrap(trap);

            });*/
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
    if(enemies.isEmpty()){
        timer->start(2000);
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
    if (enemy->preventBugForEnemyKillNum == 0){
        enemiesKilled++;
        enemy->preventBugForEnemyKillNum = 1;
    }
    updateWaveProgress();
    enemies.removeOne(enemy);
    if(enemies.isEmpty()){
        timer->start(2000);
    }
    enemy->hide();
    enemy->stopAllTimers();
    enemy->disable();
    enemy->reduceHealth(enemy->gethealth());

    // enemy->deleteLater();
    logEvent(QString("Enemy (type %1) killed.").arg(typeid(*enemy).name()));
}

void Gameplay_page::incrementEnemyKilled() {
    enemiesKilled++;
    updateWaveProgress();
}

void Gameplay_page::checkGameOver()
{
    if (isGameOver) return;
    if (enemyReachedEndCount <= 0) {
        logEvent("Game Over: Too many enemies reached the end.");
        int gamerecord = getMaxWaveRecord();
        if (wave - 1 > gamerecord) {
            gamerecord = wave - 1;
            saveWaveRecord(gamerecord);
        }
        ResultWindow *resultwindow = new ResultWindow(wave-1,enemiesKilled,usedElixir,gamerecord);
        resultwindow->show();
        isGameOver = true;
        QTimer::singleShot(0, this, &QMainWindow::close);


    }
}

void Gameplay_page::updateEnemyCountLabel()
{
    //enemyCountLabel->setText(QString("%1").arg(enemyReachedEndCount));
    if(enemyReachedEndCount == 2) enemyCountLabel3->hide();
    else if(enemyReachedEndCount == 1) enemyCountLabel2->hide();
    else if(enemyReachedEndCount == 0) enemyCountLabel1->hide();
    updateWaveProgress();
}


void Gameplay_page::updatePot(int i, int speedupLvl)
{
    QString x;
    if(speedupLvl >= 1 && speedupLvl <= 4) {
        switch(speedupLvl) {
        case 2: x = "url(:/prefix2/images/pots11.png);"; break;
        case 3: x = "url(:/prefix2/images/pots12.png);"; break;
        case 4: x = "url(:/prefix2/images/pots13.png);"; break;
        default: x = "url(:/prefix2/images/pots1.png);"; break;
        }
    }

    if(last_clicked_index == i) x = "url(:/prefix2/images/pots1.png);";

    if (i >= 0 && i < 16) {
        switch(i) {
        case 0: ui->label_29->setStyleSheet("background-image: "+ x); break;
        case 1: ui->label_28->setStyleSheet("background-image: "+ x); break;
        case 2: ui->label_26->setStyleSheet("background-image: "+ x); break;
        case 3: ui->label_27->setStyleSheet("background-image: "+ x); break;
        case 4: ui->label_25->setStyleSheet("background-image: "+ x); break;
        case 5: ui->label_24->setStyleSheet("background-image: "+ x); break;
        case 6: ui->label_22->setStyleSheet("background-image: "+ x); break;
        case 7: ui->label_23->setStyleSheet("background-image: "+ x); break;
        case 8: ui->label_21->setStyleSheet("background-image: "+ x); break;
        case 9: ui->label_20->setStyleSheet("background-image: "+ x); break;
        case 10: ui->label_18->setStyleSheet("background-image: "+ x); break;
        case 11: ui->label_19->setStyleSheet("background-image: "+ x); break;
        case 12: ui->label_15->setStyleSheet("background-image: "+ x); break;
        case 13: ui->label_14->setStyleSheet("background-image: "+ x); break;
        case 14: ui->label_16->setStyleSheet("background-image: "+ x); break;
        case 15: ui->label_17->setStyleSheet("background-image: "+ x); break;
        }
    }
}


void Gameplay_page::updateWaveProgress() {
    int progress = ((enemiesKilled-enemyReachedEndCount+3) % enemi_wave * 300) / enemi_wave;
    waveProgressForeground->setGeometry(440, 75, progress, 30);
    waveProgressZombei->setGeometry(432 + progress, 45, 70, 80);
}

Gameplay_page::~Gameplay_page()
{
    delete ui;

}



