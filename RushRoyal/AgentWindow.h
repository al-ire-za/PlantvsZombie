#ifndef AGENTWINDOW_H
#define AGENTWINDOW_H

#include <QMainWindow>

namespace Ui {
class AgentWindow;
}

class AgentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AgentWindow(QWidget *parent = nullptr);
    ~AgentWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AgentWindow *ui;
};

#endif // AGENTWINDOW_H
