#include "engine.h"

Engine::Engine(QObject *parent) : QObject(parent)
{
    m_self = new Player(true);
    m_opponent = new Player(false);
}

Engine::~Engine()
{
    delete m_self;
    delete m_opponent;
}

Player* Engine::self()
{
    return m_self;
}

Player* Engine::opponent()
{
    return m_opponent;
}
