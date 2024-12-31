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
    explicit ResultWindow(QWidget *parent = nullptr);
    ~ResultWindow();
    QLabel *recordwave;
    QLabel *NOEnemyKilled;
    QLabel *elixirused;
    QLabel *recorGame;
    void setRecordWave(int wave);
    void setNOEnemyKilled(int count);
    void setElixirUsed(int elixir);
    void setRecordGame(int record);

private:
    Ui::ResultWindow *ui;
};

#endif // RESULTWINDOW_H
