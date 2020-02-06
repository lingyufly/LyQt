cmake_minimum_required(VERSION 3.1.0)

project(mthread)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)

set(SRCS
	main.h
	main.cpp)
	
set(LIBS ${LIBS} Qt5::Widgets)

add_executable(mthread ${SRCS})
target_link_libraries(mthread ${LIBS})

