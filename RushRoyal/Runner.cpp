#include "Runner.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

Runner::Runner(QWidget *parent, int health, double speed)
    : Enemy(parent, health, speed, ":/prefix2/images/1_edit.png") {}

Runner::Runner(const Runner &other)
    : Enemy(other) {}

Runner::~Runner() {}

void Runner::move() {

}
