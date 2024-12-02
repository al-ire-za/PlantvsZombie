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
    AgentBase(QWidget *parent = nullptr, const QString &imageUrl = "", int power = 10, int fireRate = 1);
    AgentBase(const AgentBase &other);
    virtual ~AgentBase();
    int getpower() const;
    int getspeed() const;
    void updateimagUrl(const QString &image);
    void startShooting();


public slots:
    virtual void shoot();


signals:
    void bulletFired(int damage, const QRect &startRect);


protected:
    int AgentBasePower;
    int AgentBaseFireRate;
    QTimer *fireTimer;
    QString AgentBaseimageUrl;


private:
    Ui::AgentBase *ui;
};

#endif // AGENTBASE_H
