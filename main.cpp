#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>

#include "user.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    qmlRegisterSingletonType<User>("com.github.siexp", 1, 0, "User",
        [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
           Q_UNUSED(engine)
           Q_UNUSED(scriptEngine)

           auto example = new User();
           return example;
        }
    );

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
