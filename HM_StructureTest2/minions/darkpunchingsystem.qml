import QtQuick 2.0
import HearthMason 1.0

Minion{
    id: self
    name: "暗影打击装置"
    description: "每当一个随从被治疗后，对一个随机其他随从造成1点伤害。"
    origATK: 2
    origHP: 3
    skills: [
        TriggerSkill{
            onTriggered: function(event, data){
                if(event === "Recovered"){
                    //Get valid minion list:
                    var minionList = engine.minions
                    var validMinionList = []
                    var length = minionList.length
                    for(var i = 0; i < length; i++)
                        if(self !== minionList[i])
                            validMinionList.push(minionList[i])

                    //Generate a random number:
                    if(validMinionList.length == 0)
                        return
                    var index = Math.floor(Math.random() * validMinionList.length)
                    var victim = validMinionList[index]

                    //Deal damage to it:
                    engine.damage(self, victim, 1)
                }
            }
        }
    ]
}
