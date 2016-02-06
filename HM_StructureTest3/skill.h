#ifndef SKILL_H
#define SKILL_H

#include <QObject>

class Skill : public QObject
{
    Q_OBJECT
    Q_ENUMS(SkillType)

public:
    Skill(QObject *parent = 0);

    enum SkillType{
        Type_Unknown,
        Type_Trigger
    };

    Q_INVOKABLE virtual SkillType type();
};

#endif // SKILL_H
