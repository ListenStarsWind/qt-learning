#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // 给主窗口添加一个子窗口
    auto dockWidget = new QDockWidget();
    this->addDockWidget(Qt::DockWidgetArea::TopDockWidgetArea, dockWidget);

    // 设置窗口标题
    dockWidget->setWindowTitle("这是一个浮动窗口");

    // 添加其它控件
    auto widget = new QWidget();
    dockWidget->setWidget(widget);

    auto layout = new QVBoxLayout();
    widget->setLayout(layout);

    auto label = new QLabel("标签");
    auto button = new QPushButton("按钮");

    layout->addWidget(label);
    layout->addWidget(button);

    // 仅允许停靠在上边和底部
    dockWidget->setAllowedAreas(Qt::DockWidgetArea::TopDockWidgetArea | Qt::DockWidgetArea::BottomDockWidgetArea);
}

MainWindow::~MainWindow() {
    delete ui;
}