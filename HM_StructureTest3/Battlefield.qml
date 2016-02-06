import QtQuick 2.0
import HearthMason 1.0

Rectangle {
    width: 600
    height: 400

    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log(engine.self.deck)
        }
    }
}
