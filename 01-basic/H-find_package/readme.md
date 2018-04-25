## Build

```bash
mkdir build
cd build
cmake ..
```

## Boost Requirements

`Boost` library should already installed or install version 1.67.0 (or other version) by:

```bash
wget -c https://dl.bintray.com/boostorg/release/1.67.0/source/boost_1_67_0.tar.gz
tar -xvzf boost_1_67_0.tar.gz
cd boost_1_67_0
./bootstrap.sh
./b2 install
```

[Latest Boost download](https://www.boost.org/users/history)

## find_package

The `find_package()` function will search for CMake modules by `Find{PACKEAGE_NAME}.cmake` file from the list of folders in `CMAKE_MODULE_PATH`. The extracted variables to `find_package()` will depend on the module you are looking for. This is typically documented at the top of the `Find{PACKEAGE_NAME}.cmake` file.

A basic example of finding `Boost` package as below:

```cmake
find_package(Boost 1.67.0 REQUIRED COMPONENTS filesystem system)
```

The arguments are:

- Boost - Name of the package. This is part of used to find the module file FindBoost.cmake.
- 1.67.0 - The minimum version of boost to find.
- REQUIRED - Tells the module that this is required and will stop build if it cannot be found.
- COMPONENTS - The list of libraries to find.

Most `Find{PACKEAGE_NAME}.cmake` file will set a `{PACKEAGE_NAME}_FOUND` variable, which can used to check if the package is available on the system. In this example the variable is `Boost_FOUND`:

```cmake
if(Boost_FOUND)
    message ("boost found")
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()
```

Variables will be set refer to [cmake site: find_package](https://cmake.org/cmake/help/v3.5/command/find_package.html)

## Alias targets

Most modern CMake libraries export ALIAS targets in their module files. The benefit of imported targets are that they can also populate include directories and linked libraries.

For example, starting from v3.5+ of CMake, the Boost module supports this. Similar to using your own ALIAS target for libraires, an ALIAS in a module can make referencing found targets eaiser.

In the case, all targets are exported using the `Boost::` identifier and then the name of the subsystem. For example you can use:

- `Boost::boost` for header only libraries
- `Boost::system` for the boost system library.
- `Boost::filesystem` for filesystem library.

As with your own targets, these targets include their dependencies, so linking against `Boost::filesystem` will automatically add `Boost::boost` and `Boost::system` dependencies.

To link against an imported target you can use the following:

```cmake
target_link_libraries( third_party_include
  PRIVATE
      Boost::filesystem
)
```

## Non-alias targets

While most modern libraries use imported targets, not all modules have been updated. In the case where a library hasn’t been updated you will often find the following variables available:

- `{PACKEAGE_NAME}_INCLUDE_DIRS` - A varialble pointing to the include directory for the library.

- `{PACKEAGE_NAME}_LIBRARY` - A variable pointing to the library path.

These can then be added to your target_include_directories and target_link_libraries as:

```cmake
# Include the boost headers
target_include_directories( third_party_include
    PRIVATE ${Boost_INCLUDE_DIRS}
)

# link against the boost libraries
target_link_libraries( third_party_include
    PRIVATE
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
)
```