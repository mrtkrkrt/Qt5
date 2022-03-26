import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 800
    height: 500
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: myRect
        width: 100
        height: 100
        color: "orange"

        function update(){
            console.log(x + ", " + y)
            label.text = Math.round(x) + "x" + Math.round(y)
        }

        x: 100
        y: 100

        onXChanged: update()
        onYChanged: update()
        Component.onCompleted: update()

        Text {
            id: label
            text: qsTr("Hello World!")
            anchors.centerIn: parent
        }
        MouseArea {
            anchors.fill: parent
            drag.target: parent
        }
    }
}
