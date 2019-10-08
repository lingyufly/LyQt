cmake_minimum_required(VERSION 3.1.0)

project(lradar)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5SerialPort REQUIRED)

include_directories(include)
qt5_add_resources(QRC_FILES resource/lradar.qrc)

set(SRCS
	include/radar.h  
	include/baseserver.h
	include/tcpserver.h
	include/zmqserver.h
	include/serialserver.h
	source/main.cpp
	source/radar.cpp 
	source/baseserver.cpp
	source/tcpserver.cpp
	source/zmqserver.cpp
	source/serialserver.cpp
	${QRC_FILES})
	
set(LIBS ${LIBS} Qt5::Widgets Qt5::Network Qt5::SerialPort)

add_executable(lradar ${SRCS})
target_link_libraries(lradar ${LIBS})

