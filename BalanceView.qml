import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14

import com.github.siexp 1.0

ApplicationWindow {
    width: 640
    height: 480

    title: "Balance View"
    Text {
        anchors.fill: parent
        text: "Balance of user %1 is %2".arg(User.username).arg((User.balance / 100).toFixed(2))
    }
}
