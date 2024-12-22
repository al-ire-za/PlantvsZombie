#include "Freezer.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

Freezer::Freezer(QWidget *parent)
    : Enemy(parent, 2000, 0.25, ":/prefix2/images/boss ezafiai1.png") {}

Freezer::Freezer(const Freezer &other)
    : Enemy(other) {}

Freezer::~Freezer() {}

void Freezer::move() {

}
