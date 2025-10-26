#include "button.h"

Button::Button(QWidget* parent) : QPushButton(parent) {}

bool Button::eventFilter(QObject* watched, QEvent* event) {
    if (event->type() == QEvent::MouseButtonDblClick || event->type() == QEvent::MouseButtonPress) {
        qDebug() << "王安石变法";
        return false;
    }

    return false;
}
