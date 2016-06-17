cmake_minimum_required(VERSION 2.6)

project(pybind-samples CXX)
set(libcpp "cpp")


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}.")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fstack-protector")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic")

set(src_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(pybind11_dir "${CMAKE_CURRENT_SOURCE_DIR}/pybind11/include")
include_directories(${pybind11_dir})

find_package(PythonLibs 3.4 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_library(${libcpp} SHARED "${src_dir}/cpp_lib.cpp")
set_target_properties(${libcpp} PROPERTIES PREFIX "")
target_link_libraries(${libcpp} ${PYTHON_LIBRARIES})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.py
	DESTINATION ${CMAKE_BINARY_DIR}/)
