import QtQuick 2.0
import HearthMason 1.0

Rectangle {
    id: root
    width: 600
    height: 400
    color: "gray"

    Engine{
        id: engine
    }

    Rectangle{
        id: bottomRect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: 40
        color: "purple"

        Rectangle{
            id: button
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.margins: 5
            height: 30
            width: 100
            radius: 4
            color: "#dddddd"

            Text{
                anchors.centerIn: parent
                text: "Summon"
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    engine.summon(input.text)
                }
            }
        }

        TextInput{
            id: input
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.right: button.left
            anchors.bottom: parent.bottom
            anchors.margins: 5
            verticalAlignment: TextInput.AlignVCenter
            color: "white"
        }
    }

    Component{
        id: minionDelegate

        Rectangle{
            id: minion
            width: 120
            height: 180
            radius: 8
            color: "lightblue"
            border.width: damageSource == modelData ? 2 : 0

            Text{
                id: nameText
                y: 10
                height: 30
                anchors.left: parent.left
                anchors.right: parent.right
                text: modelData.name
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text{
                id: atkText
                width: 20
                height: 30
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.margins: 8
                text: modelData.curATK
                font.bold: true
                color: {
                    if(modelData.origATK < modelData.curATK)
                        return "green"
                    else
                        return "black"
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text{
                id: hpText
                width: 20
                height: 30
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.margins: 8
                text: modelData.curHP
                font.bold: true
                color: {
                    if(modelData.curHP < modelData.curMaxHP)
                        return "red"
                    else if(modelData.curHP > modelData.origHP)
                        return "green"
                    else
                        return "black"
                }
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text{
                id: descriptionText
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: nameText.bottom
                anchors.bottom: hpText.top
                anchors.margins: 8
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                text: modelData.description
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(root.currentMode == 1){
                        if(damageSource == undefined){
                            damageSource = modelData
                        }else{
                            modelData.engine.damage(damageSource, modelData, 1)
                            damageSource = undefined
                        }
                    }else if(root.currentMode == 2){
                        modelData.engine.recover(modelData, 1)
                    }
                }
            }
        }
    }

    property int currentMode: 1 // 1:damage 2:heal
    property var damageSource: undefined

    Rectangle{
        id: damagingSword
        anchors.right: parent.right
        anchors.bottom: bottomRect.top
        anchors.margins: 5
        height: 30
        width: 100
        radius: 4
        color: "red"
        border.width: currentMode == 1 ? 2 : 0

        Text{
            anchors.centerIn: parent
            text: "Damage 1"
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(damageSource == undefined)
                    root.currentMode = 1
            }
        }
    }

    Rectangle{
        id: healingHand
        anchors.right: damagingSword.left
        anchors.bottom: bottomRect.top
        anchors.margins: 5
        height: 30
        width: 100
        radius: 4
        color: "green"
        border.width: currentMode == 2 ? 2 : 0

        Text{
            anchors.centerIn: parent
            text: "Heal 1"
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(damageSource == undefined)
                    root.currentMode = 2
            }
        }
    }

    ListView{
        id: minionList
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: bottomRect.top
        model: engine.minions
        delegate: minionDelegate
        orientation: ListView.Horizontal
        interactive: false
        spacing: 5
    }
}
