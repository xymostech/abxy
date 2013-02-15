cmake_minimum_required(VERSION 2.8)
project(libvorbis)

include(ExternalProject)

# Add the autoconf compilation
ExternalProject_Add(libvorbis
	PREFIX ${CMAKE_CURRENT_BINARY_DIR}
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
	CONFIGURE_COMMAND
		${CMAKE_CURRENT_SOURCE_DIR}/configure
		--prefix=<INSTALL_DIR>
		${WITH_OGG}
		--quiet
	BUILD_COMMAND ${MAKE})

add_dependencies(libvorbis libogg)

set(Vorbis_LIBRARY_NAME "${CMAKE_SHARED_LIBRARY_PREFIX}vorbis${CMAKE_SHARED_LIBRARY_SUFFIX}")
set(VorbisFile_LIBRARY_NAME "${CMAKE_SHARED_LIBRARY_PREFIX}vorbisfile${CMAKE_SHARED_LIBRARY_SUFFIX}")

# send the required variables back up
set(Vorbis_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/include" PARENT_SCOPE)
set(Vorbis_LIBRARIES
    "${CMAKE_CURRENT_BINARY_DIR}/lib/${Vorbis_LIBRARY_NAME}"
    "${CMAKE_CURRENT_BINARY_DIR}/lib/${VorbisFile_LIBRARY_NAME}"
    PARENT_SCOPE)
