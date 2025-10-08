#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 姓名输入框
    ui->lineEditName->setPlaceholderText("请输入你的全名");
    ui->lineEditName->setClearButtonEnabled(true);

    // 性别输入框
    ui->lineEditGender->setPlaceholderText("你的性别是");
    ui->lineEditGender->setClearButtonEnabled(true);

    // 密码输入框
    ui->lineEditPassword->setPlaceholderText("请输入密码");
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditPassword->setClearButtonEnabled(true);

    // 电话号码输入框
    ui->lineEditPhone->setPlaceholderText("请输入电话号码");
    ui->lineEditPhone->setClearButtonEnabled(true);
    ui->lineEditPhone->setInputMask("000-0000-0000");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    qDebug() << "姓名: "<<ui->lineEditName->text()
             << "性别: "<<ui->lineEditGender->text()
             << "密码: "<<ui->lineEditPassword->text()
             << "电话: "<<ui->lineEditPhone->text();
}

