#ifndef ENGINE_H
#define ENGINE_H

#include "player.h"
#include "time.h"

class Engine : public QObject
{
    Q_OBJECT

    //All properties are read only.
    Q_PROPERTY(Player* self READ self)
    Q_PROPERTY(Player* opponent READ opponent)

public:
    Engine(QObject *parent = 0);
    ~Engine();

    //self and opponent player:
    Player* self();
    Player* opponent();

    //the index of the global summoning queue:
    int index();

    /*below are some tool functions:*/
    Q_INVOKABLE int randomNum(int max, int base = 0);

protected:
    Player* m_self;
    Player* m_opponent;

    int m_index;
};

#endif // ENGINE_H
