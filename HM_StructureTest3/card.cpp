#include "card.h"

Card::Card(QObject *parent) : QObject(parent)
{
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
