#-------------------------------------------------
#
# Project created by QtCreator 2012-10-18T19:14:11
#
#-------------------------------------------------

QT       += core gui\
        sql

TARGET = AS_forms
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    #mybutton.cpp
    usernamedialog.cpp \
    tabledialog.cpp

HEADERS  += gamewindow.h \
    #mybutton.h
    usernamedialog.h \
    tabledialog.h

FORMS    += \
    usernamedialog.ui \
    tabledialog.ui

RESOURCES += \
    resourses.qrc
