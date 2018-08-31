TARGET = LyRadar
TEMPLATE = app
QT += core gui widgets
CONFIG += console

INCLUDEPATH+= \
	include

SOURCES += \
	source/main.cpp \
	source/LyRadar.cpp 

HEADERS += \
	include/LyRadar.h 
		
