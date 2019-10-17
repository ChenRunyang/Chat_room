#-------------------------------------------------
#
# Project created by QtCreator 2018-12-05T14:19:40
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cli
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chat_ui.cpp \
    config.cpp

HEADERS  += mainwindow.h \
    chat_ui.h \
    config.h

FORMS    += mainwindow.ui \
    chat_ui.ui \
    config.ui
