#pragma once

#include <QDebug>
#include <QFileDialog>
#include <QFileInfo>
#include <QWidget>
#include <QPointer>
#include <QPushButton>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

   public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

   private:
    Ui::Widget* ui;
};
