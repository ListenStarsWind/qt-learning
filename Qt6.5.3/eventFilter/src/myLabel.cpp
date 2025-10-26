#include "myLabel.h"

myLabel::myLabel(QWidget* parent) : Label(parent) {}

void myLabel::mousePressEvent(QMouseEvent* event) {
    qDebug() << "东坡居士";
}
