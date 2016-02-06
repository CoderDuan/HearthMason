#include "skill.h"

Skill::Skill(QObject *parent) : QObject(parent)
{
}

Skill::SkillType Skill::type()
{
    return Type_Unknown;
}
