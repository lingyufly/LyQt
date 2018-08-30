#-------------------------------------------------
#
# Project created by QtCreator 2017-10-13T10:13:54
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console

TARGET = NetTools
TEMPLATE = app


INCLUDEPATH+=include

SOURCES += source/main.cpp \
    source/scanip.cpp

HEADERS += include/scanip.h
		
