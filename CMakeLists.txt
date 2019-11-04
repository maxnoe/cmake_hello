cmake_minimum_required(VERSION 3.1...3.15)

project(CMakeHello VERSION 0.1.0 LANGUAGES CXX)

# By default, cmake clears the runtime search
# patch for libraries from exectuables, which would
# result in library not found or having to set LD_LIBRARY_PATH
# this sets the rpath to the installation location of the library
# https://stackoverflow.com/a/30400628/3838691
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


# add our shared library libhello
add_library(hellolib SHARED src/hello.cpp include/hello/hello.hpp include/hello/version.hpp)
target_include_directories(hellolib PUBLIC include)
target_include_directories(hellolib PUBLIC ${PROJECT_BINARY_DIR}/include)
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


if(CMAKE_PROJECT_NAME STREQUAL CMakeHello)
	include(CTest)
endif()
if(CMAKE_PROJECT_NAME STREQUAL CMakeHello AND BUILD_TESTING)
    add_subdirectory(tests)
endif()

# enable installing, defaults are sane, e.g. exe goes into bin, lib into lib, 
# headers into include
install(
	TARGETS hello hellolib
	PUBLIC_HEADER DESTINATION include/hello
)
install(
	FILES ${PROJECT_BINARY_DIR}/include/hello/version.hpp include/hello/hello.hpp
	DESTINATION include/hello/
)
