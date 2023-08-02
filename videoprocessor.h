#ifndef VIDEOPROCESSOR_H
#define VIDEOPROCESSOR_H

#include <QObject>
#include <QVideoFrame>
#include <QVideoSink>

class VideoProcessor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVideoSink* videoSink READ videoSink WRITE setVideoSink NOTIFY sinkChanged)
public:
    explicit VideoProcessor(QObject *parent = nullptr);
    QVideoSink* videoSink() { return m_sink; }
    void setVideoSink(QVideoSink* sink);

signals:
    void sinkChanged();

private slots:
    void processFrame(const QVideoFrame& frame);

private:
    QVideoSink* m_sink;
};

#endif // VIDEOPROCESSOR_H
