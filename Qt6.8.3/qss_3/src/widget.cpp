#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setStyleSheet("");
    this->setStyleSheet(loadQSS());
}

Widget::~Widget() {
    delete ui;
}

QString Widget::loadQSS() {
    const QString path = QCoreApplication::applicationDirPath() + "/style/style.qss";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Open QSS failed:" << path << file.errorString();
        return {};
    }
    const auto data = QString::fromUtf8(file.readAll());
    return data;
}
