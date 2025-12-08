#pragma once

#include <QNetworkDatagram>
#include <QUdpSocket>
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
    void on_button_clicked();
    void Response();

   private:
    Ui::Widget* ui;
    QUdpSocket* socket;
    inline static const QString server_ip = "127.0.0.1";
    inline static const quint16 server_port = 8080;
};
