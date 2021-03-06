#include "engine.h"

Engine::Engine(QQmlEngine *eng, QObject *parent) : QObject(parent)
{
    m_engine = eng;

    //Random number seed:
    qsrand(time(NULL));

    int flag = randomNum(2);
    m_self = new Player(true, flag == 0, new Hero());
    m_opponent = new Player(false, flag == 1, new Hero());

    m_index = 2; //The summoning queue index of the minions starts from 2. 0 and 1 are for the heros.
}

Engine::~Engine()
{
    m_self->deleteLater();
    m_opponent->deleteLater();
}

Player* Engine::self()
{
    return m_self;
}

Player* Engine::opponent()
{
    return m_opponent;
}

int Engine::index()
{
    return m_index++;
}

//Load card from local file:
Card* Engine::loadCard(QString fileName)
{
    QQmlComponent component(m_engine, QUrl::fromLocalFile("cards/" + fileName + ".qml"));
    if(component.isReady()){
        Card* card = qobject_cast<Card*>(component.create());
        m_engine->setObjectOwnership(card, QQmlEngine::JavaScriptOwnership);
        return card;
    }
    return NULL;
}

//Return a random number between base and (base + max - 1).
int Engine::randomNum(int max, int base)
{
    if(max > 0)
        return base + rand() % max;
    return 0;
}
