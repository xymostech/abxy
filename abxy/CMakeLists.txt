cmake_minimum_required(VERSION 2.8.10)
project(abxy_lib)

set(version_MAJOR 0)
set(version_MINOR 0)
set(version_MICRO 1)
set(version_SO_MAJOR "${version_MAJOR}.${version_MINOR}")
set(version_SO_VERSION "${version_MAJOR}.${version_MINOR}.${version_MICRO}")

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${EXTERNAL_INCLUDE_DIRS}")

add_definitions(-g -std=c++11 -Wall -stdlib=libc++)

file(GLOB_RECURSE ABXY_SOURCES "*.cpp")

add_library(abxy SHARED
    ${ABXY_SOURCES})
set_target_properties(abxy
    PROPERTIES
        SOVERSION "${version_MAJOR}"
        LINK_FLAGS -stdlib=libc++ -lc++abi -ldl
)
target_link_libraries(abxy ${EXTERNAL_LIBRARIES})
