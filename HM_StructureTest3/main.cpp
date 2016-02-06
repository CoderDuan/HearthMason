#include <QGuiApplication>
#include <QtQuick/QQuickView>
#include <QtQml>

#include "engine.h"
#include "skill.h"
#include "triggerskill.h"

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

    qmlRegisterType<Skill>();
    qmlRegisterType<TriggerSkill>("HearthMason", 1, 0, "TriggerSkill");

    view.setResizeMode(QQuickView::SizeViewToRootObject);
    view.setSource(QUrl("qrc:///Battlefield.qml"));
    view.show();

    return app.exec();
}
