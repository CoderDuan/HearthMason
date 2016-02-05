#ifndef MINION_H
#define MINION_H

#include "character.h"

class MinionCard;
class Player;

class Minion : public Character
{
    Q_OBJECT
    Q_PROPERTY(MinionCard* card READ card NOTIFY cardChanged) //Read only.

public:
    Minion();

    //card: the corresponding minion card of this minion:
    MinionCard* card();
    void setCard(MinionCard* card);

    //player: the player who controls this minion:
    Player* player();
    void setPlayer(Player* player);

protected:
    MinionCard* m_card;

signals:
    void cardChanged();
};

#endif // MINION_H
