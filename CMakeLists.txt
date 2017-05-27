cmake_minimum_required(VERSION 3.8)
project(CDummy_library)

set(CMAKE_C_STANDARD 99)
option(BUILD_RUNNER "Build the runner" OFF)

# Set the varible to added to the config file
set(CDummy_VERSION_MAJOR 0 )
set(CDummy_VERSION_MINOR 1 )
set(CDummy_VERSION_PATCH 0 )
set(CDUMMY_VERSION ${CDummy_VERSION_MAJOR}.${CDummy_VERSION_MINOR}.${CDummy_VERSION_PATCH})

add_subdirectory(cdummy)

#######################################
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/cdummy/cdummyConfigVersion.cmake"
        VERSION ${CDUMMY_VERSION}
        COMPATIBILITY AnyNewerVersion
)
#######################################
# Create a Runner to test library
#######################################

if(BUILD_RUNNER)
    add_executable(runner runner.c)
    target_link_libraries(runner CDummy)
ENDIF()