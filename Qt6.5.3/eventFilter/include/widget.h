#pragma once

#include <QApplication>
#include <QDebug>
#include <QMouseEvent>
#include <QWidget>

#include "globalFilter.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

   public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

    bool eventFilter(QObject* obj, QEvent* event) override;

   protected:
    void mousePressEvent(QMouseEvent* event) override;

   private:
    Ui::Widget* ui;
    GlobalFilter* globalFilter;
};
