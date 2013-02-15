cmake_minimum_required(VERSION 2.8.10)
project(external_libs)

include(ExternalProject)

# include our custom Find scripts
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if(USE_LOCAL_ALL)
        set(USE_LOCAL_LIBOGG    true  CACHE BOOL "Use the included libogg")
        set(USE_LOCAL_LIBVORBIS true  CACHE BOOL "Use the included libvorbis")
        set(USE_LOCAL_GLEW      true  CACHE BOOL "Use the included glew")
        set(USE_LOCAL_GLFW      true  CACHE BOOL "Use the included glfw")
        set(USE_LOCAL_FREETYPE  true  CACHE BOOL "Use the included freetype")
else()
        set(USE_LOCAL_LIBOGG    false CACHE BOOL "Use the included libogg")
        set(USE_LOCAL_LIBVORBIS false CACHE BOOL "Use the included libvorbis")
        set(USE_LOCAL_GLEW      false CACHE BOOL "Use the included glew")
        set(USE_LOCAL_GLFW      false CACHE BOOL "Use the included glfw")
        set(USE_LOCAL_FREETYPE  false CACHE BOOL "Use the included freetype")
endif()


# Build ogg if we don't have that
find_package(Ogg)
if(NOT Ogg_FOUND OR USE_LOCAL_LIBOGG)
        message("-- Building local libogg")
        add_subdirectory(libogg)
endif()

# Build Vorbis if we don't have that
find_package(Vorbis)
if(NOT Vorbis_FOUND OR USE_LOCAL_LIBVORBIS)
        message("-- Building local libvorbis")
        add_subdirectory(libvorbis)
endif()

# Build GLEW if we don't have that
find_package(GLEW)
if(NOT GLEW_FOUND OR USE_LOCAL_GLEW)
        message("-- Building local GLEW")
        add_subdirectory(glew)
endif()

find_package(GLFW)
if(NOT GLFW_FOUND OR USE_LOCAL_GLFW)
        message("-- Building local glfw")
        add_subdirectory(glfw)
endif()

find_package(Freetype)
if(NOT FREETYPE_FOUND OR USE_LOCAL_FREETYPE)
        message("-- Building local Freetype")
        add_subdirectory(freetype)
endif()

message("-- Building local UnitTest++")
add_subdirectory(UnitTest++)

find_package(OpenGLNoGLU REQUIRED)
find_package(AO REQUIRED)
find_package(PNG REQUIRED)
find_package(Threads)

set(EXTERNAL_LIBRARIES
        ${OPENGL_LIBRARIES}
        ${Ogg_LIBRARIES}
        ${Vorbis_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${GLFW_LIBRARIES}
        ${FREETYPE_LIBRARIES}
        ${AO_LIBRARIES}
        ${PNG_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        PARENT_SCOPE)

set(EXTERNAL_INCLUDE_DIRS
        ${OPENGL_INCLUDE_DIRS}
        ${Ogg_INCLUDE_DIR}
        ${Vorbis_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
        ${GLFW_INCLUDE_DIR}
        ${FREETYPE_INCLUDE_DIRS}
        ${AO_INCLUDE_DIR}
        ${PNG_INCLUDE_DIRS}
        PARENT_SCOPE)

set(ALL_EXTERNAL_DEPENDENCIES
        libogg
        libvorbis
        GLEW
        glfw
        freetype
        PARENT_SCOPE)
