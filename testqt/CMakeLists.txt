cmake_minimum_required(VERSION 3.1.0)

project(testqt)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

include_directories(include)
qt5_add_resources(QRC_FILES resource/testqt.qrc)
# Populate a CMake variable with the sources
set(helloworld_SRCS
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

# Tell CMake to create the helloworld executable
add_executable(testqt WIN32 ${helloworld_SRCS})
# Use the Widgets module from Qt 5
target_link_libraries(testqt Qt5::Widgets)

get_target_property(QtCore_location Qt5::Core LOCATION)
message(${QtCore_location})