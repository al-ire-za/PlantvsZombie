#include "Shielder.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>


Shielder::Shielder(QWidget *parent, int health, double speed)
    : Enemy(parent, health, speed, ":/prefix2/images/4_editai.png") {}

Shielder::Shielder(const Shielder &other)
    : Enemy(other) {}

Shielder::~Shielder() {}

void Shielder::move() {

}
