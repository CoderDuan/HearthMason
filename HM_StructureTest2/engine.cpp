#include "engine.h"

Engine::Engine(QObject *parent) : QObject(parent){
}

Engine::~Engine(){
    foreach(Minion *minion, m_minions)
        minion->deleteLater();
}

Minion* Engine::minionAt(QQmlListProperty<Minion> *property, int index){
    Engine *engine = qobject_cast<Engine*>(property->object);
    if(engine)
        return engine->m_minions.at(index);
    return NULL;
}

int Engine::minionCount(QQmlListProperty<Minion> *property){
    Engine *engine = qobject_cast<Engine*>(property->object);
    if(engine)
        return engine->m_minions.size();
    return 0;
}

QQmlListProperty<Minion> Engine::minions(){
    return QQmlListProperty<Minion>(this, 0, &minionCount, &minionAt);;
}

void Engine::summon(QString minionName){
    QQmlComponent component(qmlEngine(this), QUrl::fromLocalFile("minions/" + minionName + ".qml"));
    if(component.isReady()){
        Minion *minion = qobject_cast<Minion*>(component.create());
        minion->setEngine(this);
        m_minions.push_back(minion);
        emit minionsChanged();
    }
}

void Engine::trigger(QString eventName, QJSValue data){
    for(int i = 0; i < m_minions.size(); i++)
        m_minions[i]->trigger(eventName, data);
}

//Functions based on game rules:
void Engine::damage(Minion *source, Minion *victim, int number){
    if(number <= 0)
        return;

    QQmlEngine* engine = qmlEngine(this);
    QJSValue damageData = engine->newObject();
    damageData.setProperty("source", engine->newQObject(source));
    damageData.setProperty("victim", engine->newQObject(victim));
    damageData.setProperty("number", QJSValue(number));

    //DamageDealing
    trigger("DamageDealing", damageData);

    if(damageData.property("number").toInt() <= 0)
        return;

    //DamageReceiving
    trigger("DamageReceiving", damageData);

    if(damageData.property("number").toInt() <= 0)
        return;

    //Lose HP
    Minion *minion = qobject_cast<Minion*>(damageData.property("victim").toQObject());
    minion->loseHP(damageData.property("number").toInt());

    //DamageDealt
    trigger("DamageDealt", damageData);

    //DamageReceived
    trigger("DamageReceived", damageData);
}

void Engine::recover(Minion *source, int number){
    if(number <= 0)
        return;

    QQmlEngine* engine = qmlEngine(this);
    QJSValue recoverData = engine->newObject();
    recoverData.setProperty("minion", engine->newQObject(source));
    recoverData.setProperty("number", QJSValue(number));

    //Recovering
    trigger("Recovering", recoverData);

    if(recoverData.property("number").toInt() <= 0)
        return;

    //Increase HP
    Minion *minion = qobject_cast<Minion*>(recoverData.property("minion").toQObject());
    int recoveredHP = minion->increaseHP(recoverData.property("number").toInt());

    if(recoveredHP <= 0)
        return;

    //Recovered
    trigger("Recovered", recoverData);
}
