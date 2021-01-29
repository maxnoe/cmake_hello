# RPATH handling. This makes setting LD_LIBRARY_PATH unecessary
# as it will compile the path to the libraries into the libraries / executables
if(APPLE)
    list(APPEND CMAKE_INSTALL_RPATH "@executable_path/../${CMAKE_INSTALL_LIBDIR}")
else()
    list(APPEND CMAKE_INSTALL_RPATH "$ORIGIN/../${CMAKE_INSTALL_LIBDIR}")
endif()
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
