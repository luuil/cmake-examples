# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
    FATAL: In-source builds are not allowed.
           You should create a separate directory for build files.
")
endif()

cmake_minimum_required(VERSION 3.5.1)
project(tgt-inc-dir VERSION 0.1.0 LANGUAGES CXX)

set(inc_dir_srcs
    src/main.cxx
    src/hi.cxx
    )

# ${PROJECT_NAME} = "tgt-inc-dir"
add_executable(${PROJECT_NAME} ${inc_dir_srcs})

# Set the direcoties that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
# ${PROJECT_SOURCE_DIR}="the location of this CMakeLists.txt file"
target_include_directories(${PROJECT_NAME}
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)