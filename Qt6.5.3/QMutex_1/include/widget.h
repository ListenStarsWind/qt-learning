#pragma once

#include <QWidget>
#include <memory>
#include "thread.h"

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

   private:
    Ui::Widget* ui;
    int tickets;
    QMutex mutex;
    std::unique_ptr<Thread> thread1;
    std::unique_ptr<Thread> thread2;
};
