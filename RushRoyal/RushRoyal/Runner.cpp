#include "Runner.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

<<<<<<< HEAD:RushRoyal/RushRoyal/Runner.cpp
Runner::Runner(QWidget *parent)
    : Enemy(parent, 50, 1.00, ":/prefix2/images/1_edit.png") {}
=======
Runner::Runner(QWidget *parent, int health, double speed)
    : Enemy(parent, health, speed, ":/prefix2/images/1_edit.png") {}
>>>>>>> 2810e8069d1a50aa421431c3fe073b5bae208eb1:RushRoyal/Runner.cpp

Runner::Runner(const Runner &other)
    : Enemy(other) {}

Runner::~Runner() {}

void Runner::move() {

}
