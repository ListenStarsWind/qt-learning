#include "widget.h"

#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
}

Widget::~Widget() {
    delete ui;
}

void Widget::paintEvent(QPaintEvent* event)
{
    (void) event;

    // 注意, 这里的 this 可不是父对象, 我们之前说过的, 栈上对象不应该加到对象树里
    // 这里的参数 this, 表示的是谁作为画板 QPaintDevice
    QPainter painter(this);
    // 打开抗锯齿, 否则边缘看着不舒服
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen;
    pen.setColor(QColor(255, 0, 0));
    pen.setWidth(5);
    pen.setStyle(Qt::PenStyle::DashLine);
    
    // 设置进绘画者
    painter.setPen(pen);

    QBrush brush;
    brush.setColor(QColor(0, 255, 0));
    brush.setStyle(Qt::BrushStyle::DiagCrossPattern);

    painter.setBrush(brush);

    painter.drawEllipse(200, 200, 400, 100);
}
