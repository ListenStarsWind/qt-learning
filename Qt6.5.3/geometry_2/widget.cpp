#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    srand(time(nullptr));           // 布下随机数种子
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->label->setText("祝您假期愉快!");
}


void Widget::on_pushButton_2_pressed()
{
    // 获取窗口的尺寸
    int width = this->geometry().width();
    int height = this->geometry().height();

    // 随机数生成新的位置
    int x = rand() % width;
    int y = rand() % height;

    ui->pushButton_2->move(x, y);
}

