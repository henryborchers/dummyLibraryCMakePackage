set(SOURCE_FILES CDummy.c CDummy.h)

# Generate version.h based on the version.h.in template
#######################################
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/version.h.in"    # Template
        "${CMAKE_CURRENT_BINARY_DIR}/version.h"       # New file generated
)

#######################################
configure_file(${PROJECT_SOURCE_DIR}/cmake/cdummyConfig.cmake
        "${CMAKE_CURRENT_BINARY_DIR}/cdummyConfig.cmake"
        COPYONLY)
include_directories(${PROJECT_BINARY_DIR}/cdummy)
add_library(CDummy ${SOURCE_FILES})
install(FILES CDummy.h DESTINATION include/cdummy)
install(TARGETS CDummy EXPORT cdummy-targets DESTINATION lib/cdummy)
install(EXPORT cdummy-targets DESTINATION lib/cdummy)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cdummyConfigVersion.cmake DESTINATION lib/cmake/cdummy)