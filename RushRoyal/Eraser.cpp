#include "Eraser.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

Eraser::Eraser(QWidget *parent)
    : Enemy(parent, 2000, 0.25, ":/prefix2/images/Eraser.png") {}

Eraser::Eraser(const Eraser &other)
    : Enemy(other) {}

Eraser::~Eraser() {}

void Eraser::move() {

}
