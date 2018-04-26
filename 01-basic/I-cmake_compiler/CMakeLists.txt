# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
    FATAL: In-source builds are not allowed.
           You should create a separate directory for build files.
")
endif()

cmake_minimum_required(VERSION 3.5.1)
project(clang-compiler VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_C_COMPILER "clang-3.6" CACHE STRING "Compiler for C" FORCE)
set(CMAKE_CXX_COMPILER "clang++-3.6" CACHE STRING "Compiler for C++" FORCE)

set(hw_srcs main.cxx)

add_executable(${PROJECT_NAME}-exe ${hw_srcs})