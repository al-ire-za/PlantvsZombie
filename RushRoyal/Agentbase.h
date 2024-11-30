#ifndef AGENTBASE_H
#define AGENTBASE_H

#include <QLabel>

namespace Ui {
class AgentBase;
}

class AgentBase : public QLabel
{
    Q_OBJECT

public:
    explicit AgentBase(QWidget *parent = nullptr, const QString &imageUrl = "", int power = 10, int speed = 1);
    ~AgentBase();
    int getpower() const;
    int getspeed() const;
    void updateimagUrl(const QString &image);

protected:
    int AgentBasePower;
    int AgentBasespeed;
    QString AgentBaseimageUrl;


private:
    Ui::AgentBase *ui;
};

#endif // AGENTBASE_H
