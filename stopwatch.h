#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTime>
#include <QTimer>

class StopWatch : public QObject
{
    Q_OBJECT
public:
    explicit StopWatch(QObject *parent = 0);

signals:
    void timeChanged(QTime newTime);


public slots:
    void start();
    void pause();
    void reset();
    void update();

    bool isRunning();

private:
    bool running;
    QTime time;
    QTimer* timer;

    static int const UPDATE_INTERVAL = 500;
};

#endif // STOPWATCH_H
