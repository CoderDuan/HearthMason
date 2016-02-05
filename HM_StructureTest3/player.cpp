#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{
    setMaxCrystalNum(0);
    setCurCrystalNum(0);
    setHero(NULL);
}

Player::Player(bool isSelf, QObject *parent) : QObject(parent)
{
    setMaxCrystalNum(0);
    setCurCrystalNum(0);
    setHero(NULL);
    m_isSelf = isSelf;
}

//curCrystalNum and maxCrystalNum:
int Player::curCrystalNum()
{
    return m_curCrystalNum;
}

void Player::setCurCrystalNum(int curCrystalNum)
{
    if(m_curCrystalNum != curCrystalNum){
        m_curCrystalNum = curCrystalNum;
        emit curCrystalNumChanged();
    }
}

int Player::maxCrystalNum()
{
    return m_maxCrystalNum;
}

void Player::setMaxCrystalNum(int maxCrystalNum)
{
    if(m_maxCrystalNum != maxCrystalNum){
        m_maxCrystalNum = maxCrystalNum;
        emit maxCrystalNumChanged();
    }
}

//hero:
Hero* Player::hero()
{
    return m_hero;
}

void Player::setHero(Hero *hero)
{
    if(m_hero != hero){
        m_hero = hero;
        emit heroChanged();
    }
}

//minions:
Minion* Player::minionAt(QQmlListProperty<Minion> *property, int index)
{
    Player *player = qobject_cast<Player*>(property->object);
    if(player)
        return player->m_minions.at(index);
    return NULL;
}

int Player::minionCount(QQmlListProperty<Minion> *property)
{
    Player *player = qobject_cast<Player*>(property->object);
    if(player)
        return player->m_minions.size();
    return 0;
}

QQmlListProperty<Minion> Player::minions()
{
    return QQmlListProperty<Minion>(this, 0, &minionCount, &minionAt);
}

void Player::insertMinion(int index, Minion *minion)
{
    if(minion)
        minion->setPlayer(this);
    m_minions.insert(index, minion);
}

//deck
Card* Player::deckAt(QQmlListProperty<Card> *property, int index)
{
    Player *player = qobject_cast<Player*>(property->object);
    if(player)
        return player->m_deck.at(index);
    return NULL;
}

int Player::deckCount(QQmlListProperty<Card> *property)
{
    Player *player = qobject_cast<Player*>(property->object);
    if(player)
        return player->m_deck.size();
    return 0;
}

QQmlListProperty<Card> Player::deck()
{
    return QQmlListProperty<Card>(this, 0, &deckCount, &deckAt);
}

void Player::appendCard(Card *card)
{
    if(card)
        card->setPlayer(this);
    m_deck.push_back(card);
}

void Player::insertCard(int index, Card *card)
{
    if(card)
        card->setPlayer(this);
    m_deck.insert(index, card);
}

//hand
Card* Player::handAt(QQmlListProperty<Card> *property, int index)
{
    Player *player = qobject_cast<Player*>(property->object);
    if(player)
        return player->m_hand.at(index);
    return NULL;
}

int Player::handCount(QQmlListProperty<Card> *property)
{
    Player *player = qobject_cast<Player*>(property->object);
    if(player)
        return player->m_hand.size();
    return 0;
}

QQmlListProperty<Card> Player::hand()
{
    return QQmlListProperty<Card>(this, 0, &handCount, &handAt);
}

void Player::acquireHandcard(Card *card)
{
    if(card)
        card->setPlayer(this);
    m_hand.push_back(card);
}
