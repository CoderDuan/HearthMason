#ifndef ENGINE_H
#define ENGINE_H

#include "player.h"

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

protected:
    Player* m_self;
    Player* m_opponent;
};

#endif // ENGINE_H
