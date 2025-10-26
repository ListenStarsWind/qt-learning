#pragma once

#include <QDebug>
#include <QLabel>
#include <QMouseEvent>

class Label : public QLabel {
   public:
    Label(QWidget* parent);

    bool event(QEvent* event) override;

   protected:
    void mousePressEvent(QMouseEvent* event) override;
};