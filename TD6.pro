#-------------------------------------------------
#
# Project created by QtCreator 2014-11-29T18:41:50
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11

QMAKE_LFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TD6
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp \
    gameboard.cpp \
    game.cpp \
    dummygame.cpp \
    ship.cpp \
    mindstormgame.cpp \
    lifecounter.cpp \
    pointscounter.cpp \
    ennemyspaceship.cpp \
    weapon.cpp \
    shot.cpp \
    mine.cpp

HEADERS  += mainwindow.h \
    controller.h \
    gameboard.h \
    game.h \
    dummygame.h \
    ship.h \
    mindstormgame.h \
    lifecounter.h \
    pointscounter.h \
    ennemyspaceship.h \
    weapon.h \
    shot.h \
    mine.h

FORMS    +=


