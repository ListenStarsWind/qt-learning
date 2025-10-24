#pragma once

#include <QDebug>
#include <QWheelEvent>
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

   protected:
    void wheelEvent(QWheelEvent* event) override;

   private:
    Ui::Widget* ui;
};
