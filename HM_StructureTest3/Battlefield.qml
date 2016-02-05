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

        Minion{
            origATK: 3
            origHP: 5
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
        }
    }
}
