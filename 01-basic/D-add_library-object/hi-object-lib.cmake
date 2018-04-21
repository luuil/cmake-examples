##########################
# Object library: 
#   CMake generates rules to compile the source files 
#   into object files but does not link archive or link
#   them into a library file
# More details refer to: https://cmake.org/Wiki/CMake/Tutorials/Object_Library
##########################

set(hi_srcs
    include/hi.hpp
    src/hi.cxx
    )

# Create an object library
add_library(hi_obj_lib OBJECT ${hi_srcs})
target_include_directories(hi_obj_lib PRIVATE "${PROJECT_SOURCE_DIR}/include")