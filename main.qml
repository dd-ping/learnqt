import QtQuick 2.12
import QtQuick.Controls 2.0
//将c++类型导入
import he.TestObj.Color 1.0

Rectangle {
    width: 360;
    height: 360;

    Text {
        id: ttext;
        anchors.left: parent.left;
        anchors.leftMargin: 4;
        anchors.top: parent.top;
        anchors.topMargin: 4;
        font.pixelSize: 32;
    }
    TestObj{
        id:testObj;
        color:Qt.green;
    }
    Rectangle{
        id:colorRect;
        anchors.centerIn: parent;
        width: 150;
        height: 150;
        color: "blue";
    }
    Button{
        id:start;
        text: "Start";
        anchors.left: parent.left;
        anchors.leftMargin: 4;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 4;
        onClicked: {
           testObj.start();
        }

    }
    Button{
        id:stop;
        text:"Stop";
        anchors.left: start.right;
        anchors.leftMargin: 4;
        anchors.bottom: start.bottom;

        onClicked: {
            testObj.stop();
        }
    }

    function changeAlgorithm(button,algorithm){
        switch(algorithm){
        case 0:
            button.text="RandomRGB";
            break;
        case 1:
            button.text="RandomRed";
            break;
        case 2:
            button.text="RandomBlue";
            break;
        case 3:
            button.text="RandomGreen";
            break;
        case 4:
            button.text="LinearIncrease";
            break;
        }
    }
    Button{
        id:colorAlgorithm;
        text: "RandomRGB";
        anchors.left: stop.right;
        anchors.leftMargin: 4;
        anchors.bottom: start.bottom;

        onClicked: {
            //使用到了 Q_INVOKABLE宏 定义的两个函数
            var algorithm=(testObj.algorithm()+1)%5;
            changeAlgorithm(colorAlgorithm,algorithm);
            testObj.setAlgorithm(algorithm);
        }
    }

    Button{
        id:quit;
        text: "quit";
        anchors.left: colorAlgorithm.right;
        anchors.leftMargin: 4;
        anchors.bottom: start.bottom;
        //anchors.bottomMargin: 4;
        onClicked: {
            rootv.close();
        }
    }
    Component.onCompleted: {
        testObj.color=Qt.rgba(0,180,120,125);
        testObj.setAlgorithm(testObj.LinearIncrease);
        changeAlgorithm(colorAlgorithm,testObj.algorithm());
    }
//响应testObj的 两个signal
    Connections{
        target: testObj;
        onCurrenTime:{
            ttext.text=strTime;
            //Q_PROPERTY 宏定义函数  Q_PROPERTY(QColor timeColor READ timeColor)
            ttext.color=testObj.timeColor;
        }
    }
    Connections{
        target: testObj;
        onColorChange:{
            //Q_PROPERTY 宏定义函数 Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChange)
            colorRect.color=color;
        }
    }

   // title: qsTr("Hello World")
}
