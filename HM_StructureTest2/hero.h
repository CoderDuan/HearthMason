#ifndef HERO_H
#define HERO_H

#include <QObject>
#include "character.h"

//class Skill;
class Weapon;

class Hero : public Character
{
    Q_OBJECT
public:
    Hero();

    //stats
    int curArmor() const;

    //weapon
    Weapon* weapon();
    void setWeapon(Weapon* weapon);

    //stats change function
    int takeDamage(int number);
    void increaseArmor(int number);

protected:
    int m_armor;
    Weapon* m_weapon;

signals:
    void curArmorChanged(const int &curArmor);

};

#endif // HERO_H
