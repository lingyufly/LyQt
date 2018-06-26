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
		source/mouse.cpp \
		source/testQTreeWidget.cpp \
        source/test.cpp \
        source/testQStackedWidget.cpp

HEADERS += \
        include/mainwindow.h \
		include/login.h \
		include/userinfo.h \
		include/mouse.h \
		include/testQTreeWidget.h \
        include/test.h \
        include/testQStackedWidget.h
		

DISTFILES += \
    ini/settings.ini 
    
RC_ICONS+=resource/sevent.ico

RESOURCES+=resource/testqt.qrc
