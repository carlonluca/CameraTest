#include <QDebug>

#include "videoprocessor.h"

VideoProcessor::VideoProcessor(QObject *parent)
    : QObject{parent}
    , m_sink(nullptr) {}

void VideoProcessor::setVideoSink(QVideoSink* sink)
{
    if (sink == m_sink)
        return;
    if (m_sink)
        disconnect(m_sink, &QVideoSink::videoFrameChanged,
                   this, &VideoProcessor::processFrame);
    m_sink = sink;
    connect(m_sink, &QVideoSink::videoFrameChanged,
            this, &VideoProcessor::processFrame, Qt::QueuedConnection);
}

void VideoProcessor::processFrame(const QVideoFrame &frame)
{
    qDebug() << "Frame" << frame.size() << frame.rotationAngle();

    QImage image = frame.toImage();
    if (image.isNull())
        qWarning() << "Could not get image from video frame";
    else
        qInfo() << "Got image from video frame of size:" << image.size();
}
