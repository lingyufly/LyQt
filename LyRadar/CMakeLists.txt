cmake_minimum_required(VERSION 3.1.0)

project(LyRadar)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5LinguistTools)

include_directories(include)
qt5_add_resources(QRC_FILES resource/LyRadar.qrc)
#${QRC_FILES}
set(SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/include/LyRadar.h  
	${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/source/LyRadar.cpp 
	)
	
set(TS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/muckturnier_de.ts)
qt5_create_translation(QM_FILES ${SRCS} ${TS_FILES} OPTIONS -pluralonly -locations none)
add_custom_target(Localization ALL DEPENDS ${QM_FILES})

add_executable(LyRadar WIN32 ${SRCS})
target_link_libraries(LyRadar Qt5::Widgets)

