#pragma once

#include "label.h"

class myLabel : public Label {
   public:
    myLabel(QWidget* parent);

   protected:
    void mousePressEvent(QMouseEvent* event);
};