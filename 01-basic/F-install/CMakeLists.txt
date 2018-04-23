# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
    FATAL: In-source builds are not allowed.
           You should create a separate directory for build files.
")
endif()

cmake_minimum_required(VERSION 3.5.1)
project(tgt-install VERSION 0.1.0 LANGUAGES CXX)

# Setting default CMAKE_INSTALL_PREFIX path to ${CMAKE_BINARY_DIR}/install
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install"
    CACHE STRING "Path for make install" FORCE)

# Create a library to link
# ${PROJECT_SOURCE_DIR}: ./src
add_library(hi_lib SHARED ${PROJECT_SOURCE_DIR}/src/hi.cxx)
target_include_directories(hi_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(hi_lib PRIVATE -DDLL_EXPORTS)

# Create a executable which link to `hi_lib`
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cxx)
target_link_libraries(${PROJECT_NAME} hi_lib)
add_dependencies(${PROJECT_NAME} hi_lib)


############################################################
# Install
############################################################

# Library
# Note: may not work on windows
# shared lib on windows should use this to install
# because it contains `.dll` and `.lib` file at same time
if(WIN32) # windows
    install (TARGETS hi_lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)
else(WIN32) # others
    install (TARGETS hi_lib LIBRARY DESTINATION lib)
endif(WIN32)


# Binaries
install (TARGETS ${PROJECT_NAME} DESTINATION bin)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)

# Config
install (FILES cmake-examples.conf DESTINATION etc)