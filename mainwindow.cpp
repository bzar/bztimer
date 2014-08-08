#include "mainwindow.h"

#include "omnialarm.h"
#include "alarmdialog.h"

#include "ui_mainwindow.h"
#include <QMediaPlaylist>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stopwatch(),
    alarms()
{

    ui->setupUi(this);
    ui->alarmStringInput->setFocus(Qt::OtherFocusReason);
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startPause()));
    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(reset()));
    connect(ui->alarmStringSetButton, SIGNAL(clicked()), this, SLOT(setAlarms()));
    connect(ui->alarmStringInputButton, SIGNAL(clicked()), this, SLOT(showInputDialog()));
    connect(&stopwatch, SIGNAL(timeChanged(QTime)), this, SLOT(timeChanged(QTime)));
    alarmSound = new QMediaPlayer(this);
    alarmSound->setPlaylist(new QMediaPlaylist);
    alarmSound->playlist()->addMedia(QMediaContent(QUrl("qrc:/alarm.wav")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::timeChanged(QTime newTime)
{
    ui->timeDisplay->setText(newTime.toString("HH:mm:ss"));
}

void MainWindow::alarm()
{
    alarmSound->stop();
    alarmSound->playlist()->previous();
    alarmSound->play();
    updateNextAlarm();
}

void MainWindow::startPause()
{
    if(stopwatch.isRunning())
    {
        stopwatch.pause();
    }
    else
    {
        stopwatch.start();
    }
}

void MainWindow::reset()
{
    stopwatch.reset();
    foreach(Alarm* alarm, alarms)
    {
        alarm->reset();
    }
    updateNextAlarm();
}
void MainWindow::addAlarm(Alarm* alarm)
{
    connect(alarm, SIGNAL(alarm()), this, SLOT(alarm()));
    connect(&stopwatch, SIGNAL(timeChanged(QTime)), alarm, SLOT(timeChanged(QTime)));
    alarms.append(alarm);
}

void MainWindow::deleteAlarms()
{
    foreach(Alarm* alarm, alarms)
    {
        delete alarm;
    }
    alarms.clear();
}

void MainWindow::setAlarms()
{
    deleteAlarms();
    QString alarmString = ui->alarmStringInput->text();
    QRegExp expressionSeparator("\\s+", Qt::CaseSensitive, QRegExp::RegExp2);
    QRegExp atomSeparator("-", Qt::CaseSensitive, QRegExp::RegExp2);
    QRegExp atomParser("(?:(\\d+)h)?(?:(\\d+)m)?(?:(\\d+)s)?", Qt::CaseSensitive, QRegExp::RegExp2);

    foreach(QString alarmStringExpression, alarmString.split(expressionSeparator))
    {
        bool repeat = alarmStringExpression.endsWith('+');
        QStringList alarmStringAtoms = alarmStringExpression.split(atomSeparator);
        QList<QTime> timeAtoms;

        foreach(QString alarmStringAtom, alarmStringAtoms)
        {
            if(atomParser.indexIn(alarmStringAtom) == -1)
            {
                qDebug("Could not match alarm string atom");
                continue;
            }
            QStringList atomParts = atomParser.capturedTexts();
            quint32 h = atomParts.at(1).toInt();
            quint32 m = atomParts.at(2).toInt();
            quint32 s = atomParts.at(3).toInt();
            timeAtoms.append(QTime(h, m, s));
        }

        Alarm* a = new OmniAlarm(timeAtoms, repeat, this);
        addAlarm(a);
    }

    updateNextAlarm();
}

void MainWindow::updateNextAlarm()
{
    QTime nextAlarm;
    foreach(Alarm* alarm, alarms)
    {
        if(!alarm->expired())
        {
            QTime alarmTime = alarm->nextAlarm();
            if(nextAlarm.isNull() || nextAlarm > alarmTime)
            {
                nextAlarm = alarmTime;
            }
        }
    }

    if(nextAlarm.isNull())
    {
        ui->nextAlarmDisplay->setText("Never");
    }
    else
    {
         ui->nextAlarmDisplay->setText(nextAlarm.toString("HH:mm:ss"));
    }
}

void MainWindow::showInputDialog()
{
    AlarmDialog dialog;
    dialog.setAlarmString(ui->alarmStringInput->text());
    if(dialog.exec() == QDialog::Accepted)
    {
        ui->alarmStringInput->setText(dialog.getAlarmString());
    }
}
