#include "minion.h"
#include "engine.h"

Minion::Minion(QObject *parent) : QObject(parent){
    m_engine = NULL;
}

int Minion::origATK() const{
    return m_origATK;
}

void Minion::setOrigATK(const int &origATK){
    m_origATK = origATK;
    m_curATK = origATK;
    emit origATKChanged(m_origATK);
    emit curATKChanged(m_curATK);
}

int Minion::origHP() const{
    return m_origHP;
}

void Minion::setOrigHP(const int &origHP){
    m_origHP = origHP;
    m_curHP = origHP;
    m_curMaxHP = origHP;
    emit origHPChanged(m_origHP);
    emit curHPChanged(m_curHP);
}

int Minion::curATK() const{
    return m_curATK;
}

int Minion::curHP() const{
    return m_curHP;
}

int Minion::curMaxHP() const{
    return m_curMaxHP;
}

QString Minion::name() const{
    return m_name;
}

void Minion::setName(const QString &name){
    m_name = name;
    emit nameChanged(m_name);
}

QJSValue Minion::description(){
    //If the description is callable (dynamic description):
    if(m_description.isCallable())
        return m_description.call();
    return m_description;
}

void Minion::setDescription(const QJSValue &description){
    m_description = description;
    emit descriptionChanged(m_description);
}

Engine* Minion::engine(){
    return m_engine;
}

void Minion::setEngine(Engine *eng){
    m_engine = eng;
}

QQmlListProperty<Skill> Minion::skills(){
    return QQmlListProperty<Skill>(this, 0, &skillAppend, &skillCount, &skillAt, &skillClear);
}

void Minion::skillAppend(QQmlListProperty<Skill> *property, Skill *skill){
    Minion *minion = qobject_cast<Minion*>(property->object);
    if(minion && skill){
        minion->m_skills.append(skill);
        minion->skillsChanged();
    }
}

Skill* Minion::skillAt(QQmlListProperty<Skill> *property, int index){
    Minion *minion = qobject_cast<Minion*>(property->object);
    if(minion)
        return minion->m_skills.at(index);
    return NULL;
}

int Minion::skillCount(QQmlListProperty<Skill> *property){
    Minion *minion = qobject_cast<Minion*>(property->object);
    if(minion)
        return minion->m_skills.size();
    return 0;
}

void Minion::skillClear(QQmlListProperty<Skill> *property){
    Minion *minion = qobject_cast<Minion*>(property->object);
    if(minion){
        minion->m_skills.clear();
        minion->skillsChanged();
    }
}

void Minion::trigger(QString eventName, QJSValue data){
    for(int i = 0; i < m_skills.size(); i++){
        if(m_skills[i]->type() == Skill::TypeTrigger){
            TriggerSkill *skill = qobject_cast<TriggerSkill*>(m_skills[i]);
            skill->trigger(eventName, data);
        }
    }
}

void Minion::loseHP(int number){
    m_curHP -= number;
    emit curHPChanged(m_curHP);
}

int Minion::increaseHP(int number){
    int recoverNum = qMin(m_curMaxHP - m_curHP, number);
    if(recoverNum > 0){
        m_curHP += recoverNum;
        emit curHPChanged(m_curHP);
    }
    return recoverNum;
}

void Minion::addBuff(int ATKBuff, int HPBuff){
    m_curATK += ATKBuff;
    m_curMaxHP += HPBuff;
    m_curHP += HPBuff;
    emit curATKChanged(m_curATK);
    emit curMaxHPChanged(m_curMaxHP);
    emit curHPChanged(m_curHP);
}
