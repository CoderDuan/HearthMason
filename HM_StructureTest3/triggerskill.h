#ifndef TRIGGERSKILL_H
#define TRIGGERSKILL_H

#include <QJSValue>
#include "skill.h"

class TriggerSkill : public Skill
{
    Q_OBJECT
    Q_PROPERTY(QJSValue triggerFunc READ triggerFunc WRITE setTriggerFunc NOTIFY triggerFuncChanged)

public:
    TriggerSkill();

    QJSValue triggerFunc() const;
    void setTriggerFunc(const QJSValue& triggerFunc);

    Q_INVOKABLE SkillType type();

protected:
    QJSValue m_triggerFunc; //The first parameter is a string representing the current event. The second parameter stands for this event's related information.

signals:
    void triggerFuncChanged();
};

#endif // TRIGGERSKILL_H
