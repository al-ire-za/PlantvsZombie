#ifndef WELCOM_PAGE_H
#define WELCOM_PAGE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class welcom_page;
}
QT_END_NAMESPACE

class welcom_page : public QMainWindow
{
    Q_OBJECT

public:
    welcom_page(QWidget *parent = nullptr);
    ~welcom_page();

private slots:
    void on_play_button_clicked();

    void on_agents_clicked();

    void on_enemy_clicked();

    void on_exit_clicked();

private:
    Ui::welcom_page *ui;
};
#endif // WELCOM_PAGE_H
