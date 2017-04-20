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
    pattern/observer/observable.cpp \
    pattern/factory/factory.cpp \
    pattern/factory/factorymanager.cpp

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
    pattern/observer/observermanager.h \
    pattern/factory/factory.h \
    pattern/factory/data_structures.h \
    pattern/factory/builder.h \
    pattern/factory/factory_shell.h \
    pattern/factory/factory_engine.h \
    pattern/factory/demo_manager.h \
    pattern/factory/spaceship.h \
    pattern/factory/ispaceship.h \
    space_objects/ships/ship_shell.h \
    space_objects/ships/ship_enging.h \
    pattern/factory/builder_battleship.h \
    pattern/factory/builder_transport.h \
    space_objects/ships/ishipenging.h \
    space_objects/ships/ishipshell.h \
    space_objects/ships/iunit.h
