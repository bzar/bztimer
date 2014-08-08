#ifndef ALARMDIALOG_H
#define ALARMDIALOG_H

#include <QtWidgets/QDialog>

namespace Ui {
    class AlarmDialog;
}

class AlarmDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AlarmDialog(QWidget *parent = 0);
    void setAlarmString(QString newAlarmString);
    QString getAlarmString();

signals:

public slots:

private slots:
    void addString(QString str);
    void erase();
    void clear();
private:
    Ui::AlarmDialog *ui;
};

#endif // ALARMDIALOG_H
