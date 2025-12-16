#pragma once

#include <QWidget>
#include <QFile>
#include <QDebug>

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
    static QString loadQSS();
   private:
    Ui::Widget* ui;
};
