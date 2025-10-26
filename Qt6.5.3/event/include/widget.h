#pragma once

#include <QDebug>
#include <QMouseEvent>
#include <QWidget>


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

    bool event(QEvent* event) override;

   protected:
    void mousePressEvent(QMouseEvent* event) override;

   private:
    Ui::Widget* ui;
};
