#include "alarmdialog.h"
#include "ui_alarmdialog.h"
#include <QSignalMapper>

AlarmDialog::AlarmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmDialog)
{
    ui->setupUi(this);
    QSignalMapper* signalMapper = new QSignalMapper(this);
    signalMapper->setMapping(ui->button0, QString("0"));
    signalMapper->setMapping(ui->button1, QString("1"));
    signalMapper->setMapping(ui->button2, QString("2"));
    signalMapper->setMapping(ui->button3, QString("3"));
    signalMapper->setMapping(ui->button4, QString("4"));
    signalMapper->setMapping(ui->button5, QString("5"));
    signalMapper->setMapping(ui->button6, QString("6"));
    signalMapper->setMapping(ui->button7, QString("7"));
    signalMapper->setMapping(ui->button8, QString("8"));
    signalMapper->setMapping(ui->button9, QString("9"));
    signalMapper->setMapping(ui->buttonPlus, QString("+"));
    signalMapper->setMapping(ui->buttonDash, QString("-"));
    signalMapper->setMapping(ui->buttonHour, QString("h"));
    signalMapper->setMapping(ui->buttonMinute, QString("m"));
    signalMapper->setMapping(ui->buttonSecond, QString("s"));
    signalMapper->setMapping(ui->buttonSpace, QString(" "));

    connect(ui->button0, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->button1, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->button2, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->button3, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->button4, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->button5, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->button6, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->button7, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->button8, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->button9, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->buttonPlus, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->buttonDash, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->buttonHour, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->buttonMinute, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->buttonSecond, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->buttonSpace, SIGNAL(clicked()), signalMapper, SLOT (map()));

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(addString(QString)));
    connect(ui->eraseButton, SIGNAL(clicked()), this, SLOT(erase()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clear()));

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void AlarmDialog::setAlarmString(QString newAlarmString)
{
    ui->alarmStringEdit->setText(newAlarmString);
}

QString AlarmDialog::getAlarmString()
{
    return ui->alarmStringEdit->text();
}

void AlarmDialog::addString(QString str)
{
    ui->alarmStringEdit->setText(ui->alarmStringEdit->text() + str);
}

void AlarmDialog::erase()
{
    QString newString = ui->alarmStringEdit->text();
    newString.chop(1);
    ui->alarmStringEdit->setText(newString);
}

void AlarmDialog::clear()
{
    ui->alarmStringEdit->setText("");
}
