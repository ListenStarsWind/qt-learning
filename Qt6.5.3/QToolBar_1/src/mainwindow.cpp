#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto menu = new QMenu("文件");
    ui->menubar->addMenu(menu);

    auto toolBar = new QToolBar();
    this->addToolBar(toolBar);

    auto action1 = new QAction("保存");
    action1->setIcon(QIcon(":/save.png"));
    action1->setToolTip("点击以保存当前文件");
    toolBar->addAction(action1);

    auto action2 = new QAction("打开");
    action2->setIcon(QIcon(":/open.png"));
    toolBar->addAction(action2);

    menu->addAction(action1);
    menu->addAction(action2);

    connect(action1, &QAction::triggered, this, [](){
        qDebug() << "活动一";
    });

    connect(action1, &QAction::triggered, this, [](){
        qDebug() << "活动二";
    });    
}

MainWindow::~MainWindow() {
    delete ui;
}