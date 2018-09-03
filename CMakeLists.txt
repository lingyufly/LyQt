cmake_minimum_required(VERSION 3.1.0)

project(LyQt)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_CRT_SECURE_NO_DEPRECATE")  #屏蔽 sscanf等函数不安全的警告
add_subdirectory(TestQt)
add_subdirectory(LyRadar)
add_subdirectory(NetTools)