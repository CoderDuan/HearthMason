import QtQuick 2.0
import HearthMason 1.0

Rectangle {
    width: 600
    height: 400

    MinionCard{
        id: card
        origCost: 3
        name: "Deathwing"
        description: "Face Deathwing!"
        cardClass: MinionCard.Class_Hunter
        minion: Minion{
            origATK: 3
            origHP: 5

            TriggerSkill{
                triggerFunc: function(){}
            }
            TriggerSkill{
                triggerFunc: function(){console.log("called trigger function")}
            }
            TriggerSkill{

            }
        }
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log(card)
            console.log(card.minion)
            console.log(card.name)
            console.log(card.minion.card)
            console.log(card.minion.curATK)
            console.log(card.cardClass)
            console.log(card.minion.skills.length)
            console.log(card.minion.skills[1])
            console.log(card.minion.skills[1].triggerFunc.call())
            console.log(engine)
            console.log(engine.self)
            console.log(engine.opponent)
            console.log("is myself starting player?", engine.self.isStartingPlayer())
            console.log(engine.self.hero)
            console.log(engine.self.hero.curMaxHP)
        }
    }
}
