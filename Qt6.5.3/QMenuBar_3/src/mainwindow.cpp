#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    auto menu1 = new QMenu("文件(&F)");
    auto menu2 = new QMenu("编辑(&E)");
    auto menu3 = new QMenu("视图(&V)");
    auto menu4 = new QMenu("关于(&A)");

    menuBar->addMenu(menu1);
    menuBar->addMenu(menu2);
    menuBar->addMenu(menu3);
    menuBar->addMenu(menu4);

    auto action1 = new QAction("菜单项1(&H)");
    auto action2 = new QAction("菜单项2(&J)");
    auto action3 = new QAction("菜单项3(&K)");
    auto action4 = new QAction("菜单项4(&L)");

    menu1->addAction(action1);
    menu2->addAction(action2);
    menu3->addAction(action3);
    menu4->addAction(action4);

    connect(action1, &QAction::triggered, this, &MainWindow::handle1);
    connect(action2, &QAction::triggered, this, &MainWindow::handle2);
    connect(action3, &QAction::triggered, this, &MainWindow::handle3);
    connect(action4, &QAction::triggered, this, &MainWindow::handle4);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::handle1()
{
    qDebug() << "action1";    
}

void MainWindow::handle2()
{
    qDebug() << "action2";    
}

void MainWindow::handle3()
{
    qDebug() << "action3";    
}
    

void MainWindow::handle4()
{
    qDebug() << "action4";    
}