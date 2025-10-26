#pragma once

#include <QDebug>
#include <QMouseEvent>
#include <QObject>


class GlobalFilter : public QObject {
   public:
    bool eventFilter(QObject* obj, QEvent* event) override;
};
