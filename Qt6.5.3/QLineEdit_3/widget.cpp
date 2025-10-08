#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    ui->lineEdit->setPlaceholderText("请输入密码");
    ui->lineEdit_2->setPlaceholderText("请确认密码");

    connect(ui->lineEdit, &QLineEdit::textEdited, this, &Widget::onPassEdited);
    connect(ui->lineEdit_2, &QLineEdit::textEdited, this, &Widget::onPassEdited);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onPassEdited()
{
    const QString s1 = ui->lineEdit->text();
    const QString s2 = ui->lineEdit_2->text();
    if(!s1.isEmpty() && !s2.isEmpty())
    {
        if(s1 == s2)
            ui->label->setText("允许的密码");
        else
            ui->label->setText("不一致的密码");
    }
}
