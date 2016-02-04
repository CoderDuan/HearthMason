#include "character.h"

Character::Character(QObject *parent) : QObject(parent)
{

}

int Character::origATK() const
{
    return m_origATK;
}

void Character::setOrigATK(const int &origATK)
{
    m_origATK = origATK;
    m_curATK = origATK;
    emit origATKChanged(m_origATK);
    emit curATKChanged(m_curATK);
}

int Character::origHP() const
{
    return m_origHP;
}

void Character::setOrigHP(const int &origHP)
{
    m_origHP = origHP;
    m_curHP = origHP;
    m_curMaxHP = origHP;
    emit origHPChanged(m_origHP);
    emit curHPChanged(m_curHP);
}

int Character::curATK() const
{
    return m_curATK;
}

int Character::curHP() const
{
    return m_curHP;
}

int Character::curMaxHP() const
{
    return m_curMaxHP;
}

QString Character::name() const
{
    return m_name;
}

void Character::setName(const QString &name)
{
    m_name = name;
    emit nameChanged(m_name);
}

QJSValue Character::description(){
    //If the description is callable (dynamic description):
    if(m_description.isCallable())
        return m_description.call();
    return m_description;
}

void Character::setDescription(const QJSValue &description){
    m_description = description;
    emit descriptionChanged(m_description);
}

int Character::takeDamage(int number)
{
    loseHP(number);
    return number;
}

void Character::loseHP(int number){
    m_curHP -= number;
    emit curHPChanged(m_curHP);
}

int Character::increaseHP(int number){
    int recoverNum = qMin(m_curMaxHP - m_curHP, number);
    if(recoverNum > 0){
        m_curHP += recoverNum;
        emit curHPChanged(m_curHP);
    }
    return recoverNum;
}

void Character::addBuff(int ATKBuff, int HPBuff){
    m_curATK += ATKBuff;
    m_curMaxHP += HPBuff;
    m_curHP += HPBuff;
    emit curATKChanged(m_curATK);
    emit curMaxHPChanged(m_curMaxHP);
    emit curHPChanged(m_curHP);
}

QQmlListProperty<Skill> Character::skills(){
    return QQmlListProperty<Skill>(this, 0, &skillAppend, &skillCount, &skillAt, &skillClear);
}

void Character::skillAppend(QQmlListProperty<Skill> *property, Skill *skill){
    Character *character = qobject_cast<Character*>(property->object);
    if(character && skill){
        character->m_skills.append(skill);
        character->skillsChanged();
    }
}

Skill* Character::skillAt(QQmlListProperty<Skill> *property, int index){
    Character *character = qobject_cast<Character*>(property->object);
    if(character)
        return character->m_skills.at(index);
    return NULL;
}

int Character::skillCount(QQmlListProperty<Skill> *property){
    Character *character = qobject_cast<Character*>(property->object);
    if(character)
        return character->m_skills.size();
    return 0;
}

void Character::skillClear(QQmlListProperty<Skill> *property){
    Character *character = qobject_cast<Character*>(property->object);
    if(character){
        character->m_skills.clear();
        character->skillsChanged();
    }
}

void Character::trigger(QString eventName, QJSValue data){
    for(int i = 0; i < m_skills.size(); i++){
        if(m_skills[i]->type() == Skill::TypeTrigger){
            TriggerSkill *skill = qobject_cast<TriggerSkill*>(m_skills[i]);
            skill->trigger(eventName, data);
        }
    }
}

