#include "widget.h"

#include <qpushbutton.h>
#include <qtreewidget.h>

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    // 添加 header 名
    ui->treeWidget->setHeaderLabel("动画中的动物形象");

    // 插入顶层节点
    auto cat = insertTopLevelItem(0, "猫");
    auto dog = insertRootItem(0, "狗");

    // 插入更深的节点
    insertChildItem(cat, 0, "加菲猫");
    insertChildItem(cat, 0, "汤姆");
    insertChildItem(cat, 0, "猫咪老师");

    insertChildItem(dog, 0, "史努比");
    insertChildItem(dog, 0, "布鲁托");
    insertChildItem(dog, 0, "斯派克");

    connect(ui->addSelectedButton, &QPushButton::clicked, this,
            &Widget::onAddSelectedButtonClicked);
    connect(ui->addTopLevelButton, &QPushButton::clicked, this,
            &Widget::onAddTopLevelButtonClicked);
    connect(ui->removeSelectedButton, &QPushButton::clicked, this,
            &Widget::onRemoveSelectedButtonClicked);
}

Widget::~Widget() {
    delete ui;
}

QTreeWidgetItem* Widget::insertTopLevelItem(int column, const QString& text) {
    // 新增顶层节点
    auto item = new QTreeWidgetItem();
    // 在指定列增加文本
    item->setText(column, text);
    ui->treeWidget->addTopLevelItem(item);
    return item;
}

QTreeWidgetItem* Widget::insertRootItem(int column, const QString& text) {
    auto item = new QTreeWidgetItem();
    item->setText(column, text);
    ui->treeWidget->invisibleRootItem()->addChild(item);
    return item;
}

QTreeWidgetItem* Widget::insertChildItem(QTreeWidgetItem* parent, int column, const QString& text) {
    auto item = new QTreeWidgetItem();
    item->setText(column, text);
    parent->addChild(item);
    return item;
}

void Widget::onAddSelectedButtonClicked() {
    auto parent = ui->treeWidget->currentItem();
    if (parent != nullptr) {
        const QString text = ui->lineEdit->text();
        insertChildItem(parent, 0, text);
        ui->lineEdit->clear();
    }
}

void Widget::onAddTopLevelButtonClicked() {
    const QString text = ui->lineEdit->text();
    insertTopLevelItem(0, text);
    ui->lineEdit->clear();
}

void Widget::onRemoveSelectedButtonClicked() {
    auto child = ui->treeWidget->currentItem();
    if (child == nullptr) return;  // 没有选中的内容不删

    // 获取父节点
    auto parent = child->parent();
    if (parent == nullptr) {
        // 父节点为空, 意味着这是顶层节点
        auto idx = ui->treeWidget->indexOfTopLevelItem(child);
        ui->treeWidget->takeTopLevelItem(idx);
    } else {
        // 父节点不为空, 意味着这不是顶层节点, 当做一般Item来删除
        parent->removeChild(child);
    }
}
