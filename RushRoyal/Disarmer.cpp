#include "Disarmer.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

Disarmer::Disarmer(QWidget *parent)
    : Enemy(parent, 2000, 0.25, ":/prefix2/images/Disaemer1.png") {}

Disarmer::Disarmer(const Disarmer &other)
    : Enemy(other) {}

Disarmer::~Disarmer() {}

void Disarmer::move() {
}


// background-image: url(:/prefix2/images/Disaemer1.png);
// background-image: url(:/prefix2/images/boss ezafiai1.png);
// background-image: url(:/prefix2/images/freezerai1.png);
