#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_up_clicked()
{
    QRect rect = ui->rect->geometry();  // 获取几何属性
    qDebug() << rect;                   // QDebug支持对Qt中绝大多数类型的打印
    // rect.setY(rect.y() - 5);            // 上移五个像素点
    // ui->rect->setGeometry(rect);        // 把属性写回去, 使之生效

    ui->rect->setGeometry(rect.x(), rect.y()-5, rect.width(), rect.height());
}


void Widget::on_down_clicked()
{
    QRect rect = ui->rect->geometry();
    qDebug() << rect;
    // rect.setY(rect.y() + 5);
    // ui->rect->setGeometry(rect);

    ui->rect->setGeometry(rect.x(), rect.y()+5, rect.width(), rect.height());
}


void Widget::on_left_clicked()
{
    QRect rect = ui->rect->geometry();
    qDebug() << rect;
    // rect.setX(rect.x() - 5);
    // ui->rect->setGeometry(rect);

    ui->rect->setGeometry(rect.x()-5, rect.y(), rect.width(), rect.height());
}


void Widget::on_right_clicked()
{
    QRect rect = ui->rect->geometry();
    qDebug() << rect;
    // rect.setX(rect.x() + 5);
    // ui->rect->setGeometry(rect);

    ui->rect->setGeometry(rect.x()+5, rect.y(), rect.width(), rect.height());
}

