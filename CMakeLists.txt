cmake_minimum_required(VERSION 2.8.10)

# TODO: conditionally set variables depending on compiler
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/defines.cmake")

project(abxy)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(external)

add_subdirectory(examples)

add_subdirectory(abxy)
