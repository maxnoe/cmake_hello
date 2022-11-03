# RPATH handling. This makes setting LD_LIBRARY_PATH unecessary
# as it will compile the path to the libraries into the libraries / executables
include(GNUInstallDirs)
file(RELATIVE_PATH libdir_relative
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}
    ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR}
)
if(APPLE)
    list(APPEND CMAKE_INSTALL_RPATH @loader_path)
    list(APPEND CMAKE_INSTALL_RPATH @executable_path/${libdir_relative})
else()
    list(APPEND CMAKE_INSTALL_RPATH $ORIGIN)
    list(APPEND CMAKE_INSTALL_RPATH $ORIGIN/${libdir_relative})
endif()
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
