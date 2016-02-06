#ifndef ENGINE_H
#define ENGINE_H

#include <QQmlComponent>
#include <QQmlEngine>
#include "player.h"
#include "time.h"

class Engine : public QObject
{
    Q_OBJECT

    //All properties are read only.
    Q_PROPERTY(Player* self READ self)
    Q_PROPERTY(Player* opponent READ opponent)

public:
    Engine(QQmlEngine* eng, QObject *parent = 0);
    ~Engine();

    //self and opponent player:
    Player* self();
    Player* opponent();

    //the index of the global summoning queue:
    int index();

    //load card from local file:
    Card* loadCard(QString fileName);

    /*below are some tool functions:*/
    Q_INVOKABLE int randomNum(int max, int base = 0);

protected:
    Player* m_self;
    Player* m_opponent;
    int m_index;

    //QML engine:
    QQmlEngine* m_engine;
};

#endif // ENGINE_H
