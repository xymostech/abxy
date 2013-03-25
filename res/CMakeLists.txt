cmake_minimum_required(VERSION 2.8.10)
project(resources)

set(FILES
    font.fragment.shader
    font.vertex.shader
    hit.ogg
    LiberationMono-Regular.ttf
    standard.fragment.shader
    standard.vertex.shader
    standard.program
    lighting.fragment.shader
    lighting.vertex.shader
    lighting.program
    test.model
    test.png
    white.png)

include("AddPrefix")
ADD_PREFIX(ABXY_RESOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}" ${FILES})
set(ABXY_RESOURCE_FILES ${ABXY_RESOURCE_FILES} PARENT_SCOPE)
