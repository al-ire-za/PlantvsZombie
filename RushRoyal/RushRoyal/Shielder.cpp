#include "Shielder.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>


<<<<<<< HEAD:RushRoyal/RushRoyal/Shielder.cpp
Shielder::Shielder(QWidget *parent)
    : Enemy(parent, 100, 0.5, ":/prefix2/images/4_editai.png") {}
=======
Shielder::Shielder(QWidget *parent, int health, double speed)
    : Enemy(parent, health, speed, ":/prefix2/images/4_editai.png") {}
>>>>>>> 2810e8069d1a50aa421431c3fe073b5bae208eb1:RushRoyal/Shielder.cpp

Shielder::Shielder(const Shielder &other)
    : Enemy(other) {}

Shielder::~Shielder() {}

void Shielder::move() {

}
