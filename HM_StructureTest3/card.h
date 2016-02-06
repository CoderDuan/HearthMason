#ifndef CARD_H
#define CARD_H

#include <QObject>

class Player;

class Card : public QObject
{
    Q_OBJECT
    Q_ENUMS(Class)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(Card::Class cardClass READ cardClass WRITE setCardClass NOTIFY cardClassChanged)
    Q_PROPERTY(int origCost READ origCost WRITE setOrigCost NOTIFY origCostChanged)
    Q_PROPERTY(int curCost READ curCost NOTIFY curCostChanged) //Read only.
    Q_PROPERTY(Player* player READ player NOTIFY playerChanged) //Read only.

public:
    Card(QObject *parent = 0);

    enum Class{
        Class_Neutral = 0,
        Class_Druid,
        Class_Hunter,
        Class_Mage,
        Class_Paladin,
        Class_Priest,
        Class_Rogue,
        Class_Shaman,
        Class_Warlock,
        Class_Warrior
    };

    //metadata: name, class and description:
    QString name() const;
    void setName(const QString &name);
    Class cardClass() const;
    void setCardClass(const Class &cardClass);
    QString description() const;
    void setDescription(const QString &description);

    //cost and curCost:
    int origCost() const;
    void setOrigCost(const int &origCost);
    int curCost() const;
    void setCurCost(const int &curCost);

    //player: the player who controls this card (or the corresponding minion or secret)
    Player* player();
    void setPlayer(Player* player);

protected:
    QString m_name;
    QString m_description;
    Class m_class;
    int m_origCost;
    int m_curCost;
    Player* m_player;

signals:
    void nameChanged();
    void descriptionChanged();
    void cardClassChanged();
    void origCostChanged();
    void curCostChanged();
    void playerChanged();
};

#endif // CARD_H
