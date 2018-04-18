# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
    FATAL: In-source builds are not allowed.
           You should create a separate directory for build files.
")
endif()

cmake_minimum_required(VERSION 3.5.1)
project(hello-world VERSION 0.1.0 LANGUAGES CXX)

set(hw_srcs main.cxx)

message(STATUS "The BINARY dir: " ${PROJECT_BINARY_DIR})
message(STATUS "The SOURCE dir: " ${PROJECT_SOURCE_DIR})

add_executable(hello-world ${hw_srcs})