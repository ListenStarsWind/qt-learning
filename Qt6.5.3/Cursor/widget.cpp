#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pixmap(":/002-atom.png");
    pixmap = pixmap.scaled(24, 24, Qt::KeepAspectRatio);

    QCursor cursor(pixmap, 0, 0);
    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}
