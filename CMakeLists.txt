cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(opencv-builds VERSION 0.1.0 LANGUAGES CXX C)


# External dependencies
# set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
# include(opencv)

# build at configuration time
configure_file(
    cmake/opencv_configuration.cmake
    ${CMAKE_BINARY_DIR}/opencv-download/CMakeLists.txt
    )
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/opencv-download)
if(result)
  message(FATAL_ERROR "CMake step for opencv failed: ${result}")
endif()

# execute_process(
#     COMMAND ${CMAKE_COMMAND} --build .
#     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/opencv-download
# )
# if(result)
#   message(FATAL_ERROR "Build step for cctz failed: ${result}")
# endif()


# find_package(OpenCV
#     REQUIRED
#     PATHS ${opencv_BUILD}
#     )
# message(STATUS "Found opencv${OpenCV_VERSION}${OpenCV_VERSION_MAJOR}${OpenCV_VERSION_MINOR}")