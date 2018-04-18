## Build

```bash
mkdir build
cd build
cmake ..
```

## Directory Variables

CMake syntax specifies a number of [variables](https://cmake.org/Wiki/CMake_Useful_Variables) which can be used to help find useful directories in your project or source tree. Some of these include:

| Variable | Info |
|------------------|---------------------------|
| CMAKE_SOURCE_DIR | The root source directory |
| CMAKE_CURRENT_SOURCE_DIR | The current source directory if using sub-projects and directories. |
| PROJECT_SOURCE_DIR | The source directory of the current cmake project. |
| CMAKE_BINARY_DIR | The root binary / build directory. This is the directory where you ran the cmake command. |
| CMAKE_CURRENT_BINARY_DIR | The build directory you are currently in. |
| PROJECT_BINARY_DIR | The build directory for the current project. |

## Including Directories

When you have different include folders, you can make your compiler aware of them using the target_include_directories() [function](https://cmake.org/cmake/help/v3.0/command/target_include_directories.html). When compiling this target this will add these directories to the compiler with the `-I` flag e.g. `-I/directory/path`

```
target_include_directories(target
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
```

The `PRIVATE` identifier specifies the scope of the include. **This is important for libraries** and is exlpained in the next example. More details on the function is available [here](https://cmake.org/cmake/help/v3.0/command/target_include_directories.html)