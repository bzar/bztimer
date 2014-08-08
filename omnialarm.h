#ifndef OMNIALARM_H
#define OMNIALARM_H

#include "alarm.h"

#include <QTime>
#include <QList>

class OmniAlarm : public Alarm
{
    Q_OBJECT
public:
    explicit OmniAlarm(QList<QTime> alarmTimes, bool repeatAlarms, QObject *parent = 0);
    void timeChanged(QTime newTime);
    virtual QTime nextAlarm();

signals:

public slots:
    void reset();

private:
    QList<QTime> times;
    bool repeat;
    quint16 timeIndex;
    QTime alarmTime;
};

#endif // OMNIALARM_H
