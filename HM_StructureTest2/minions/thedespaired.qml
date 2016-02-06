import QtQuick 2.0
import HearthMason 1.0

Minion{
    id: self
    name: "绝望者"
    description: "对该随从的治疗全部改为受到等量的伤害。"
    origATK: 5
    origHP: 8
    skills: [
        TriggerSkill{
            onTriggered: function(event, data){
                if(event === "Recovering"){
                    var target = data.minion
                    if(target === self){
                        var num = data.number
                        data.number = 0

                        //受到等量伤害
                        engine.damage(self, self, num)
                    }
                }
            }
        }
    ]
}
