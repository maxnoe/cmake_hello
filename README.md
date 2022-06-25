# CMake Hello World Project [![.github/workflows/ci.yml](https://github.com/maxnoe/cmake_hello/actions/workflows/ci.yml/badge.svg)](https://github.com/maxnoe/cmake_hello/actions/workflows/ci.yml)

Introductory CMake Tutorial according to
https://cliutils.gitlab.io/modern-cmake/


RPATH handling from https://cliutils.gitlab.io/modern-cmake


## Building

Use:
```
cmake -S . -B build [-DCMAKE_INSTALL_PREFIX=...]
cmake --build build -- [-j CORES]
cmake --install build
./build/tests/tests  # or ctest --test-dir build
```
