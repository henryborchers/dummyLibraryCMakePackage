cmake_minimum_required(VERSION 3.8)
project(CDummy_library)

set(CMAKE_C_STANDARD 99)
set(CDummy_VERSION_MAJOR 0 )
set(CDummy_VERSION_MINOR 1 )
configure_file(
        "${PROJECT_SOURCE_DIR}/version.h.in"
        "${PROJECT_BINARY_DIR}/version.h"

)
set(SOURCE_FILES library.c library.h)
include_directories(${PROJECT_BINARY_DIR})
add_library(CDummy ${SOURCE_FILES})
add_executable(runner runner.c)
target_link_libraries(runner CDummy)