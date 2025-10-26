#pragma once

#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>

class Button : public QPushButton{
    public:
    Button(QWidget* parent);

    bool eventFilter(QObject *watched, QEvent* event) override;
};