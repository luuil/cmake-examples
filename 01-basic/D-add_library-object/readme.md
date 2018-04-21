## Build

```bash
mkdir build
cd build
cmake ..
```

## Object Library

An "OBJECT" library type that can be created with `add_library`:

```cmake
add_library(myObjects OBJECT a.c b.c)
```

CMake generates rules to compile the source files into object files but does not link archive or link them into a library file. 

Instead the object files may be included in other targets created by `add_library` or `add_executable` by listing the object library as a source with special syntax `$<TARGET_OBJECTS:objlib>`, where "`objlib`" is the object library name.

### Motivation

Consider a project that compiles a large number of source files and links them into a single library. One approach is to list all sources in a single `add_library` invocation:

```cmake
# CMakeLists.txt
add_library(big ${many_srcs})
```

This is okay if all the source files need to compile with the same preprocessor definitions, include directories, and other flags. However, large projects typically organize their source files into groups, often in separate subdirectories, that each need different include directories and preprocessor definitions. For such projects it is more convenient for developers to create a separate library target for each group. For example, we can create two subdirectories:

```cmake
# A/CMakeLists.txt
add_library(A ${A_srcs})

# B/CMakeLists.txt
add_library(B ${B_srcs})
```

and then refer to those libraries from the top directory:

```cmake
# CMakeLists.txt
add_subdirectory(A)
add_subdirectory(B)
add_library(big ${other_srcs})
target_link_libraries(big A B)
```

This approach is easy to use and helps organize the project source tree. Since CMake tracks link dependencies automatically it is easy to refer to the "big" library in target_link_libraries calls elsewhere in the project and let CMake propagate the dependency on A and B.

The drawback to the approach is that it creates a separate library file on disk for each group. In this case library files such as `libbig.a`, `libA.a`, and `libB.a` will be created instead of one large `libbig.a`. The additional files may not be desirable for packaging, distribution, or use externally by other build systems.

CMake's OBJECT library type provides a way to avoid this drawback and get the best of both above approaches.

### Usage
Let's convert the above example to use OBJECT libraries. First we change the two subdirectories to specify the OBJECT library type:

```cmake
# A/CMakeLists.txt
add_library(A OBJECT ${A_srcs})

# B/CMakeLists.txt
add_library(B OBJECT ${B_srcs})
```

Then we change the top-level directory to refer to the object libraries as sources of the main library:

```cmake
# CMakeLists.txt
add_subdirectory(A)
add_subdirectory(B)
add_library(big ${other_srcs} $<TARGET_OBJECTS:A> $<TARGET_OBJECTS:B>)
```

CMake will compile all the sources in A and B but does not produce any library files. Then it will compile all the normal sources in big. Finally CMake will construct a single library file using objects compiled from all three targets.

In this case one large library file such as libbig.a is produced. It can be installed and distributed as a single library file, effectively hiding the details of the source tree organization.

### Restrictions

Object libraries may contain only sources (and headers) that compile to object files. They may contain custom commands generating such sources, **but not PRE_BUILD, PRE_LINK, or POST_BUILD commands**. Object libraries **cannot be imported, exported, installed, or linked**.

Most of these restrictions disallow behavior that is not yet implemented but may be defined in the future. They are intended for forward compatibility with future versions of CMake that allow such operations.

> Refer to [Object Library](https://cmake.org/Wiki/CMake/Tutorials/Object_Library)