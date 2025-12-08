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
    void Request();
    QString on_message_call_bacl(const QString& request);

   private:
    Ui::Widget* ui;
    QUdpSocket* socket;
};
