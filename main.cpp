#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "videoprocessor.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<VideoProcessor>("com.luke", 1, 0, "VideoProcessor");

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("CameraTest", "Main");

    return app.exec();
}
