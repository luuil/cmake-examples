# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
    FATAL: In-source builds are not allowed.
           You should create a separate directory for build files.
")
endif()

cmake_minimum_required(VERSION 3.5.1)
project(add-lib-obj VERSION 0.1.0 LANGUAGES CXX)

# Object library first, executable depends on it
include(hi-object-lib.cmake)
include(add-lib-obj-exe.cmake)