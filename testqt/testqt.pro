#-------------------------------------------------
#
# Project created by QtCreator 2017-10-13T10:13:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testqt
TEMPLATE = app


INCLUDEPATH+=include

SOURCES += \
        source/main.cpp \
        source/mainwindow.cpp \
		source/login.cpp \
		source/userinfo.cpp \
		source/mouse.cpp

HEADERS += \
        include/mainwindow.h \
		include/login.h \
		include/userinfo.h \
		include/mouse.h

FORMS += \
        ui/mainwindow.ui \
		ui/login.ui \
		ui/userinfo.ui \
		ui/mouse.ui

DISTFILES += \
    ini/settings.ini 
