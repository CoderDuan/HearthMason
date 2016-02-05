#include "minion.h"
#include "minioncard.h"

Minion::Minion()
{
    m_card = NULL;
}

MinionCard* Minion::card(){
    return m_card;
}

void Minion::setCard(MinionCard *card){
    if(m_card != card){
        m_card = card;
        emit cardChanged();
    }
}
