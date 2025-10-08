#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // ^1 表示以'1'开头, \d表示数字, 此处进行了二次转义,  {10}表示前面的元素必须出现十次, 这里就是必须要有十个数字
    QRegularExpression regexp("^1\\d{10}$");

    // 为LineEdit设置基于正则表达式的验证器(LineEdit会将对象挂到自己的对象树上)
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regexp));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    int pos = 0;
    QString content = arg1;
    if(ui->lineEdit->validator()->validate(content, pos) == QValidator::Acceptable)
    {
        ui->pushButton->setEnabled(true);
    }
    else
    {
        ui->pushButton->setEnabled(false);
    }
}

