#include "omnialarm.h"
#include <QDebug>
OmniAlarm::OmniAlarm(QList<QTime> alarmTimes, bool repeatAlarms, QObject *parent) :
    Alarm(parent), times(alarmTimes), repeat(repeatAlarms), timeIndex(0), alarmTime(alarmTimes.at(0))
{
}

void OmniAlarm::timeChanged(QTime newTime)
{
    if(!expired() && newTime.msecsTo(alarmTime) <= 0)
    {
        timeIndex = (timeIndex + 1) % times.size();

        if(!timeIndex && !repeat)
        {
            setExpired(true);
        }
        else
        {
            alarmTime = alarmTime.addSecs(QTime(0,0).secsTo(times.at(timeIndex)));
        }

        emit alarm();
    }
}

QTime OmniAlarm::nextAlarm()
{
    if(!expired())
    {
        return alarmTime;
    }
    else
    {
        return QTime();
    }
}

void OmniAlarm::reset()
{
    setExpired(false);
    timeIndex = 0;
    alarmTime = times.at(0);
}
