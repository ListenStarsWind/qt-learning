#include <QApplication>
#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include <cstdio>

#include "widget.h"

static void qtToStderrMessageHandler(QtMsgType type, const QMessageLogContext& context,
                                     const QString& msg) {
    Q_UNUSED(context);
    const QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    const QByteArray ba = QString("[%1] %2").arg(time, msg).toLocal8Bit();
    fwrite(ba.constData(), 1, ba.size(), stderr);
    fwrite("\n", 1, 1, stderr);
    fflush(stderr);
}

int main(int argc, char* argv[]) {
    // 在 Debug 构建默认启用消息处理器；在 Release 构建中通过环境变量
    // 或命令行参数启用（便于发布后临时打开日志，不需重编译）。
    bool installHandler = false;

#if !defined(NDEBUG)
    // Debug 构建：默认安装
    installHandler = true;
#else
    // Release 构建：检查环境变量或命令行参数
    if (!qgetenv("MYAPP_FORCE_CONSOLE").isEmpty()) {
        installHandler = true;
    }
    // 检查命令行参数 --log-to-console
    for (int i = 1; i < argc; ++i) {
        if (QString::fromLocal8Bit(argv[i]) == QLatin1String("--log-to-console")) {
            installHandler = true;
            break;
        }
    }
#endif

    if (installHandler) {
        // 在应用启动早期安装消息处理器，确保所有 qDebug/qWarning 都被捕获到 stderr
        qInstallMessageHandler(qtToStderrMessageHandler);
    }

    QApplication a(argc, argv);
    a.setStyleSheet("QPushButton { color: red; }");
    Widget w;
    w.show();
    return a.exec();
}
