#ifndef SINGLEALARM_H
#define SINGLEALARM_H

#include "alarm.h"

class SingleAlarm : public Alarm
{
public:
    SingleAlarm(int h, int m, int s, QObject *parent = 0);

    void timeChanged(QTime newTime);
    virtual QTime nextAlarm();

private:
    QTime alarmTime;
};

#endif // SINGLEALARM_H
