cmake_minimum_required(VERSION 3.7)
project(CDummy_library)
set(CMAKE_C_STANDARD 99)
include(GNUInstallDirs)
option(BUILD_RUNNER "Build the runner" OFF)

# Set the varible to added to the config file
set(CDummy_VERSION_MAJOR 0 )
set(CDummy_VERSION_MINOR 1 )
set(CDummy_VERSION_PATCH 0 )
set(CDummy_VERSION ${CDummy_VERSION_MAJOR}.${CDummy_VERSION_MINOR}.${CDummy_VERSION_PATCH})
include(GenerateExportHeader)
#######################################
set(SOURCE_FILES cdummy/CDummy.c)
set(PUBLIC_HEADERS cdummy/CDummy.h)
#add_subdirectory(cdummy)
configure_file(
        "cdummy/CDversion.h.in"    # Template
        "cdummy/CDversion.h"       # New file generated
)
include_directories(${PROJECT_BINARY_DIR})
add_library(CDummy SHARED ${SOURCE_FILES} ${PUBLIC_HEADERS})
generate_export_header(CDummy)
set_property(TARGET CDummy PROPERTY VERSION ${CDummy_VERSION})
set_property(TARGET CDummy PROPERTY INTERFACE_CDummy_VERSION_MAJOR ${CDummy_VERSION})
set_property(TARGET CDummy APPEND PROPERTY
        COMPATIABLE_INTERFACE_STRING CDummy_VERSION_MAJOR
        )
install(
        TARGETS CDummy EXPORT CDummyTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(FILES
        cdummy/CDummy.h
        "${CMAKE_CURRENT_BINARY_DIR}/cdummy_export.h"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        COMPONENT Devel
        )
#######################################

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/cdummy/cdummyConfigVersion.cmake"
        VERSION ${CDummy_VERSION}
        COMPATIBILITY AnyNewerVersion
)
export(EXPORT CDummyTargets
        FILE "${CMAKE_CURRENT_BINARY_DIR}/cdummy/cdummyTargets.cmake"
        NAMESPACE CDummy::
        )

set(ConfigPackageLocation ${CMAKE_INSTALL_LIBDIR}/cmake/cdummy)

configure_package_config_file(
        cmake/cdummyConfig.cmake
        "${CMAKE_CURRENT_BINARY_DIR}/cdummy/cdummyConfig.cmake"
        INSTALL_DESTINATION "${ConfigPackageLocation}"
        PATH_VARS CMAKE_INSTALL_INCLUDEDIR

)

install(EXPORT CDummyTargets
        FILE CDummyTargets.cmake
        NAMESPACE CDummy::
        DESTINATION ${ConfigPackageLocation}
        )
install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/cdummy/cdummyConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/cdummy/cdummyConfigVersion.cmake"
        DESTINATION ${ConfigPackageLocation}
        COMPONENT Devel
        )
#######################################
# Create a Runner to test library
#######################################

if(BUILD_RUNNER)
    include_directories(cdummy/include)
    add_executable(runner runner.c)
    target_link_libraries(runner CDummy)
ENDIF()