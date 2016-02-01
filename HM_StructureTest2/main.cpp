#include <QGuiApplication>
#include <QtQuick/QQuickView>
#include "engine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    QObject::connect(view.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    qmlRegisterType<Engine>("HearthMason", 1, 0, "Engine");
    qmlRegisterType<Minion>("HearthMason", 1, 0, "Minion");
    qmlRegisterType<Skill>("HearthMason", 1, 0, "Skill");
    qmlRegisterType<TriggerSkill>("HearthMason", 1, 0, "TriggerSkill");

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:///Battlefield.qml"));
    view.show();

    return app.exec();
}
