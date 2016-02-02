import QtQuick 2.0
import HearthMason 1.0

Minion{
    id: self
    name: "欺软怕硬的恶霸"
    description: function(){
        return "对体力值小于" + curHP + "的随从造成双倍伤害。"
    }
    origATK: 3
    origHP: 4
    skills: [
        TriggerSkill{
            onTriggered: function(event, data){
                if(event === "DamageDealing"){
                    var victim = data.victim
                    var source = data.source
                    if(source === self && victim.curHP < self.curHP){
                        var num = data.number
                        data.number = 2 * num
                    }
                }
            }
        }
    ]
}
