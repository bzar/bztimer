#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
//#include <phonon/mediaobject.h>
#include "stopwatch.h"
#include "alarm.h"
#include <QList>
#include <QMediaPlayer>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void timeChanged(QTime newTime);
    void alarm();
    void startPause();
    void reset();
    void setAlarms();
    void updateNextAlarm();

private slots:
    void showInputDialog();

protected:
    void changeEvent(QEvent *e);

private:
    void addAlarm(Alarm* alarm);
    void deleteAlarms();

    Ui::MainWindow *ui;
    StopWatch stopwatch;
    QMediaPlayer *alarmSound;

    QList<Alarm*> alarms;
};

#endif // MAINWINDOW_H
