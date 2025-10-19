#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // 创建菜单栏
    auto menuBar = new QMenuBar();

    // 将菜单栏设置进菜单栏中
    this->setMenuBar(menuBar);

    // 创建菜单
    QMap<QString, QMenu*> menuMap{{"文件",{}}, {"编辑",{}},{"视图",{}}};
    for(auto it = menuMap.begin(); it != menuMap.end(); ++it)
    {
        const QString& key = it.key();
        QMenu*& value = it.value();
        value = new QMenu(key);
        menuBar->addMenu(value);
    }

    // 添加菜单子项
    QMap<QString, QMap<QString, QAction*>> actionMap;
    for(auto it = menuMap.begin(); it != menuMap.end(); ++it)
    {
        actionMap.insert(it.key(), {});
    }

    QVector<QString> v{"新建", "打开", "保存", "另存为", "退出"};
    for(const auto& text : v)
    {
        auto action = new QAction(text);
        menuMap["文件"]->addAction(action);
        actionMap["文件"].insert(text, action);
    }

    connect(actionMap["文件"]["新建"], &QAction::triggered, this, &MainWindow::handle);    
    connect(actionMap["文件"]["退出"], &QAction::triggered, this, &MainWindow::close);    
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::handle()
{
    qDebug() << "触发新建操作";
}
