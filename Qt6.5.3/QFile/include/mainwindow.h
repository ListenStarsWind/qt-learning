#pragma once

#include <QApplication>
#include <QFile>
#include <QFileDialog>
#include <QFont>
#include <QMainWindow>
#include <QMessageBox>
#include <QSaveFile>
#include <QScopedPointer>
#include <QTextEdit>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void onOpenActionTriggered();
    void onSaveActionTriggered();

   private:
    Ui::MainWindow* ui;
    QTextEdit* textEdit;
};
