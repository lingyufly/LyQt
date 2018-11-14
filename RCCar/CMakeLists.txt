cmake_minimum_required(VERSION 3.1.0)

project(RCCar)
if (ANDROID)
	set(ENV{QTDIR} "D:\\Applications\\Qt5.10.1\\5.10.1\\android_armv7")
	set(ENV{PATH} "D:\\Applications\\Qt5.10.1\\5.10.1\\android_armv7\\bin" "D:\\Applications\\Qt5.10.1\\5.10.1\\android_armv7\\lib" $ENV{PATH})
	set(ENV{ANDROID_NDK} "D:\\Applications\\Android\\android-ndk-r10e")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)

include_directories(include)
qt5_add_resources(QRC_FILES resource/rccar.qrc)

add_definitions("-std=c++11")
set(SRCS
	include/rccar.h  
	include/config.h
	source/main.cpp
	source/rccar.cpp 
	source/config.cpp
	${QRC_FILES})
	
set(LIBS ${LIBS} Qt5::Widgets Qt5::Network)

if (ANDROID)
	get_property(cxx_features GLOBAL PROPERTY CMAKE_CXX_KNOWN_FEATURES)
	set(CMAKE_CXX_COMPILE_FEATURES ${cxx_features})
	set(GLOBAL PROPERTY CMAKE_C_COMPILE_FEATURES ${cxx_features})
	set(QT_ANDROID_SDK_ROOT "D:/Applications/Android/android-sdk")
	include(../../qt-android-cmake/AddQtAndroidApk.cmake)
	add_library(RCCar SHARED ${SRCS})
	add_qt_android_apk(my_app_apk RCCar
		BUILDTOOLS_REVISION "28.0.0"
		INSTALL)
else()
	add_executable(RCCar ${SRCS})
endif()
target_link_libraries(RCCar ${LIBS})

#cmake -G"MinGW Makefiles" -DCMAKE_TOOLCHAIN_FILE="E:\\code\\Qt\\qt-android-cmake\\toolchain\\android.toolchain.cmake" -DCMAKE_MAKE_PROGRAM="%ANDROID_NDK%/prebuilt/windows/bin/make.exe" ..