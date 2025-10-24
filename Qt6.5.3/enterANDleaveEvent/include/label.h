#pragma once

#include <QLabel>
#include <Qdebug>

class Label : public QLabel {
   public:
    Label(QWidget* parent = nullptr);

    protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;
};