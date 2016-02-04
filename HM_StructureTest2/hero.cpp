#include "hero.h"

Hero::Hero()
{

}

int Hero::curAmror() const
{
    return m_armor;
}

Weapon* Hero::weapon()
{
    return m_weapon;
}

void Hero::setWeapon(Weapon *weapon)
{
    m_weapon = weapon;
}

int Hero::takeDamage(int number)
{
    //at least take 1 damage
    if(number <= 0)
        return 0;
    if(number <= m_armor){
        m_armor -= number;
        emit curAmrorChanged(m_armor);
        return 0;
    }
    else{
        int hpDamage = number - m_armor;
        m_armor = 0;
        m_curHP -= hpDamage;
        emit curAmrorChanged(m_armor);
        emit curHPChanged(m_curHP);
        return hpDamage;
    }
    return 0;

}










