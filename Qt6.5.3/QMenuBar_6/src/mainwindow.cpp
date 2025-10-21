#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto menuBar = this->menuBar();
    this->setMenuBar(menuBar);

    auto menu = new QMenu("文件");
    menu->setIcon(QIcon(":/open.png"));
    menuBar->addMenu(menu);

    auto action1 = new QAction("新建");
    action1->setIcon(QIcon(":/open.png"));
    auto action2 = new QAction("保存");
    action2->setIcon(QIcon(":/save.png"));

    menu->addAction(action1);
    menu->addAction(action2);
}

MainWindow::~MainWindow() {
    delete ui;
}