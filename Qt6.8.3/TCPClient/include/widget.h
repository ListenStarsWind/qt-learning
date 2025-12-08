#pragma once

#include <QWidget>
#include <QTcpSocket>
#include <QMessageBox>

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
    void button_clicked();

   private:
   QTcpSocket* socket;
    Ui::Widget* ui;
};
