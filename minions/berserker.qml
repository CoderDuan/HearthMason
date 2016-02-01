import QtQuick 2.0
import HearthMason 1.0

Minion{
    id: self
    name: "暴乱狂战士"
    description: "每当一个随从受到伤害后，便获得+1攻击力。"
    origATK: 2
    origHP: 4
    skills: [
        TriggerSkill{
            onTriggered: function(event, data){
                if(event === "DamageReceived"){
                    self.addBuff(1, 0)
                }
            }
        }
    ]
}
