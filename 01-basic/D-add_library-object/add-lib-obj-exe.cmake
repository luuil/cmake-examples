set(main_srcs
    src/main.cxx
    )

# Create an executable
# Object library used as a source, can be used in `add_library` or `add_executable`
add_executable(${PROJECT_NAME}
    ${main_srcs}
    $<TARGET_OBJECTS:hi_obj_lib>
    )

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")