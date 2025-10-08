#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_textEdit_textChanged()
{
    // toPlainText: 将输入框的实际显示内容以纯文本形式返回
    // 如果文本内容是由html或markdown渲染出来的,
    // 则去除其中的特殊符号, 返回看见的纯文本
    const QString s = ui->textEdit->toPlainText();
    ui->label->setText(s);
}

