# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
    FATAL: In-source builds are not allowed.
           You should create a separate directory for build files.
")
endif()

cmake_minimum_required(VERSION 3.5.1)
project(add-lib VERSION 0.1.0 LANGUAGES CXX)

set(hi_srcs
    src/hi.cxx
    )


# Create a static library 'cmake object' from the sources
add_library(${PROJECT_NAME}-shared  SHARED ${hi_srcs})

# on windows: link against shared library on windows
# needs 'dllexport/dllimport'
if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    message(STATUS "MSVC Compiler!")
    # target_compile_definitions(${PROJECT_NAME}-shared PRIVATE -DDLL_EXPORTS)
    add_definitions(-DDLL_EXPORTS)
endif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")

# The included directory can be regard as 
# the 'namespace' of the source files
target_include_directories(${PROJECT_NAME}-shared
    PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
)

# Create a shared library 'cmake object' from the sources
add_library(${PROJECT_NAME}-static  STATIC ${hi_srcs})
target_include_directories(${PROJECT_NAME}-static
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

set(main_srcs
    src/main.cxx
    )

# Create an executable 'cmake object'
# and link with shared library
add_executable(${PROJECT_NAME}-shared-exe ${main_srcs})
target_link_libraries(${PROJECT_NAME}-shared-exe ${PROJECT_NAME}-shared)

# Create an executable 'cmake object'
# and link with static library
add_executable(${PROJECT_NAME}-static-exe ${main_srcs})
target_link_libraries(${PROJECT_NAME}-static-exe ${PROJECT_NAME}-static)