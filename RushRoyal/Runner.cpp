#include "Runner.h"
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>

Runner::Runner(QWidget *parent)
    : Enemy(parent, 50, 1.00, ":/prefix2/images/1_edit.png") {}

Runner::Runner(const Runner &other)
    : Enemy(other) {}

Runner::~Runner() {}

void Runner::move() {

}
