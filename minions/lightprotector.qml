import QtQuick 2.0
import HearthMason 1.0

Minion{
    id: self
    name: "圣光护卫者"
    description: "每当一个随从被治疗后，获得+2攻击力。"
    origATK: 1
    origHP: 3
    skills: [
        TriggerSkill{
            onTriggered: function(event, data){
                if(event === "Recovered"){
                    self.addBuff(2, 0)
                }
            }
        }
    ]
}
