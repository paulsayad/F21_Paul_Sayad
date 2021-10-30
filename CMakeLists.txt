cmake_minimum_required(VERSION 3.18)

project(my_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DSAYADGE_WINDOWS)
elseif(APPLE)
	add_definitions(-DSAYADGE_MAC)
elseif(UNIX)
	add_definitions(-DSAYADGE_LINUX)
endif()

add_subdirectory(MyGame)
add_subdirectory(SayadGE)
add_subdirectory(glfw)