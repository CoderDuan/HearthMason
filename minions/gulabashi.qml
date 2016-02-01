import QtQuick 2.0
import HearthMason 1.0

Minion{
    id: self
    name: "古拉巴什狂暴者"
    description: "每当该随从受到伤害后，获得+3攻击力。"
    origATK: 2
    origHP: 7
    skills: [
        TriggerSkill{
            onTriggered: function(event, data){
                if(event === "DamageReceived"){
                    var victim = data.victim
                    if(victim === self)
                        self.addBuff(3, 0)
                }
            }
        }
    ]
}
