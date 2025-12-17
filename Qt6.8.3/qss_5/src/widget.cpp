#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    QString style = "QComboBox::down-arrow {image: url(:/down.png)}";
    this->setStyleSheet(style);
}

Widget::~Widget() {
    delete ui;
}
