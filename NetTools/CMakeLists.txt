cmake_minimum_required(VERSION 3.1.0)

project(NetTools)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
set(LIBS ${LIBS} ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES})

include_directories(include)
qt5_add_resources(QRC_FILES resource/nettools.qrc)
set(SRCS
	include/scanip.h  
	source/main.cpp
	source/scanip.cpp 
	${QRC_FILES})

add_executable(NetTools WIN32 ${SRCS})
target_link_libraries(NetTools ${LIBS})

