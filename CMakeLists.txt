cmake_minimum_required(VERSION 2.8.10)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# TODO: conditionally set variables depending on compiler
include("CompilerSetup")

project(abxy)

add_subdirectory(external)
add_subdirectory(abxy)
add_subdirectory(res)
#add_subdirectory(examples)
