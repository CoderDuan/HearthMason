#ifndef ENGINE_H
#define ENGINE_H

#include <QQmlEngine>
#include <QList>
#include "minion.h"

class Engine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Minion> minions READ minions NOTIFY minionsChanged)

public:
    Engine(QObject *parent = 0);
    ~Engine();

    QList<Minion*> m_minions;
    QQmlListProperty<Minion> minions();

    Q_INVOKABLE void trigger(QString eventName, QJSValue data); //Note: the parameter [data] is actually passed by reference.
    Q_INVOKABLE void summon(QString minionName);

    //Functions based on game rules:
    Q_INVOKABLE void damage(Minion *source, Minion *victim, int number);
    Q_INVOKABLE void recover(Minion *minion, int number);

private:
    static Minion* minionAt(QQmlListProperty<Minion> *property, int index);
    static int minionCount(QQmlListProperty<Minion> *property);

signals:
    void minionsChanged();
};

#endif // ENGINE_H
