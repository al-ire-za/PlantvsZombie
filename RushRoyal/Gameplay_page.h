#ifndef GAMEPLAY_PAGE_H
#define GAMEPLAY_PAGE_H

#include <QMainWindow>
#include <QLabel>
#include <QPoint>

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
    void updateStyleSheetAgentChoice(QWidget* widget, const QString& imageUrl);
    void updateStyleSheetAgentBorad(QWidget* widget, const QString& imageUrl);
    QVector<QLabel*> enemi_list;


protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::Gameplay_page *ui;
    QTimer *timer;
    QLabel *agent_board[16];
    QStringList randomImages_AgentChoice;
    QStringList randomImages_Enemi;
    QString random_enemi;
    QString randomImage1;
    QString randomImage2;
    QString randomImage3;
    QString randomImage4;

    QLabel *current_choice;
    QLabel *agent_choice1;
    QLabel *agent_choice2;
    QLabel *agent_choice3;
    QLabel *agent_choice4;



};

#endif // GAMEPLAY_PAGE_H
