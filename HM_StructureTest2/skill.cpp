#include "skill.h"

Skill::Skill(QObject *parent) : QObject(parent){
}

Skill::SkillType Skill::type(){
    return TypeUnknown;
}

TriggerSkill::TriggerSkill(QObject *parent) : Skill(parent){
}

QJSValue TriggerSkill::onTriggered(){
    return m_onTriggered;
}

void TriggerSkill::setOnTriggered(const QJSValue &onTriggered){
    m_onTriggered = onTriggered;
    emit onTriggeredChanged();
}

Skill::SkillType TriggerSkill::type(){
    return TypeTrigger;
}

void TriggerSkill::trigger(QString eventName, QJSValue data){
    if(m_onTriggered.isCallable()){
        QJSValueList args;
        args << eventName << data;
        m_onTriggered.call(args);
    }
}
