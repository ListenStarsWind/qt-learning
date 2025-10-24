#pragma once

#include <QDebug>
#include <QLabel>
#include <QString>
#include <QMouseEvent>

class Label : public QLabel {
   public:
    Label(QWidget* parent);

   protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
};
