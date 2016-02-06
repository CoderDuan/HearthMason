#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QQmlListProperty>
#include "skill.h"

class Character : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int origATK READ origATK WRITE setOrigATK NOTIFY origATKChanged)
    Q_PROPERTY(int origHP READ origHP WRITE setOrigHP NOTIFY origHPChanged)
    Q_PROPERTY(int curATK READ curATK NOTIFY curATKChanged) //Read only.
    Q_PROPERTY(int curHP READ curHP NOTIFY curHPChanged) //Read only.
    Q_PROPERTY(int curMaxHP READ curMaxHP NOTIFY curMaxHPChanged) //Read only.
    Q_PROPERTY(QQmlListProperty<Skill> skills READ skills NOTIFY skillsChanged) //Read only.
    Q_CLASSINFO("DefaultProperty", "skills")

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

    //skills:
    QQmlListProperty<Skill> skills();

    //the summoning order:
    int order() const;
    void setOrder(const int &order);

protected:
    //basic stats. curATK, origATK, curHP, origHP, curMaxHP:
    int m_origATK;
    int m_origHP;
    int m_curATK;
    int m_curHP;
    int m_curMaxHP;

    //skills:
    QList<Skill*> m_skills;

    //the summoning order:
    int m_order;

signals:
    void origATKChanged();
    void origHPChanged();
    void curATKChanged();
    void curHPChanged();
    void curMaxHPChanged();
    void skillsChanged();
};

#endif // CHARACTER_H
