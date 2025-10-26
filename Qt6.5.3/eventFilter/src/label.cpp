#include "label.h"

Label::Label(QWidget* parent) : QLabel(parent) {}

bool Label::event(QEvent* event) {
    if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick) {
        qDebug() << "但少闲人如吾两人者人耳";
        return true;
    }

    return QLabel::event(event);
}

void Label::mousePressEvent(QMouseEvent* event) {
    qDebug() << "苏东坡";
}
