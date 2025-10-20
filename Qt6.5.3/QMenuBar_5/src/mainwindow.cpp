#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    auto menu = new QMenu("菜单");
    menuBar->addMenu(menu);

    auto action1 = new QAction("菜单项1");
    auto action2 = new QAction("菜单项2");
    
    menu->addAction(action1);
    menu->addSeparator();
    menu->addAction(action2);
}

MainWindow::~MainWindow() {
    delete ui;
}