# CMake Hello World Project [![Build Status](https://travis-ci.com/MaxNoe/cmake_hello.svg?branch=master)](https://travis-ci.com/MaxNoe/cmake_hello)

Introductory CMake Tutorial according to
https://cliutils.gitlab.io/modern-cmake/


RPATH handling from https://cliutils.gitlab.io/modern-cmake


## Building

Use:
```
cmake -S . -B build [-DCMAKE_INSTALL_PREFIX=...]
cmake --build build [--target install]
cd build
ctest -v
```
