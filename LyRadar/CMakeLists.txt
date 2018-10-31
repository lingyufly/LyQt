cmake_minimum_required(VERSION 3.1.0)

project(LyRadar)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5LinguistTools)

include_directories(include)
qt5_add_resources(QRC_FILES resource/LyRadar.qrc)
set(SRCS
	include/LyRadar.h  
	source/main.cpp
	source/LyRadar.cpp 
	)
	
set(TS_FILES translation/LyRadar_de.ts translation/LyRadar_zh.ts)
qt5_create_translation(QM_FILES ${SRCS} ${TS_FILES})
add_custom_target(lupdate ALL DEPENDS ${TS_FILES})
add_custom_target(lrelease ALL DEPENDS ${QM_FILES})

add_executable(LyRadar WIN32 ${SRCS} ${QRC_FILES})
target_link_libraries(LyRadar Qt5::Widgets)

