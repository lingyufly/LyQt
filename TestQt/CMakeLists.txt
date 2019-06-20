cmake_minimum_required(VERSION 3.1.0)

project(TestQt)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)

include_directories(include)
qt5_add_resources(QRC_FILES resource/testqt.qrc)
set(SRCS
	include/logindlg.h  
	include/mainwindow.h 
	include/mousewgt.h 
	include/testwgt.h 
	include/dockwgt.h 
	include/treewidgetwgt.h 
	include/userinfowgt.h
	include/fileiowgt.h 
	include/testwizard.h
	source/main.cpp
	source/logindlg.cpp 
	source/mainwindow.cpp
	source/mousewgt.cpp 
	source/testwgt.cpp 
	source/dockwgt.cpp
	source/treewidgetwgt.cpp 
	source/userinfowgt.cpp 
	source/fileiowgt.cpp 
	source/testwizard.cpp 
	${QRC_FILES})

set(LIBS ${LIBS} Qt5::Widgets)

add_executable(TestQt ${SRCS})
target_link_libraries(TestQt ${LIBS})

