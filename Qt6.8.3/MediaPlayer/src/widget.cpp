#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    audio = new QAudioOutput(this);

    QList<QAudioDevice> devices = QMediaDevices::audioOutputs();

    audio->setDevice(devices[0]);
    audio->setVolume(0.5f);  // 设置输出音量
    // for (int i = 0; i < devices.size(); ++i) {
    //     const QAudioDevice& dev = devices[i];
    //     qDebug() << dev.description();
    // }

    player->setAudioOutput(audio);
    player->setSource(QUrl("qrc:/canon.mp3"));

    connect(ui->playButton, &QPushButton::clicked, this, &Widget::play);
    connect(ui->pauseButton, &QPushButton::clicked, this, &Widget::pause);
}

Widget::~Widget() {
    delete ui;
}

void Widget::play() {
    player->play();
}

void Widget::pause() {
    player->pause();
}
