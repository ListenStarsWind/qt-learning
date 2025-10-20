#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto toolbar1 = new QToolBar();
    auto toolbar2 = new QToolBar();

    this->addToolBar(Qt::ToolBarArea::LeftToolBarArea,toolbar1);
    this->addToolBar(toolbar2);

    toolbar1->setAllowedAreas(Qt::ToolBarArea::LeftToolBarArea | Qt::ToolBarArea::RightToolBarArea);
    toolbar1->setFloatable(false);
    // toolbar1->setMovable(false);

    auto action1 = new QAction("动作1");
    auto action2 = new QAction("动作2");
    auto action3 = new QAction("动作3");
    auto action4 = new QAction("动作4");

    toolbar1->addAction(action1);
    toolbar1->addAction(action2);
    
    toolbar2->addAction(action3);
    toolbar2->addAction(action4);
}

MainWindow::~MainWindow() {
    delete ui;
}