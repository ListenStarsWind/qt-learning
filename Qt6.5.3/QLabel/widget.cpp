#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置对齐方式

    // 设置文本
    ui->label->setText("这是一段文本");
    // 设置水平方向(Horizontal)居中, 竖直方向(Vertical)居中对齐
    // ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    // 设置靠右, 竖直居中对齐
    // ui->label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    // 设置靠右, 靠上对齐
    ui->label->setAlignment(Qt::AlignRight | Qt::AlignTop);

    // 设置自动换行
    ui->label_2->setText(
        "星照夜, 夜映星; 星在夜中看光明. 光照夜, 夜藏光, 光与夜里梦相生. "
        "梦生影, 影化形, 形在光中又化影. 影照星, 星入梦, 梦回夜色生无穷. "
        "夜里有光, 光中有夜, 星在光里呼吸着夜; 夜在星下凝望着光, 一息一照, 一照一长. "
        "长生不灭, 灭而复生, 生在光中, 灭在夜中; 星在夜里照夜的星, 夜在星中藏星的梦. "
        "光行夜海, 夜载光舟, 星是灯, 梦是流; 一明一暗, 一来一往, 万象生于这呼吸的荡漾."
        );
    ui->label_2->setWordWrap(true);

    // 设置缩进
    ui->label_3->setText(
        "吾闻二世少子也，不当立，当立者乃公子扶苏。"
        "扶苏以数谏故，上使外将兵。"
        "今或闻无罪，二世杀之。百姓多闻其贤，未知其死也。"
        "项燕为楚将，数有功，爱士卒，楚人怜之。"
        "或以为死，或以为亡。"
        "今诚以吾众诈自称公子扶苏﹑项燕，为天下唱，宜多应者。"
        );
    ui->label_3->setWordWrap(true);
    ui->label_3->setIndent(50);

    //设置边距
    ui->label_4->setText(
        "吾闻二世少子也，不当立，当立者乃公子扶苏。"
        "扶苏以数谏故，上使外将兵。"
        "今或闻无罪，二世杀之。百姓多闻其贤，未知其死也。"
        "项燕为楚将，数有功，爱士卒，楚人怜之。"
        "或以为死，或以为亡。"
        "今诚以吾众诈自称公子扶苏﹑项燕，为天下唱，宜多应者。"
        );
    ui->label_4->setWordWrap(true);
    ui->label_4->setMargin(15);
}

Widget::~Widget()
{
    delete ui;
}
