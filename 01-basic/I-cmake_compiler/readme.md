## Build

```bash
mkdir build
cd build
cmake ..
```

## Compiler

CMake exposes options to control the programs used to compile and link your code. These programs include:

- `CMAKE_C_COMPILER` - The program used to compile c code.
- `CMAKE_CXX_COMPILER` - The program used to compile c++ code.
- `CMAKE_LINKER` - The program used to link your binary.

> Note:
> In this example clang-3.6 is installed via the command `sudo apt-get install clang-3.6`