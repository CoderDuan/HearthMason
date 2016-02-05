#include "minioncard.h"

MinionCard::MinionCard()
{
    m_minion = NULL;
}

Minion* MinionCard::minion(){
    return m_minion;
}

void MinionCard::setMinion(Minion *minion){
    if(m_minion != minion){
        m_minion = minion;
        m_minion->setCard(this);
        emit minionChanged();
    }
}
