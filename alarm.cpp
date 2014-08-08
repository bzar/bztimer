#include "alarm.h"

Alarm::Alarm(QObject *parent) :
    QObject(parent), done(false)
{
}

Alarm::~Alarm()
{

}

bool Alarm::expired()
{
    return done;
}

void Alarm::setExpired(bool value)
{
    done = value;
}

void Alarm::reset()
{
    done = false;
}
