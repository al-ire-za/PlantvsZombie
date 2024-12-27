#include "Shielder.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>


Shielder::Shielder(QWidget *parent)
    : Enemy(parent, 100, 1.25, ":/prefix2/images/4_editai.png") {}

Shielder::Shielder(const Shielder &other)
    : Enemy(other) {}

Shielder::~Shielder() {}

void Shielder::move() {

}
