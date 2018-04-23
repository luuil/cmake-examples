## Build

```bash
mkdir build
cd build
cmake ..
```

## Install

CMake offers the ability to add a `make install` target to allow a user to install binaries, libraries and other files. The base install location is controlled by the variable CMAKE_INSTALL_PREFIX which can be set using `ccmake` or by calling cmake with `cmake .. -DCMAKE_INSTALL_PREFIX=/install/location`

### Install binary or library

The files that are installed are controlled by the install() function.
Install the generated target binaryto the destination `${CMAKE_INSTALL_PREFIX}/bin`:

```cmake
install (TARGETS ${PROJECT_NAME}
    DESTINATION bin)
}
```

Install the generated STATIC library to the destination `${CMAKE_INSTALL_PREFIX}/lib`:

```cmake
install (TARGETS ${lib_name}
    LIBRARY DESTINATION lib)
}
```

Install the generated SHARED library to the destination `${CMAKE_INSTALL_PREFIX}/lib`
and `${CMAKE_INSTALL_PREFIX}/bin`:

```cmake
# shared lib on windows should use this to install
# because it contains `.dll` and `.lib` file at same time
if(WIN32) # windows
    install (TARGETS hi_lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)
else(WIN32) # others
    install (TARGETS hi_lib LIBRARY DESTINATION lib)
endif(WIN32)
```

### Install directory

Install the header files for developing against the library/excutable into the `${CMAKE_INSTALL_PREFIX}/include` directory:

```cmake
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    DESTINATION include)
```

### Install file

Install a configuration file `cmake-examples.conf` to the destination `${CMAKE_INSTALL_PREFIX}/etc`:

```cmake
install (FILES cmake-examples.conf
    DESTINATION etc)
```