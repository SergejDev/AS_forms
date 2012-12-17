#-------------------------------------------------
#
# Project created by QtCreator 2012-10-18T19:14:11
#
#-------------------------------------------------

QT       += core gui sql


TARGET = AS_forms
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    usernamedialog.cpp \
    tabledialog.cpp \
    ship.cpp \
    ships.cpp \
    bullet.cpp \
    bullets.cpp \
    gamecontroller.cpp \
    gun.cpp

HEADERS  += gamewindow.h \
    usernamedialog.h \
    tabledialog.h \
    ship.h \
    ships.h \
    bullet.h \
    bullets.h \
    gamecontroller.h \
    gun.h

FORMS    += \
    usernamedialog.ui \
    tabledialog.ui

RESOURCES += \
    resourses.qrc
