#pragma once

#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <Qlabel>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};
