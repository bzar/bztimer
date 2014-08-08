#ifndef ALARM_H
#define ALARM_H

#include <QObject>
#include <QTime>

class Alarm : public QObject
{
    Q_OBJECT
public:
    explicit Alarm(QObject *parent = 0);
    virtual ~Alarm();

    bool expired();
    virtual QTime nextAlarm() = 0;

protected:
    void setExpired(bool value);

signals:
    void alarm();

public slots:
    virtual void timeChanged(QTime newTime) = 0;
    virtual void reset();

private:
    bool done;
};

#endif // ALARM_H
