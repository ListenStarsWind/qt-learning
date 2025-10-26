#include "widget.h"

#include "ui_widget.h"

Widget::Widget(QWidget* parent)
    : QWidget(parent), ui(new Ui::Widget), globalFilter(new GlobalFilter()) {
    ui->setupUi(this);

    ui->label->installEventFilter(this);
    ui->label->installEventFilter(ui->button);

    qApp->installEventFilter(globalFilter);
}

Widget::~Widget() {
    delete ui;
    delete globalFilter;
}

bool Widget::eventFilter(QObject* obj, QEvent* event) {
    // 双键也拦截, 防止实验按得太快误识别
    if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick) {
        qDebug() << "黄州团练副史";
        return true;
    }

    return false;
}

void Widget::mousePressEvent(QMouseEvent* event) {
    qDebug() << "乌台诗案";
}
