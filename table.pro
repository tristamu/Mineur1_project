#-------------------------------------------------
#
# Project created by QtCreator 2014-10-22T09:05:52
#
#-------------------------------------------------

QT       += core gui
QT       += sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = table
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    persistentAttribute.cpp \
    persistentObject.cpp \
    database.cpp \
    bookobject.cpp \
    filepathdialog.cpp

HEADERS  += mainwindow.h \
    persistentAttribute.h \
    persistentObject.h \
    database.h \
    bookobject.h \
    filepathdialog.h

FORMS    += mainwindow.ui \
    filepathdialog.ui
