#include "widget.h"
#include "./ui_widget.h"
#include <QTimer>
#include <QDebug>
#include <QStyle>
#include <QPalette>
#include <QStyleOptionProgressBar>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , timer(new QTimer(this))
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    qDebug() << ui->progressBar->style()->objectName();

    QPalette palStyle = ui->progressBar->style()->standardPalette();
    qDebug() << "背景颜色:" << palStyle.color(QPalette::Window);
    qDebug() << "文字颜色:" << palStyle.color(QPalette::WindowText);
    qDebug() << "按钮颜色:" << palStyle.color(QPalette::Button);
    qDebug() << "高亮颜色:" << palStyle.color(QPalette::Highlight);
    qDebug() << "高亮文字:" << palStyle.color(QPalette::HighlightedText);

    QStyleOptionProgressBar opt;
    opt.initFrom(ui->progressBar);
    opt.rect = ui->progressBar->rect();
    opt.minimum = ui->progressBar->minimum();
    opt.maximum = ui->progressBar->maximum();
    opt.progress = ui->progressBar->value();
    opt.textVisible = ui->progressBar->isTextVisible();
    opt.text = ui->progressBar->text();

    QRect textRect = ui->progressBar->style()->subElementRect(QStyle::SE_ProgressBarLabel, &opt);

    QFont font = ui->progressBar->font();
    QPalette palWidget = ui->progressBar->palette();
    QColor textColor = palWidget.color(QPalette::Text);
    if (opt.progress > opt.minimum)
        textColor = palWidget.color(QPalette::HighlightedText);

    qDebug() << "百分比文字:" << opt.text;
    qDebug() << "文字矩形:" << textRect;
    qDebug() << "字体:" << font.toString();
    qDebug() << "颜色:" << textColor;


    connect(timer, &QTimer::timeout, this, &Widget::onProgressBarTimeout);
    timer->start(100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onProgressBarTimeout()
{
    int val = ui->progressBar->value();
    if(val >= 100)
    {
        timer->stop();
        disconnect(timer, &QTimer::timeout, this, &Widget::onProgressBarTimeout);
    }
    else
    {
        val += 1;
        ui->progressBar->setValue(val);
    }
}
