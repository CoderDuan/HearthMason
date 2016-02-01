#ifndef SKILL_H
#define SKILL_H

#include <QObject>
#include <QJSValue>

class Skill : public QObject
{
    Q_OBJECT
public:
    Skill(QObject *parent = 0);

    enum SkillType{TypeUnknown, TypeTrigger};

    virtual SkillType type();
};

class TriggerSkill : public Skill
{
    Q_OBJECT
    Q_PROPERTY(QJSValue onTriggered READ onTriggered WRITE setOnTriggered NOTIFY onTriggeredChanged)

public:
    TriggerSkill(QObject *parent = 0);

    QJSValue m_onTriggered;
    QJSValue onTriggered();
    void setOnTriggered(const QJSValue& onTriggered);

    SkillType type();

    void trigger(QString eventName, QJSValue data);

signals:
    void onTriggeredChanged();
};

#endif // SKILL_H
