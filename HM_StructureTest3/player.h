#ifndef PLAYER_H
#define PLAYER_H

#include <QQmlListProperty>
#include "card.h"
#include "hero.h"
#include "minion.h"
#include "minioncard.h"

class Player : public QObject
{
    Q_OBJECT

    //All properties are read only:
    Q_PROPERTY(int curCrystalNum READ curCrystalNum NOTIFY curCrystalNumChanged)
    Q_PROPERTY(int maxCrystalNum READ maxCrystalNum NOTIFY maxCrystalNumChanged)
    Q_PROPERTY(Hero* hero READ hero NOTIFY heroChanged)
    Q_PROPERTY(QQmlListProperty<Minion> minions READ minions NOTIFY minionsChanged)
    Q_PROPERTY(QQmlListProperty<Card> deck READ deck NOTIFY deckChanged)
    Q_PROPERTY(QQmlListProperty<Card> hand READ hand NOTIFY handChanged)

public:
    Player(QObject *parent = 0);
    Player(bool isSelf, bool isStartingPlayer, Hero *hero, QObject *parent = 0);
    ~Player();

    int curCrystalNum();
    void setCurCrystalNum(int curCrystalNum);
    int maxCrystalNum();
    void setMaxCrystalNum(int maxCrystalNum);

    Hero* hero();
    void setHero(Hero* hero);

    QQmlListProperty<Minion> minions();
    void insertMinion(int index, Minion* minion);

    QQmlListProperty<Card> deck();
    void appendCard(Card* card);
    void insertCard(int index, Card* card);

    QQmlListProperty<Card> hand();
    void acquireHandcard(Card* card);

    Q_INVOKABLE bool isSelf();
    Q_INVOKABLE bool isStartingPlayer();

protected:
    //This player's deck and hand, as well as his minions and secrets in the battlefield.
    QList<Card*> m_deck;
    QList<Card*> m_hand;
    QList<Minion*> m_minions;

    static Minion* minionAt(QQmlListProperty<Minion> *property, int index);
    static int minionCount(QQmlListProperty<Minion> *property);

    static Card* deckAt(QQmlListProperty<Card> *property, int index);
    static int deckCount(QQmlListProperty<Card> *property);

    static Card* handAt(QQmlListProperty<Card> *property, int index);
    static int handCount(QQmlListProperty<Card> *property);

    //This player's crystal:
    int m_curCrystalNum;
    int m_maxCrystalNum;

    //This player's hero:
    Hero* m_hero;

    //Is this player self or opponent?
    bool m_isSelf;
    //Is this player starting player?
    bool m_isStartingPlayer;

signals:
    void curCrystalNumChanged();
    void maxCrystalNumChanged();
    void heroChanged();
    void minionsChanged();
    void deckChanged();
    void handChanged();
};

#endif // PLAYER_H
