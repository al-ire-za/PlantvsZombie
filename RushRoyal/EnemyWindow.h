#ifndef ENEMYWINDOW_H
#define ENEMYWINDOW_H

#include <QMainWindow>

namespace Ui {
class EnemyWindow;
}

class EnemyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EnemyWindow(QWidget *parent = nullptr);
    ~EnemyWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EnemyWindow *ui;
};

#endif // ENEMYWINDOW_H
