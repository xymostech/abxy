cmake_minimum_required(VERSION 2.8.10)
project(examples)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../")
include_directories(${EXTERNAL_INCLUDE_DIRS})

add_definitions(-g -std=c++11 -Wall -Wextra -Werror -stdlib=libc++)

add_executable(Test Test.cpp)
target_link_libraries(Test abxy)
set_target_properties(Test
    PROPERTIES
        LINK_FLAGS "-stdlib=libc++ -lc++abi -ldl")

add_custom_target(example_resources ALL
    COMMAND mkdir -p "${CMAKE_CURRENT_BINARY_DIR}/res"
    COMMAND cp ${ABXY_RESOURCE_FILES} "${CMAKE_CURRENT_BINARY_DIR}/res/")
