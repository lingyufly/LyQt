cmake_minimum_required(VERSION 3.1.0)

project(LyRadar)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets CONFIG REQUIRED)

include_directories(include)
qt5_add_resources(QRC_FILES resource/LyRadar.qrc)
set(SRCS
	include/LyRadar.h  
	source/main.cpp
	source/LyRadar.cpp 
	${QRC_FILES})

add_executable(LyRadar WIN32 ${SRCS})
target_link_libraries(LyRadar Qt5::Widgets)

