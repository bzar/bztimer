#include "stopwatch.h"

StopWatch::StopWatch(QObject *parent) :
    QObject(parent), time(0,0,0,0), timer(0), running(false)
{
    reset();
}

void StopWatch::start()
{
    timer->start();
    running = true;
}

void StopWatch::pause()
{
    if(timer) delete timer;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->setInterval(UPDATE_INTERVAL);
    running = false;
}

void StopWatch::reset()
{
    if(timer) delete timer;
    timer = new QTimer(this);
    time = QTime(0,0,0,0);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->setInterval(UPDATE_INTERVAL);
    running = false;
    emit timeChanged(time);
}

void StopWatch::update()
{
    time = time.addMSecs(UPDATE_INTERVAL);
    emit timeChanged(time);
}

bool StopWatch::isRunning()
{
    return running;
}
