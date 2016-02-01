import QtQuick 2.0
import HearthMason 1.0

Minion{
    id: self
    name: "肉盾"
    description: "每当其他随从受到伤害时，改为令此随从受到等量伤害。"
    origATK: 1
    origHP: 7
    skills: [
        TriggerSkill{
            onTriggered: function(event, data){
                if(event === "DamageReceiving"){
                    var victim = data.victim
                    if(victim !== self)
                        data.victim = self
                }
            }
        }
    ]
}
