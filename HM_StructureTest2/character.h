#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QtQml>
#include <QDebug>

#include "skill.h"

class Character : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QJSValue description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(int origATK READ origATK WRITE setOrigATK NOTIFY origATKChanged)
    Q_PROPERTY(int origHP READ origHP WRITE setOrigHP NOTIFY origHPChanged)
    Q_PROPERTY(int curATK READ curATK NOTIFY curATKChanged)
    Q_PROPERTY(int curHP READ curHP NOTIFY curHPChanged)
    Q_PROPERTY(int curMaxHP READ curMaxHP NOTIFY curMaxHPChanged)
    Q_PROPERTY(QQmlListProperty<Skill> skills READ skills NOTIFY skillsChanged)

public:
    Character(QObject* parent = 0);

    //basic stats. curATK, OrigATK, curHP, OrigHP, curMaxHP
    int origATK() const;
    void setOrigATK(const int &origATK);
    int origHP() const;
    void setOrigHP(const int &origHP);
    int curATK() const;
    int curHP() const;
    int curMaxHP() const;

    //name and description
    QString name() const;
    void setName(const QString &name);
    QJSValue description();
    void setDescription(const QJSValue& description);

    //skills
    QList<Skill*> m_skills;
    QQmlListProperty<Skill> skills();

    //trigger
    void trigger(QString eventName, QJSValue data);

    //stats change function
    virtual int takeDamage(int number);//Returns the actual number of Armor Increased.
    void loseHP(int number);
    int increaseHP(int number); //Returns the actual number of HP increased.
    Q_INVOKABLE void addBuff(int ATKBuff, int HPBuff);

protected:
    int m_origATK;
    int m_origHP;
    int m_curATK;
    int m_curHP;
    int m_curMaxHP;

    QString m_name;
    QJSValue m_description;

    static void skillAppend(QQmlListProperty<Skill> *property, Skill *skill);
    static Skill* skillAt(QQmlListProperty<Skill> *property, int index);
    static int skillCount(QQmlListProperty<Skill> *property);
    static void skillClear(QQmlListProperty<Skill> *property);

signals:
    void curATKChanged(const int& curATK);
    void curHPChanged(const int& curHP);
    void origATKChanged(const int& origATK);
    void origHPChanged(const int& origHP);
    void curMaxHPChanged(const int& curMaxHP);
    void nameChanged(const QString& name);
    void descriptionChanged(const QJSValue& description);
    void skillsChanged();

};

#endif // CHARACTER_H
