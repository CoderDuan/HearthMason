#include <QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml>

#include "engine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    QObject::connect(view.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    Engine engine;
    view.rootContext()->setContextProperty("engine", &engine);

    qmlRegisterType<Engine>();
    qmlRegisterType<Player>();

    qmlRegisterType<Character>();
    qmlRegisterType<Hero>();
    qmlRegisterType<Minion>("HearthMason", 1, 0, "Minion");

    qmlRegisterType<Card>();
    qmlRegisterType<MinionCard>("HearthMason", 1, 0, "MinionCard");

    view.setResizeMode(QQuickView::SizeViewToRootObject);
    view.setSource(QUrl("qrc:///Battlefield.qml"));
    view.show();

    return app.exec();
}
