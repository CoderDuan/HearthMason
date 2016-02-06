#include "triggerskill.h"

TriggerSkill::TriggerSkill()
{
    m_triggerFunc = QJSValue();
}

QJSValue TriggerSkill::triggerFunc() const
{
    return m_triggerFunc;
}

void TriggerSkill::setTriggerFunc(const QJSValue &triggerFunc)
{
    if(triggerFunc.isCallable()){
        m_triggerFunc = triggerFunc;
        emit triggerFuncChanged();
    }
}

Skill::SkillType TriggerSkill::type()
{
    return Type_Trigger;
}
