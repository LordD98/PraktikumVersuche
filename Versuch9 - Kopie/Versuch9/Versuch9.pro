#-------------------------------------------------
#
# Project created by QtCreator 2017-07-09T00:24:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Versuch9
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    abstractmap.cpp \
    addstreetdialog.cpp \
    city.cpp \
    dijkstra.cpp \
    dijkstradialog.cpp \
    map.cpp \
    mapio.cpp \
    mapionrw.cpp \
    newcityui.cpp \
    street.cpp

HEADERS  += mainwindow.h \
    abstractmap.h \
    addstreetdialog.h \
    city.h \
    dijkstra.h \
    dijkstradialog.h \
    map.h \
    mapio.h \
    mapionrw.h \
    newcityui.h \
    street.h

FORMS    += mainwindow.ui \
    addstreetdialog.ui \
    dijkstradialog.ui \
    newcityui.ui
