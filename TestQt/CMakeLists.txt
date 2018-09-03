cmake_minimum_required(VERSION 3.1.0)

project(TestQt)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)

include_directories(include)
qt5_add_resources(QRC_FILES resource/testqt.qrc)
set(SRCS
	include/login.h  
	include/mainwindow.h 
	include/mouse.h 
	include/test.h 
	include/testQStackedWidget.h 
	include/testQTreeWidget.h 
	include/userinfo.h
	include/fileio.h 
	include/wizard.h
	source/main.cpp
	source/login.cpp 
	source/mainwindow.cpp
	source/mouse.cpp 
	source/test.cpp 
	source/testQStackedWidget.cpp
	source/testQTreeWidget.cpp 
	source/userinfo.cpp 
	source/fileio.cpp 
	source/wizard.cpp 
	${QRC_FILES})

add_executable(TestQt WIN32 ${SRCS})
target_link_libraries(TestQt Qt5::Widgets)

