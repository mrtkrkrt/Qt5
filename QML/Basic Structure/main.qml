import QtQuick 2.15
import QtQuick.Window 2.15

//ID - must be unique
//Root Object - there can be only one

//Top Level object is the root!

Window {
    width: 800
    height: 600
    visible: true
    title: qsTr("Hello World")
    Text {
        id: denemeText
        text: qsTr("Hello World!")
        anchors.centerIn: parent
        font.bold: true
        font.pixelSize: 23
        z : 1
    }

    property var middle: height / 2

    Image {
        id: ahmet
        source: "https://media-exp1.licdn.com/dms/image/C4E03AQFjb-big6Z4vQ/profile-displayphoto-shrink_800_800/0/1601985386441?e=1651708800&v=beta&t=rOiqvUF-5RLzv0K53CYfMMyk8ITjIU_tHJUTQfkMI5o"
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
        width: 200
        height: 200
        onProgressChanged: console.log(ahmet.progress)
        onStatusChanged: if(ahmet.status == Image.Ready) console.log("Remote image was loaded")
        Rectangle {
            id: rect
            width: parent.width
            height: parent.height
            opacity: 0.5 //50% - 0.0 - 1.0

            color: tapHandler.pressed ? "red" : "blue"

            TapHandler{
                id: tapHandler
            }
        }
    }

    Item {
        id: itemTemp
        width: 100
        height: 100

        Rectangle{
            id: rectTemp
            anchors.fill: parent
            color: "blue"
        }
    }

    Rectangle {
            id: rectTemp2
            x: 100
            color: "red"
            width: 100
            height: 100
            visible: true

            border.color: "#000000"
            border.width: 5

            radius: width

            //Gradients are super easy!
            //https://doc.qt.io/qt-5/qml-qtquick-gradientstop.html

            gradient: Gradient {
                GradientStop {position: 0.0; color: "red"}
                GradientStop {position: 1.0; color: "blue"}
            }
    }
    Text {
            id: myText
            text: qsTr("<html><b>Hello</b> <i><font color='green'>World</font></i></html><br>
    <font color='#C0C0C0'>this is a test</font><br>
    <a href='http://www.voidrealms.com'>my link</a>")
            x: 200
            font.pointSize: 35
            //font.bold: true //might not work
            //font.italic: true //might not work
            color: "red"
            linkColor: "blue"


            onLinkHovered: {
                console.log("Hover: " + link)
                if(link) {
                    myText.font.bold = true
                } else {
                    myText.font.bold = false
                }
            }

            onLinkActivated: Qt.openUrlExternally(link)
    }
    Rectangle {
            id: myArea
            color: "blue"
            width: 200
            height: 200
            y: 100

            MouseArea {
                id: myMouse
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                hoverEnabled: true

                onClicked: {
                    console.log("Clicked: " + mouse.button)
                    if(mouse.button === Qt.LeftButton) parent.color = "green"
                    if(mouse.button === Qt.RightButton) parent.color = "red"
                }

                onDoubleClicked: console.log("Double Clicked: " + mouse.button)
                onPositionChanged: console.log("Position X:" + mouseX + " Y: " + mouseY)
                onEntered: parent.color = "orange"
                onExited: parent.color = "blue"
            }
    }

}
