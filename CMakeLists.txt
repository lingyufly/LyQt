cmake_minimum_required(VERSION 3.1.0)

project(QtDemo)

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_CRT_SECURE_NO_DEPRECATE")  #屏蔽 sscanf等函数不安全的警告
endif()

add_subdirectory(TestQt)
add_subdirectory(lradar)
add_subdirectory(NetTools)
