import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14

import com.github.siexp 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        spacing: 4
        Text {
            id: username
            text: User.username
        }
        Text {
            id: email
            text: User.email
        }
        Text {
            id: balance
            text: (User.balance / 100).toFixed(2)
        }
    }

    Button {
        anchors{
            right: parent.right
            bottom: parent.bottom
        }

        text: "Add 9.99$"

        onClicked: {
            User.balance += 999
        }
    }

    BalanceView {
        visible: true;
    }
}
