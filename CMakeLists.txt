cmake_minimum_required(VERSION 3.15...3.18)

project(Hello VERSION 0.1.0 LANGUAGES CXX)

# provides CMAKE_INSTALL_BINDIR / CMAKE_INSTALL_LIBDIR etc.
include(GNUInstallDirs)

# By default, cmake clears the runtime search
# patch for libraries from exectuables, which would
# result in library not found or having to set LD_LIBRARY_PATH
# this sets the rpath to the installation location of the library
# https://stackoverflow.com/a/30400628/3838691
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# add our shared library libhello
add_library(hellolib SHARED src/hello.cpp include/hello/hello.hpp include/hello/version.hpp)

# we need to give different include dirs for this file
# for building and for other people consuming our library from an
# installed location
target_include_directories(
    hellolib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
# for the auto generated header
target_include_directories(
    hellolib PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(hellolib PUBLIC cxx_std_11)
set_target_properties(hellolib PROPERTIES CXX_EXTENSIONS OFF)


# cmake cannot have to targets with the same name but we want
# libhello not libhellolib
SET_TARGET_PROPERTIES(hellolib PROPERTIES OUTPUT_NAME hello)

configure_file(
	"${PROJECT_SOURCE_DIR}/include/hello/version.hpp.in"
	"${PROJECT_BINARY_DIR}/include/hello/version.hpp"
)

# add our executable hello and link it against our library
add_executable(hello apps/hello.cpp)
target_link_libraries(hello PUBLIC hellolib)
target_compile_features(hello PUBLIC cxx_std_11)
set_target_properties(hello PROPERTIES CXX_EXTENSIONS OFF)

# using a variable to convert to list
set(HELLO_HEADERS
    "${PROJECT_BINARY_DIR}/include/hello/version.hpp"
    "include/hello/hello.hpp"
)
set_target_properties(hello PROPERTIES PUBLIC_HEADER "${HELLO_HEADERS}")


if(CMAKE_PROJECT_NAME STREQUAL CMakeHello)
	include(CTest)
endif()
if(CMAKE_PROJECT_NAME STREQUAL CMakeHello AND BUILD_TESTING)
    add_subdirectory(tests)
endif()

# enable installing, defaults are sane, e.g. exe goes into bin, lib into lib
# but for the public headers, we want them in a sub folder for our project.
install(
    TARGETS hello hellolib
    EXPORT HelloConfig
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/hello
)

# Exporting so that other projects can do find_project(Hello)
include(CMakePackageConfigHelpers)
export(
    TARGETS hello hellolib
    NAMESPACE Hello::
    FILE "${CMAKE_CURRENT_BINARY_DIR}/HelloConfig.cmake"
)
write_basic_package_version_file(
    HelloConfigVersion.cmake
    COMPATIBILITY SameMajorVersion
)
install(
    EXPORT HelloConfig
    DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/Hello"
)
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/HelloConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/Hello"
)
