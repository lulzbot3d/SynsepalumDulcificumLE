# Set LC_LIBRARY_PATH variable to ensure CMake can actually use the CPython library
set(ENV{LD_LIBRARY_PATH} "${CMAKE_LIBRARY_PATH}:${LD_LIBRARY_PATH}")
find_package(pybind11 REQUIRED)

pybind11_add_module(pyDulcificum pyDulcificum.cpp)
target_link_libraries(pyDulcificum PUBLIC dulcificumle pybind11::pybind11)
target_compile_definitions(pyDulcificum PRIVATE PYDULCIFICUM_VERSION="${PYDULCIFICUM_VERSION}")
if(NOT MSVC AND NOT ${CMAKE_BUILD_TYPE} MATCHES Debug|RelWithDebInfo)
    pybind11_strip(pyDulcificum)
endif()