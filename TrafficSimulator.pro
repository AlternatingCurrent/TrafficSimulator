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
    trafficlights.cpp \
    pedestrian.cpp \
    simulationframe.cpp \
    athlete.cpp \
    pedestrianmaker.cpp \
    vehiclefactory.cpp \
    carwithtrailer.cpp \
    randomgenerator.cpp \
    strategycontext.cpp \
    increasespeedaggressive.cpp \
    increasespeedmedium.cpp \
    increasespeedlow.cpp \
    overtakelow.cpp \
    overtakemedium.cpp \
    overtakehigh.cpp \
    decreasespeed.cpp \
    mainwindowstates.cpp

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
    pedestrianmaker.h \
    vehiclefactory.h \
    carwithtrailer.h \
    randomgenerator.h \
    strategycontext.h \
    increasespeedaggressive.h \
    increasespeedmedium.h \
    increasespeedlow.h \
    overtakelow.h \
    overtakemedium.h \
    overtakehigh.h \
    decreasespeed.h \
    mainwindowstates.h

FORMS    += mainwindow.ui


DISTFILES +=

RESOURCES += \
    images.qrc
CONFIG += c++11
