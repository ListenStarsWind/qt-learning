#pragma once

#include <QMainWindow>

#include "Thread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    private:
    void handler();

   private:
    Ui::MainWindow* ui;
    Thread thread;
};
