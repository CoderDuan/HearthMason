#ifndef CARD_H
#define CARD_H

#include <QObject>

class Player;

class Card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(int origCost READ origCost WRITE setOrigCost NOTIFY origCostChanged)
    Q_PROPERTY(int curCost READ curCost NOTIFY curCostChanged) //Read only.
    Q_PROPERTY(Player* player READ player NOTIFY playerChanged) //Read only.

public:
    Card(QObject *parent = 0);

    //metadata: name and description:
    QString name() const;
    void setName(const QString &name);
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
    int m_origCost;
    int m_curCost;
    Player* m_player;

signals:
    void nameChanged();
    void descriptionChanged();
    void origCostChanged();
    void curCostChanged();
    void playerChanged();
};

#endif // CARD_H
