#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setTextFormat(Qt::PlainText);
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_3->setTextFormat(Qt::MarkdownText);

    ui->label->setText("~~这是一段纯文本~~");
    ui->label_2->setText("<b>这是一段富文本</b");
    ui->label_3->setText("~~这是一段markdown~~");
}

Widget::~Widget()
{
    delete ui;
}
