#include "minion.h"
#include "minioncard.h"
#include "player.h"

Minion::Minion()
{
    setCard(NULL);
}

MinionCard* Minion::card()
{
    return m_card;
}

void Minion::setCard(MinionCard *card)
{
    if(m_card != card){
        m_card = card;
        emit cardChanged();
    }
}

Player* Minion::player()
{
    if(m_card)
        return m_card->player();
    return NULL;
}

void Minion::setPlayer(Player *player)
{
    if(m_card)
        m_card->setPlayer(player);
}
