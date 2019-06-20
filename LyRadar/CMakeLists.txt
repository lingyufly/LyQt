cmake_minimum_required(VERSION 3.1.0)

project(LyRadar)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)

include_directories(include)
qt5_add_resources(QRC_FILES resource/lyradar.qrc)

set(SRCS
	include/LyRadar.h  
	source/main.cpp
	source/LyRadar.cpp 
	${QRC_FILES})
	
set(LIBS ${LIBS} Qt5::Widgets)

add_executable(LyRadar ${SRCS})
target_link_libraries(LyRadar ${LIBS})

