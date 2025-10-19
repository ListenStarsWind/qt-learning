#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    auto menu4 = new QMenu("查看");
    menuBar->addMenu(menu4);

    auto menu4_3 = new QMenu("外观");
    menu4->addMenu(menu4_3);

    auto menu4_3_11 = new QMenu("面板位置");
    menu4_3->addMenu(menu4_3_11);

    auto action = new QAction("底部");
    menu4_3_11->addAction(action);
}

MainWindow::~MainWindow() {
    delete ui;
}
