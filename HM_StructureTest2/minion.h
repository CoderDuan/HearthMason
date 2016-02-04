#ifndef MINION_H
#define MINION_H

#include "character.h"

class Minion : public Character
{
    Q_OBJECT
public:
    Minion(QObject* parent = 0);
    int takeDamage(int number);
};

#endif // MINION_H
