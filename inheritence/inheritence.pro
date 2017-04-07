QT += core
QT -= gui

TARGET = inheritence
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

SOURCES += main.cpp \
    subbase.cpp

HEADERS += \
    base.h \
    singltonemanager.h \
    staticinstance.h \
    absbase.h \
    subbase.h

