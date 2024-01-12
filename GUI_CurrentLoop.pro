#-------------------------------------------------
#
# Project created by QtCreator 2022-07-05T13:58:40
#
#-------------------------------------------------

QT       += core gui serialport widgets printsupport

TARGET = "VD17 Service"
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    serialcommands.cpp \
    supportfunctions.cpp \
    mouseprocessing.cpp \
    plotprocessing.cpp \
    appsettings.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    appsettings.h \
    support.h

FORMS    += mainwindow.ui \
    appsettings.ui

win32 {
    RC_FILE = myicon.rc
}

