#include "card.h"
#include "player.h"

Card::Card(QObject *parent) : QObject(parent)
{
    setPlayer(NULL);
}

//metadata: name and description:
QString Card::name() const
{
    return m_name;
}

void Card::setName(const QString &name)
{
    m_name = name;
    emit nameChanged();
}

QString Card::description() const
{
    return m_description;
}

void Card::setDescription(const QString &description)
{
    m_description = description;
    emit descriptionChanged();
}

//origCost and curCost:
int Card::origCost() const
{
    return m_origCost;
}

void Card::setOrigCost(const int &origCost)
{
    if(m_origCost != origCost){
        m_origCost = origCost;
        m_curCost = origCost;
        emit origCostChanged();
        emit curCostChanged();
    }
}

int Card::curCost() const
{
    return m_curCost;
}

void Card::setCurCost(const int &curCost)
{
    m_curCost = curCost;
    emit curCostChanged();
}

//player: the player who controls this card (or the corresponding minion or secret)
Player* Card::player()
{
    return m_player;
}

void Card::setPlayer(Player *player)
{
    if(m_player != player){
        m_player = player;
        emit playerChanged();
    }
}
