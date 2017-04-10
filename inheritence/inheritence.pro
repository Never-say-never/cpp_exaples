QT += core
QT -= gui

TARGET = inheritence
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

SOURCES += main.cpp \
    subbase.cpp \
    pattern/observer/observermanager.cpp \
    pattern/observer/observable.cpp

HEADERS += \
    base.h \
    singltonemanager.h \
    staticinstance.h \
    absbase.h \
    subbase.h \
    rwo.h \
    observer.h \
    pattern/observer/observer.h \
    pattern/observer/observable.h \
    pattern/observer/observerman.h \
    pattern/observer/observermanager.h
