# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
    FATAL: In-source builds are not allowed.
           You should create a separate directory for build files.
")
endif()

cmake_minimum_required(VERSION 3.5.1)
project(find-package VERSION 0.1.0 LANGUAGES CXX)

find_package(Boost 1.67.0 REQUIRED COMPONENTS filesystem)

# check if boost was found
# When use the `find_package()` function the variable 
# `${PACKAGE}_FOUND` will be set to Ture:found or false:not found
if(Boost_FOUND)
    message ("boost found")
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()

# Create a executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cxx)
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ${Boost_FILESYSTEM_LIBRARY}
)