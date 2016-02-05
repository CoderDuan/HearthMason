#include "hero.h"

Hero::Hero()
{
    setOrigATK(0);
    setOrigHP(30); //Each hero has 30HP at the beginning of the game.
    setCurArmor(0);
}

int Hero::curArmor() const
{
    return m_curArmor;
}

void Hero::setCurArmor(const int &curArmor)
{
    if(m_curArmor != curArmor){
        m_curArmor = curArmor;
        emit curArmorChanged();
    }
}
