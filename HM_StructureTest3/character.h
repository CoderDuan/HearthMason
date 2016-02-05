#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>

class Character : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int origATK READ origATK WRITE setOrigATK NOTIFY origATKChanged)
    Q_PROPERTY(int origHP READ origHP WRITE setOrigHP NOTIFY origHPChanged)
    Q_PROPERTY(int curATK READ curATK NOTIFY curATKChanged) //Read only.
    Q_PROPERTY(int curHP READ curHP NOTIFY curHPChanged) //Read only.
    Q_PROPERTY(int curMaxHP READ curMaxHP NOTIFY curMaxHPChanged) //Read only.

public:
    Character(QObject* parent = 0);

    //basic stats. curATK, origATK, curHP, origHP, curMaxHP:
    int origATK() const;
    void setOrigATK(const int &origATK);
    int origHP() const;
    void setOrigHP(const int &origHP);
    int curATK() const;
    void setCurATK(const int &curATK);
    int curHP() const;
    void setCurHP(const int &curHP);
    int curMaxHP() const;
    void setCurMaxHP(const int &curMaxHP);

protected:
    int m_origATK;
    int m_origHP;
    int m_curATK;
    int m_curHP;
    int m_curMaxHP;

signals:
    void origATKChanged();
    void origHPChanged();
    void curATKChanged();
    void curHPChanged();
    void curMaxHPChanged();
};

#endif // CHARACTER_H
