#include "widget.h"

#include <QPainter>

#include "ui_widget.h"


Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
}

Widget::~Widget() {
    delete ui;
}

void Widget::paintEvent(QPaintEvent* event) {
    (void)event;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 坐标系顺时针旋转 180 度
    painter.rotate(180);

    QPixmap pixmap(":/Furina.png");

    auto width = this->rect().width();
    auto heignt = this->rect().height();

    painter.translate(-width, -heignt);

    // 以新的原点为照片的"左上角位置", 缩放当前widget 宽 高 的大小进行绘制
    painter.drawPixmap(0, 0, width, heignt, pixmap);
}
