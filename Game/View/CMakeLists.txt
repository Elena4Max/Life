cmake_minimum_required(VERSION 2.8)
project(life)
set(SOURCES view.cpp)
set(HEADERS view.h)
add_library(view ${SOURCES} ${HEADERS})
target_include_directories(view PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../World)
target_link_libraries(view world)

