#-------------------------------------------------
#
# Project created by QtCreator 2015-10-17T21:39:00
#
#-------------------------------------------------

QT       += core gui network

CONFIG += qaxcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dlg.cpp

HEADERS  += mainwindow.h \
    dlg.h

FORMS    += mainwindow.ui \
    dlg.ui
