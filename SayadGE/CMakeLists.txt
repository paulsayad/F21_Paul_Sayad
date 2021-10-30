set(SOURCE_FILES SayadGEApp.cpp)

set(HEADER_FILES SayadGE.h SayadGEApp.h SayadGEUtils.h)

add_library(sayadge_lib  SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(sayadge_lib PRIVATE pch.h)

add_definitions(-DSAYADGE_LIB)

target_link_libraries(sayadge_lib glfw)

include_directories(../glfw/include)