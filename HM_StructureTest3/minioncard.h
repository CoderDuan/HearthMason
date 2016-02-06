#ifndef MINIONCARD_H
#define MINIONCARD_H

#include "card.h"
#include "minion.h"

class MinionCard : public Card
{
    Q_OBJECT
    Q_PROPERTY(Minion* minion READ minion WRITE setMinion NOTIFY minionChanged)
    Q_CLASSINFO("DefaultProperty", "minion")

public:
    MinionCard();

    //minion: the corresponding minion of this minion card.
    Minion* minion();
    void setMinion(Minion* minion);

protected:
    Minion* m_minion;

signals:
    void minionChanged();
};

#endif // MINIONCARD_H
