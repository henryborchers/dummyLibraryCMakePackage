set(SOURCE_FILES CDummy.c)
set(PUBLIC_HEADERS CDummy.h)
# Generate version.h based on the CDversion.h.in template
#######################################
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/CDversion.h.in"    # Template
        "${CMAKE_CURRENT_BINARY_DIR}/CDversion.h"       # New file generated
)

#######################################
#configure_file(${PROJECT_SOURCE_DIR}/cmake/cdummyConfig.cmake
#        "${CMAKE_CURRENT_BINARY_DIR}/cdummyConfig.cmake"
#        COPYONLY)
#######################################
include_directories(${PROJECT_BINARY_DIR}/cdummy)
add_library(CDummy ${SOURCE_FILES} ${PUBLIC_HEADERS})
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
        CDummy.h
        "${CMAKE_CURRENT_BINARY_DIR}/CDummy_export.h"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        COMPONENT Devel
        )

export(TARGETS CDummy FILE cdummyConfig.cmake)

message(WARNING "CMAKE_INSTALL_INCLUDEDIR = ${CMAKE_INSTALL_INCLUDEDIR}")
#######################################
#install(FILES CDummy.h DESTINATION include/cdummy)
#install(TARGETS CDummy EXPORT cdummy-targets DESTINATION lib/cdummy)
#install(EXPORT cdummy-targets DESTINATION lib/cdummy)
#install(FILES
#        "${CMAKE_CURRENT_BINARY_DIR}/cdummyConfig.cmake"
#        "${CMAKE_CURRENT_BINARY_DIR}/cdummyConfigVersion.cmake"
#        DESTINATION lib/cmake/cdummy)
