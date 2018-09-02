TARGET = TestQt
TEMPLATE = app
QT += core gui widgets
CONFIG += console

INCLUDEPATH += \
	include

SOURCES += \
	source/main.cpp \
	source/mainwindow.cpp \
	source/login.cpp \
	source/userinfo.cpp \
	source/mouse.cpp \
	source/testqtreewidget.cpp \
	source/test.cpp \
	source/testqstackedwidget.cpp \
	source/wizard.cpp \
	source/fileio.cpp 

HEADERS += \
	include/mainwindow.h \
	include/login.h \
	include/userinfo.h \
	include/mouse.h \
	include/testqtreewidget.h \
	include/test.h \
	include/testqstackedwidget.h \
	include/wizard.h \
	include/fileio.h 
		

DISTFILES += \
    ini/settings.ini 
    
RC_ICONS += \
	resource/testqt.ico

RESOURCES += \
	resource/testqt.qrc
