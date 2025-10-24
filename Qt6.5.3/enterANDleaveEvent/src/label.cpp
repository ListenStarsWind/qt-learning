#include "label.h"

Label::Label(QWidget* parent) : QLabel(parent) {}

void Label::enterEvent(QEnterEvent* event) {
    (void) event;
    qDebug() << "enterEvent";
}

void Label::leaveEvent(QEvent* event) {
    (void) event;
    qDebug() << "leaveEvent";
}
