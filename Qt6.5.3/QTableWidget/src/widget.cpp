#include "widget.h"
#include "ui_widget.h"
#include <qpushbutton.h>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  // 插入三个行
  ui->tableWidget->insertRow(0);
  ui->tableWidget->insertRow(1);
  ui->tableWidget->insertRow(2);

  // 插入三个列
  ui->tableWidget->insertColumn(0);
  ui->tableWidget->insertColumn(0);
  ui->tableWidget->insertColumn(0);

  // 设置列表头
  ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("学号"));
  ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("姓名"));
  ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("年龄"));

  // 填入数据
  ui->tableWidget->setItem(0, 0, new QTableWidgetItem("10001"));
  ui->tableWidget->setItem(0, 1, new QTableWidgetItem("张三"));
  ui->tableWidget->setItem(0, 2, new QTableWidgetItem("20"));

  ui->tableWidget->setItem(1, 0, new QTableWidgetItem("10002"));
  ui->tableWidget->setItem(1, 1, new QTableWidgetItem("李四"));
  ui->tableWidget->setItem(1, 2, new QTableWidgetItem("20"));

  ui->tableWidget->setItem(2, 0, new QTableWidgetItem("10003"));
  ui->tableWidget->setItem(2, 1, new QTableWidgetItem("王五"));
  ui->tableWidget->setItem(2, 2, new QTableWidgetItem("20"));

  connect(ui->addRowButton, &QPushButton::clicked, this, &Widget::onAddRowButtonClicked);
  connect(ui->addColumnButton, &QPushButton::clicked, this, &Widget::onAddColumnButtonClicked);
  connect(ui->removeRowButton, &QPushButton::clicked, this, &Widget::onRemoveRowButtonClicked);
  connect(ui->removeColumnButton, &QPushButton::clicked, this, &Widget::onRemoveColumnButtonClicked);
}

Widget::~Widget() { delete ui; }

void Widget::onAddRowButtonClicked() {
    // 如果有三行, 那么下标就是 0 1 2 新行的下标将为三
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);
}

void Widget::onAddColumnButtonClicked() {
    
    int colCount = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(colCount);

    // 如果newColumnHeaderLineEdit有内容
    const QString text = ui->newColumnHeaderLineEdit->text();
    ui->newColumnHeaderLineEdit->clear();
    if(!text.isEmpty())
    {
        ui->tableWidget->setHorizontalHeaderItem(colCount, new QTableWidgetItem(text));
    }
}

void Widget::onRemoveRowButtonClicked() {
    int curRow = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(curRow);
}

void Widget::onRemoveColumnButtonClicked() {
    int curCol = ui->tableWidget->currentColumn();
    ui->tableWidget->removeColumn(curCol);
}
