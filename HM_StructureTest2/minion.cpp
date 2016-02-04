#include "minion.h"

Minion::Minion(QObject* parent)
    :Character(parent)
{

}

int Minion::takeDamage(int number)
{
    loseHP(number);
    return number;
}
