import QtQuick 2.0
import HearthMason 1.0

MinionCard{
    id: card
    name: "淡水鳄"
    description: "我是一只淡水鳄！"
    origCost: 2
    Minion{
        origATK: 2
        origHP: 3
        TriggerSkill{
            triggerFunc: function(){
                console.log("function triggered")
            }
        }
    }
}
