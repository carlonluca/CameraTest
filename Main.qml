import QtQuick
import QtQuick.Window
import QtMultimedia
import com.luke

Window {
    width: 640
    height: 480
    visible: true

    Component.onCompleted: camera.start()

    VideoOutput {
        id: videoOutput
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
    }

    MediaDevices {
        id: mediaDevices
    }

    CaptureSession {
        camera: camera
        videoOutput: videoOutput
    }

    Camera {
        id: camera
        cameraDevice: mediaDevices.defaultVideoInput
    }

    Timer {
        interval: 1000
        repeat: true
        onTriggered: {
            console.log("Video stream:", videoOutput.sourceRect)
            console.log("Video orientation:", videoOutput.orientation)
        }

        running: true
    }

    VideoProcessor {
        videoSink: videoOutput.videoSink
    }

    Rectangle {
        anchors.centerIn: parent
        color: "orange"
        width: label.width + 20
        height: label.height + 20
        Text {
            id: label
            anchors.centerIn: parent
            text: "Start/stop"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (camera.active)
                    camera.stop()
                else
                    camera.start()
            }
        }
    }
}
