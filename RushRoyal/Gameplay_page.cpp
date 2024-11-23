#include "Gameplay_page.h"
#include "ui_Gameplay_page.h"

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


Gameplay_page::Gameplay_page(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gameplay_page)
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


    randomImages_AgentChoice = {
        ":/prefix2/images/jolback2.png",
        ":/prefix2/images/kalam2.png",
        ":/prefix2/images/hendone2.png",
        ":/prefix2/images/gandom22.png",
        ":/prefix2/images/golmoshaki2.png",
        ":/prefix2/images/gorbemahi2.png",
        ":/prefix2/images/felfelmoshaki2.png",
        ":/prefix2/images/hendone_yakhi22.png"
    };

    randomImages_Enemi = {
        ":/prefix2/images/1_edit.png",
        ":/prefix2/images/2_editai.png",
        ":/prefix2/images/33_editai.png",
        ":/prefix2/images/4_editai.png",
        ":/prefix2/images/5_editai.png",
        ":/prefix2/images/6_editai.png"
};

    const int width_aghent_choice = 90;
    const int hight_aghent_choice = 80;
    const int startx_agent_choice = 410;
    const int starty_aghant_choice = 640;
    const int spacing = 100;


    agent_choice1 = new QLabel(this);
    agent_choice1->setGeometry(startx_agent_choice, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    randomImage1 = randomImages_AgentChoice[std::rand() % randomImages_AgentChoice.size()];
    updateStyleSheetAgentChoice(agent_choice1, randomImage1);

    agent_choice2 = new QLabel(this);
    agent_choice2->setGeometry(startx_agent_choice + spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    randomImage2 = randomImages_AgentChoice[std::rand() % randomImages_AgentChoice.size()];
    updateStyleSheetAgentChoice(agent_choice2, randomImage2);

    agent_choice3 = new QLabel(this);
    agent_choice3->setGeometry(startx_agent_choice + 2 * spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    randomImage3 = randomImages_AgentChoice[std::rand() % randomImages_AgentChoice.size()];
    updateStyleSheetAgentChoice(agent_choice3, randomImage3);

    agent_choice4 = new QLabel(this);
    agent_choice4->setGeometry(startx_agent_choice + 3 * spacing, starty_aghant_choice, width_aghent_choice, hight_aghent_choice);
    randomImage4 = randomImages_AgentChoice[std::rand() % randomImages_AgentChoice.size()];
    updateStyleSheetAgentChoice(agent_choice4, randomImage4);


    for (int i = 0; i < 16; ++i) {
        agent_board[i] = new QLabel(this);

    }

    const int width_agent_board = 90;
    const int height_agent_borad = 80;
    const int startX = 350;
    const int startY = 250;
    const int xOffset = 140;
    const int yOffset = 90;

    for (int i = 0; i < 16; ++i) {
        int x = startX + (i % 4) * xOffset;
        int y = startY + (i / 4) * yOffset;

        agent_board[i]->setGeometry(x, y, width_agent_board, height_agent_borad);
        agent_board[i]->setStyleSheet("background-image: url(:/prefix2/images/sanng.png);");
    }

    current_choice = nullptr;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gameplay_page::create_enemi);
    timer->start(2000); //5000
}



int count_enemi = 0;
int wave = 0;
void Gameplay_page :: create_enemi(){
    int randomInterval;
    QLabel *new_labal = new QLabel(this);
    count_enemi++ ;
    random_enemi = randomImages_Enemi[std::rand() % randomImages_Enemi.size()];
    new_labal->setStyleSheet("background-image: url("+ random_enemi +");");
    new_labal->setGeometry(220, 700, 90, 80);
    new_labal->show();
    enemi_list.append(new_labal);
    move_enemi(new_labal);
    logEvent(QString("DEnemy #%1 created.").arg(count_enemi));

    if(wave == 2){

        QApplication::quit();
    }

    if((count_enemi) % ( 5 + wave ) != 0){ // %20
        randomInterval = (std::rand() % 1500) + 500;
    }
    else{
        randomInterval = 10000; //20000
        wave++ ;
        count_enemi = 0;
        logEvent(QString("Wave %1 completed.").arg(wave));
    }

    timer->start(randomInterval);
}


void Gameplay_page :: move_enemi(QLabel *labal){
    QPropertyAnimation *animation = new QPropertyAnimation(labal, "geometry");
    animation->setDuration(4000); //4000
    animation->setStartValue(QRect(215, 700, 90, 80));
    animation->setEndValue(QRect(215, 140, 90, 80));

    QPropertyAnimation *animation2 = new QPropertyAnimation(labal, "geometry");
    animation2->setDuration(4000);
    animation2->setStartValue(QRect(215, 140, 90, 80));
    animation2->setEndValue(QRect(900, 140, 90, 80));

    QPropertyAnimation *animation3 = new QPropertyAnimation(labal, "geometry");
    animation3->setDuration(4000);
    animation3->setStartValue(QRect(900, 140, 90, 80));
    animation3->setEndValue(QRect(900, 625, 90, 80));


    QSequentialAnimationGroup *group = new QSequentialAnimationGroup(this);
    group->addAnimation(animation);
    group->addAnimation(animation2);
    group->addAnimation(animation3);

    connect(animation3, &QPropertyAnimation::finished, this, [this, labal]() {
        labal->hide();
    });

    group->start();

}


void Gameplay_page :: mousePressEvent(QMouseEvent *event){

    if(event->button() == Qt::LeftButton){
        QString logMessage;

        if (event->pos().x() >= 410 && event->pos().x() <= 500 &&
            event->pos().y() >= 640 && event->pos().y() <= 720){
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


        if (event->pos().x() >= 510 && event->pos().x() <= 600 &&
            event->pos().y() >= 640 && event->pos().y() <= 720){
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

        if (event->pos().x() >= 610 && event->pos().x() <= 700 &&
            event->pos().y() >= 640 && event->pos().y() <= 720){
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

        if (event->pos().x() >= 710 && event->pos().x() <= 800 &&
            event->pos().y() >= 640 && event->pos().y() <= 720){
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

        if (current_choice) {
            for (int i = 0; i < 16; ++i) {
                if (event->pos().x() >= agent_board[i]->x() &&
                    event->pos().x() <= agent_board[i]->x() + agent_board[i]->width() &&
                    event->pos().y() >= agent_board[i]->y() &&
                    event->pos().y() <= agent_board[i]->y() + agent_board[i]->height()) {


                    if (agent_board[i]->styleSheet() == "background-image: url(:/prefix2/images/sanng.png);" ){
                        QString oldImage = agent_board[i]->styleSheet();
                        QString newImage;

                        //ezafe kardan aks agent choice be agent choice
                        if (current_choice == agent_choice1) {
                            updateStyleSheetAgentBorad(agent_board[i], randomImage1);
                            newImage = randomImage1;
                        } else if (current_choice == agent_choice2) {
                            updateStyleSheetAgentBorad(agent_board[i], randomImage2);
                            newImage = randomImage2;
                        } else if (current_choice == agent_choice3) {
                            updateStyleSheetAgentBorad(agent_board[i], randomImage3);
                            newImage = randomImage3;
                        } else if (current_choice == agent_choice4) {
                            updateStyleSheetAgentBorad(agent_board[i], randomImage4);
                            newImage = randomImage4;
                        }

                        //set kardan ye aks random baray egent choice
                        if(current_choice == agent_choice1){
                            randomImage1 = randomImages_AgentChoice[std::rand() % randomImages_AgentChoice.size()];
                            updateStyleSheetAgentChoice(agent_choice1, randomImage1);
                        } else if(current_choice == agent_choice2) {
                            randomImage2 = randomImages_AgentChoice[std::rand() % randomImages_AgentChoice.size()];
                            updateStyleSheetAgentChoice(agent_choice2, randomImage2);
                        } else if(current_choice == agent_choice3){
                            randomImage3 = randomImages_AgentChoice[std::rand() % randomImages_AgentChoice.size()];
                            updateStyleSheetAgentChoice(agent_choice3, randomImage3);
                        } else if(current_choice == agent_choice4){
                            randomImage4 = randomImages_AgentChoice[std::rand() % randomImages_AgentChoice.size()];
                            updateStyleSheetAgentChoice(agent_choice4, randomImage4);
                        }


                        logMessage = QString("Changed tile agent board at index %1 from %2 to new image %3.").arg(i).arg(oldImage).arg(newImage);
                        logEvent(logMessage);
                        current_choice = nullptr;

                    }


                }
            }
        }

    }
}


void Gameplay_page::logEvent(const QString &event) {
    QFile file("game_log.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << event << "\n";
        file.close();
    }
}


void Gameplay_page::updateStyleSheetAgentChoice(QWidget* widget, const QString& imageUrl) {
    widget->setStyleSheet("background-image: url(" + imageUrl + "); background-color: rgb(238, 145, 84);");
}

void Gameplay_page::updateStyleSheetAgentBorad(QWidget* widget, const QString& imageUrl){
    widget->setStyleSheet("background-image: url(" + imageUrl + "); background-color: rgb(223, 195, 139);");
}

Gameplay_page::~Gameplay_page()
{
    delete ui;
}
