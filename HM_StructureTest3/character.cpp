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
    if(m_origATK != origATK){
        m_origATK = origATK;
        m_curATK = origATK;
        emit origATKChanged();
        emit curATKChanged();
    }
}

int Character::origHP() const
{
    return m_origHP;
}

void Character::setOrigHP(const int &origHP)
{
    if(m_origHP != origHP){
        m_origHP = origHP;
        m_curHP = origHP;
        m_curMaxHP = origHP;
        emit origHPChanged();
        emit curHPChanged();
        emit curMaxHPChanged();
    }
}

int Character::curATK() const
{
    return m_curATK;
}

void Character::setCurATK(const int &curATK)
{
    if(m_curATK != curATK){
        m_curATK = curATK;
        emit curATKChanged();
    }
}

int Character::curHP() const
{
    return m_curHP;
}

void Character::setCurHP(const int &curHP)
{
    if(m_curHP != curHP){
        m_curHP = curHP;
        emit curHPChanged();
    }
}

int Character::curMaxHP() const
{
    return m_curMaxHP;
}

void Character::setCurMaxHP(const int &curMaxHP)
{
    if(m_curMaxHP != curMaxHP){
        m_curMaxHP = curMaxHP;
        emit curMaxHPChanged();
    }
}
