## Build

```bash
mkdir build
cd build
cmake ..
```

## Target link library

The usage requirements of a target can transitively propagate to dependents. The `target_link_libraries()` command has PRIVATE, INTERFACE and PUBLIC keywords to control the propagation.

```cmake
add_library(archive archive.cpp)
target_compile_definitions(archive INTERFACE USING_ARCHIVE_LIB)

add_library(serialization serialization.cpp)
target_compile_definitions(serialization INTERFACE USING_SERIALIZATION_LIB)

add_library(archiveExtras extras.cpp)
target_link_libraries(archiveExtras PUBLIC archive)
target_link_libraries(archiveExtras PRIVATE serialization)
# archiveExtras is compiled with -DUSING_ARCHIVE_LIB
# and -DUSING_SERIALIZATION_LIB

add_executable(consumer consumer.cpp)
# consumer is compiled with -DUSING_ARCHIVE_LIB
target_link_libraries(consumer archiveExtras)
```

Because archive is a PUBLIC dependency of archiveExtras, the usage requirements of it are propagated to consumer too. Because serialization is a PRIVATE dependency of archiveExtras, the usage requirements of it are not propagated to consumer.

Generally, a dependency should be specified in a use of `target_link_libraries()` with the `PRIVATE` keyword if it is used by **only the implementation of a library, and not in the header files**. If a dependency is **additionally used in the header files of a library** (e.g. for class inheritance), then it should be specified as a `PUBLIC` dependency. A dependency which is **not used by the implementation of a library, but only by its headers** should be specified as an `INTERFACE` dependency. The `target_link_libraries()` command may be invoked with multiple uses of each keyword:

```cmake
target_link_libraries(archiveExtras
  PUBLIC archive
  PRIVATE serialization
)
```

> Refer to [transitive usage requirements](https://cmake.org/cmake/help/v3.11/manual/cmake-buildsystem.7.html#transitive-usage-requirements)