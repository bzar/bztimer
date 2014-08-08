#include "singlealarm.h"

SingleAlarm::SingleAlarm(int h, int m, int s, QObject *parent)
    : Alarm(parent), alarmTime(h, m, s)
{
}

void SingleAlarm::timeChanged(QTime newTime)
{
    if(!expired() && newTime.msecsTo(alarmTime) <= 0)
    {
        setExpired(true);
        emit alarm();
    }
}

QTime SingleAlarm::nextAlarm()
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
