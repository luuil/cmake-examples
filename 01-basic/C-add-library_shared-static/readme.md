## Build

```bash
mkdir build
cd build
cmake ..
```

## Shared/Static Library

The `add_library()` function is used to create a shared/static library from some source files:

```cpp
add_library(hi-lib SHARED
    src/hi.cpp
)
```

## `message`

Display a message:

```cmake
message([<mode>] "message to display" ...)
```

The `mode` can be one of these values:

value          | info
---------------|------------------------------------------
(none)         | Important information
STATUS         | Incidental information
WARNING        | CMake Warning, continue processing
AUTHOR_WARNING | CMake Warning (dev), continue processing
SEND_ERROR     | CMake Error, continue processing, but skip generation
FATAL_ERROR    | CMake Error, stop processing and generation
DEPRECATION    | CMake Deprecation Error or Warning if variable CMAKE_ERROR_DEPRECATED or CMAKE_WARN_DEPRECATED is enabled, respectively, else no message.

## `dllexport`/`dllimport`

When we create shared libraries on windows, we need to export/import,
so that they can be seen externally.