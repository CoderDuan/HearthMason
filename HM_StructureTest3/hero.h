#ifndef HERO_H
#define HERO_H

#include "character.h"

class Hero : public Character
{
    Q_OBJECT
    Q_PROPERTY(int curArmor READ curArmor NOTIFY curArmorChanged) //Read only.

public:
    Hero();

    //curArmor:
    int curArmor() const;
    void setCurArmor(const int &curArmor);

protected:
    int m_curArmor;

signals:
    void curArmorChanged();
};

#endif // HERO_H
