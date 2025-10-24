#include "label.h"

Label::Label(QWidget* parent) : QLabel(parent) {}

void Label::mousePressEvent(QMouseEvent* event) {
    QString button = "按下";
    char buffer[64] = {0};

    switch (event->button()) {
        case Qt::MouseButton::LeftButton:
            button += "左键";
            break;
        case Qt::MouseButton::RightButton:
            button += "右键";
            break;
        case Qt::MouseButton::MiddleButton:
            button += "中键";
            break;
        default:
            button += "??";
            break;
    }

    snprintf(buffer, sizeof(buffer), "%s: (%.1f, %.1f)", button.toUtf8().constData(),
             event->position().x(), event->position().y());

    qDebug() << buffer;
}

void Label::mouseReleaseEvent(QMouseEvent* event) {
    QString button = "释放";
    char buffer[64] = {0};

    switch (event->button()) {
        case Qt::MouseButton::LeftButton:
            button += "左键";
            break;
        case Qt::MouseButton::RightButton:
            button += "右键";
            break;
        case Qt::MouseButton::MiddleButton:
            button += "中键";
            break;
        default:
            button += "??";
            break;
    }

    snprintf(buffer, sizeof(buffer), "%s: (%.1f, %.1f)", button.toUtf8().constData(),
             event->position().x(), event->position().y());

    qDebug() << buffer;
}

void Label::mouseDoubleClickEvent(QMouseEvent* event)
{
    QString button = "双击";
    char buffer[64] = {0};

    switch (event->button()) {
        case Qt::MouseButton::LeftButton:
            button += "左键";
            break;
        case Qt::MouseButton::RightButton:
            button += "右键";
            break;
        case Qt::MouseButton::MiddleButton:
            button += "中键";
            break;
        default:
            button += "??";
            break;
    }

    snprintf(buffer, sizeof(buffer), "%s: (%.1f, %.1f)", button.toUtf8().constData(),
             event->position().x(), event->position().y());

    qDebug() << buffer;
}
