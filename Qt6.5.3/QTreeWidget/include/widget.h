#pragma once

#include <QWidget>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QTreeWidgetItem* insertTopLevelItem(int column, const QString& text);
    QTreeWidgetItem* insertRootItem(int column, const QString& text);
    QTreeWidgetItem* insertChildItem(QTreeWidgetItem* parent, int column, const QString& text);

    void onAddSelectedButtonClicked();
    void onAddTopLevelButtonClicked();
    void onRemoveSelectedButtonClicked();
private:
    Ui::Widget *ui;
};
