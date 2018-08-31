TARGET = NetTools
TEMPLATE = app
QT += core gui network widgets
CONFIG += console

INCLUDEPATH += \
	include

SOURCES += \
	source/main.cpp \
    source/scanip.cpp

HEADERS += \
	include/scanip.h
		
