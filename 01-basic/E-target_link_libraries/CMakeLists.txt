# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
    FATAL: In-source builds are not allowed.
           You should create a separate directory for build files.
")
endif()

cmake_minimum_required(VERSION 3.5.1)
project(tgt-link-lib VERSION 0.1.0 LANGUAGES CXX)

# Create a library to link
# ${PROJECT_SOURCE_DIR}: ./src
add_library(hi_lib ${PROJECT_SOURCE_DIR}/src/hi.cxx)

# a dependency should be specified in a use of target_link_libraries() with the
# PRIVATE keyword if it is used by only the implementation of a library, 
# and not in the header files. If a dependency is additionally used in the header
# files of a library (e.g. for class inheritance), then it should be specified as
# a PUBLIC dependency. A dependency which is not used by the implementation of a library,
# but only by its headers should be specified as an INTERFACE dependency.
target_compile_definitions(hi_lib INTERFACE USING_HI_LIB)
target_include_directories(hi_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Create a executable which link to `hi_lib`
# ${PROJECT_NAME}:tgt-link-lib is compiled with -DUSING_HI_LIB
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cxx)

# ${PROJECT_NAME}:tgt-link-lib is also have the `${PROJECT_SOURCE_DIR}/include` scope,
# because PUBLIC is used in `hi_lib`'s target_include_directories
target_link_libraries(${PROJECT_NAME} hi_lib)