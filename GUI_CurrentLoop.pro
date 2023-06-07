#-------------------------------------------------
#
# Project created by QtCreator 2022-07-05T13:58:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = "VD17 Service"
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    serialcommands.cpp \
    supportfunctions.cpp \
    mouseprocessing.cpp \
    plotprocessing.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui

win32 {
    RC_FILE = myicon.rc
}

CONFIG += serialport
