#pragma once

#include <QMessageBox>
#include <QTcpServer>
#include <QTcpSocket>
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

   private:
    void accept_connection();
    void recv_connection();
    QString on_message_call_back(QString& request);

   private:
    QTcpServer* server;
    Ui::Widget* ui;
};
