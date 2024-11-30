#ifndef GAMEPLAY_PAGE_H
#define GAMEPLAY_PAGE_H

#include <QMainWindow>
#include <QLabel>
#include <QPoint>
#include "Agentbase.h"


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
    void move_enemi(QLabel *labal);
    void logEvent(const QString &event);
    QVector<QLabel*> enemi_list;




protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::Gameplay_page *ui;
    QTimer *timer;
    QVector<AgentBase*> agents;
    QVector<AgentBase*> agent_board;
    QStringList randomImages_Enemi;
    QString random_enemi;
    AgentBase *current_choice;
    AgentBase *agent_choice1;
    AgentBase *agent_choice2;
    AgentBase *agent_choice3;
    AgentBase *agent_choice4;
    void initializeAgents();
    QLabel *label_agentBorad;



};

#endif // GAMEPLAY_PAGE_H
