#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class ResultWindow;
}

class ResultWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResultWindow(int wave = 0, int count = 0, int elixir = 0, int record = 0, QWidget *parent = nullptr);
    ~ResultWindow();
    QLabel *recordwave;
    QLabel *NOEnemyKilled;
    QLabel *elixirused;
    QLabel *recorGame;
    QLabel *leaderBoard;
    QLabel *resultText;
    void setRecordWave(int wave);
    void setNOEnemyKilled(int count);
    void setElixirUsed(int elixir);
    void setRecordGame(int record);
    void exitGame();
    void restartGame();

private:
    Ui::ResultWindow *ui;
};

#endif // RESULTWINDOW_H
