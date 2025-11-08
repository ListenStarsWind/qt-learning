#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(&thread, &Thread::notify, this, &MainWindow::handler);

    // 线程启动
    thread.start();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::handler()
{
    auto val = ui->lcdNumber->intValue();
    val--;
    ui->lcdNumber->display(val);    
}