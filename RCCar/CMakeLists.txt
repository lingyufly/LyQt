cmake_minimum_required(VERSION 3.1.0)

project(RCCar)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)

include_directories(include)
qt5_add_resources(QRC_FILES resource/rccar.qrc)
set(SRCS
	include/rccar.h  
	source/main.cpp
	source/rccar.cpp 
	${QRC_FILES})
	
set(LIBS ${LIBS} Qt5::Widgets Qt5::MultimediaWidgets)

add_executable(RCCar WIN32 ${SRCS})
target_link_libraries(RCCar ${LIBS})

