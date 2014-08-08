#-------------------------------------------------
#
# Project created by QtCreator 2010-06-24T10:28:30
#
#-------------------------------------------------

QT       += core gui widgets multimedia

TARGET = BZTimer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    stopwatch.cpp \
    alarm.cpp \
    singlealarm.cpp \
    omnialarm.cpp \
    alarmdialog.cpp

HEADERS  += mainwindow.h \
    stopwatch.h \
    alarm.h \
    singlealarm.h \
    omnialarm.h \
    alarmdialog.h

FORMS    += mainwindow.ui \
    alarmdialog.ui


RESOURCES += \
    resources.qrc
