import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Grid {
            spacing: 5
            rows: 3
            columns: 2

            MyShape {color: "red"}
            MyShape {color: "yellow"}
            MyShape {color: "green"}
            MyShape {color: "blue"}
            MyShape {color: "black"}
            MyShape {color: "gray"}
            MyShape {color: "teal"}
            MyShape {color: "brown"}
            MyShape {color: "orange"}
        }
    Row {
            x: 300
            spacing: 2

            MyShape {color: "red"}
            MyShape {color: "blue"}
            MyShape {color: "green"}
        }

    Column {
        x: 300
        y: 300
        spacing: 2

        MyShape {color: "red"}
        MyShape {color: "blue"}
        MyShape {color: "green"}
    }
}
