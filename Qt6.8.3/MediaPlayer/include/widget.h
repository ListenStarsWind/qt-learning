#pragma once

#include <QAudioDevice>
#include <QAudioOutput>
#include <QDebug>
#include <QMediaDevices>
#include <QMediaPlayer>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

   public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

   private:
    void play();
    void pause();

   private:
    QMediaPlayer* player;
    QAudioOutput* audio;
    Ui::Widget* ui;
};
