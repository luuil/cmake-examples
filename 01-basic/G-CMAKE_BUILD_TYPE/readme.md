## Build

```bash
mkdir build
cd build
cmake ..
```

## CMAKE_BUILD_TYPE

CMake has a number of built in build configurations which can be used to compile your project. These specify the optimization levels and if debug information is to be included in the binary.

The levels provided are:

- **Release** - Adds the `-O3 -DNDEBUG` flags to the compiler
- **Debug** - Adds the `-g`
- **MinSizeRel** - Adds `-Os -DNDEBUG`
- **RelWithDebInfo** - Adds `-O2 -g -DNDEBUG`

### Set Build Type when configuration

- Use cmake-gui
- Passing into cmake  
  ```bash
  cmake .. -DCMAKE_BUILD_TYPE=Release
  ```

### Set Default Build Type when creat `CMakeLists.txt`

The default build type provided by CMake is to include no compiler flags for optimization. For some projects you may want to set a default build type.

To do this you can add the following to your top level CMakeLists.txt

```cmake
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message("Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()
```

The `RelWithDebInfo` build type will be set as default build type.