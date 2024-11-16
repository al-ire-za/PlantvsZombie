#ifndef GAMEPLAY_PAGE_H
#define GAMEPLAY_PAGE_H

#include <QMainWindow>
#include <QLabel>

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
    QVector<QLabel*> labels;

private:
    Ui::Gameplay_page *ui;
    QTimer *timer;
};

#endif // GAMEPLAY_PAGE_H
