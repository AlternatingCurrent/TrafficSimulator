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
    loggingapp.cpp \
    overtakeaggressive.cpp \
    overtakemediumaggressiveness.cpp \
    overtakelowaggressiveness.cpp \
    increasespeedaggressive.cpp \
    increasespeedmedium.cpp \
    increasespeedlow.cpp \
    decreasespeed.cpp \
    trafficlights.cpp \
    pedestrian.cpp \
    simulationframe.cpp \
    athlete.cpp \
    pedestrianmaker.cpp

HEADERS  += mainwindow.h \
    vehicle.h \
    policecar.h \
    regularcar.h \
    subject.h \
    dispatcher.h \
    contextobject.h \
    concreteinterceptor.h \
    loggingapp.h \
    vehiclestrategy.h \
    trafficlights.h \
    pedestrian.h \
    simulationframe.h \
    athlete.h \
    pedestrianmaker.h

FORMS    += mainwindow.ui


DISTFILES +=

RESOURCES += \
    images.qrc
CONFIG += c++11
