#-------------------------------------------------
#
# Project created by QtCreator 2015-10-05T22:27:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrafficSimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vehicle.cpp \
    policecar.cpp \
    regularcar.cpp \
    subject.cpp \
    dispatcher.cpp \
    contextobject.cpp \
    concreteinterceptor.cpp \
    loggingapp.cpp

HEADERS  += mainwindow.h \
    vehicle.h \
    policecar.h \
    regularcar.h \
    subject.h \
    dispatcher.h \
    contextobject.h \
    concreteinterceptor.h \
    loggingapp.h

FORMS    += mainwindow.ui

QMAKE_LFLAGS += /INCREMENTAL:NO
