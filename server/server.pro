#-------------------------------------------------
#
# Project created by QtCreator 2018-12-02T11:34:52
#
#-------------------------------------------------

QT       += core gui network
QT += sql

LIBS += -LH:\C++\chat_room\server -lsqlite3

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rlmessage.cpp

HEADERS  += mainwindow.h \
    rlmessage.h

FORMS    += mainwindow.ui
