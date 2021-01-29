cmake_minimum_required(VERSION 3.15...3.18)

project(fibonacci VERSION 0.1.0 LANGUAGES CXX)

# provides CMAKE_INSTALL_BINDIR / CMAKE_INSTALL_LIBDIR etc.
include(GNUInstallDirs)

# this lets cmake find our moduiles we puit in ./cmake
include(cmake/RPATHHandling.cmake)

# add version info from the project call into a header file
configure_file(
	include/fibonacci/version.h.in
	"${PROJECT_BINARY_DIR}/include/fibonacci/version.h"
)

add_library(fibonacci SHARED
    src/fibonacci.cpp
    include/fibonacci/fibonacci.h
    ${PROJECT_BINARY_DIR}/include/fibonacci/version.h
)

# our library and everyone that uses it must at least use cxx 11
target_compile_features(fibonacci PUBLIC cxx_std_11)
# we will use c++11, not some compiler specific standard like gnu++11
set_target_properties(fibonacci PROPERTIES CXX_EXTENSIONS OFF CXX_STANDARD_REQUIRED ON)


# we need to give different include dirs for this file
# for building and for other people consuming our library from an
# installed location
target_include_directories(
    fibonacci PUBLIC
    $<BUILD_INTERFACE:include;${PROJECT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)


# add our executable fibonacci and link it against our library
add_executable(fibonacci-cli cli/fibonacci.cpp)
target_link_libraries(fibonacci-cli PUBLIC fibonacci)
target_compile_features(fibonacci-cli PUBLIC cxx_std_11)
set_target_properties(
    fibonacci-cli PROPERTIES
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME fibonacci  # call the exe fibonacci not fibonacci-cli without clashing with libfibonacci
)



# Run testing only if people build our project
include(CTest)
if(CMAKE_PROJECT_NAME STREQUAL fibonacci AND BUILD_TESTING)
    add_subdirectory(tests)
endif()

# enable installing, defaults are sane, e.g. exe goes into bin, lib into lib
# but for the public headers, we want them in a sub folder for our project.
install(
    TARGETS fibonacci fibonacci-cli
    EXPORT FibonacciConfig
)
install(DIRECTORY include/fibonacci DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Exporting so that other projects can do find_project(fibonacci)
include(CMakePackageConfigHelpers)
export(
    TARGETS fibonacci fibonacci-cli
    NAMESPACE fibonacci::
    FILE "${CMAKE_CURRENT_BINARY_DIR}/FibonacciConfig.cmake"
)
write_basic_package_version_file(
    fibonacciConfigVersion.cmake
    COMPATIBILITY SameMajorVersion
)
install(
    EXPORT FibonacciConfig
    DESTINATION "${CMAKE_INSTALL_DATADIR}/fibonacci/cmake"
)
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/FibonacciConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_DATADIR}/fibonacci/cmake"
)
