#include "globalFilter.h"

#include <QWidget>


bool GlobalFilter::eventFilter(QObject* obj, QEvent* event) {
    QWidget* widget = qobject_cast<QWidget*>(obj);
    if (widget != nullptr) {
        if (event->type() == QEvent::MouseButtonPress ||
            event->type() == QEvent::MouseButtonDblClick) {
            qDebug() << "记承天寺夜游";
        }
    }

    return false;
}
