#-------------------------------------------------
#
# Project created by QtCreator 2013-05-04T13:15:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main
TEMPLATE = app


SOURCES += main.cpp\
    iqcapplication.cpp \
    iqcmainwindow.cpp \
    ../lib/qslog/QsLogDest.cpp \
    ../lib/qslog/QsLog.cpp \
    ../lib/qslog/QsDebugOutput.cpp

HEADERS  += \
    iqcapplication.h \
    iqcmainwindow.h \
    ../lib/qslog/QsLogDest.h \
    ../lib/qslog/QsLog.h \
    ../lib/qslog/QsDebugOutput.h

FORMS +=

RESOURCES += \
    iqc.qrc
