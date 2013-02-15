cmake_minimum_required(VERSION 2.8)
project(freetype)

include(ExternalProject)

# Add the autoconf compilation
ExternalProject_Add(freetype
	PREFIX ${CMAKE_CURRENT_BINARY_DIR}
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
	CONFIGURE_COMMAND
		${CMAKE_CURRENT_SOURCE_DIR}/configure
		--prefix=<INSTALL_DIR>
		--quiet
	BUILD_COMMAND ${MAKE})

set(Freetype_LIBRARY_NAME "${CMAKE_SHARED_LIBRARY_PREFIX}freetype${CMAKE_SHARED_LIBRARY_SUFFIX}")

# send the required variables back up
set(FREETYPE_INCLUDE_DIRS
	"${CMAKE_CURRENT_BINARY_DIR}/include"
	"${CMAKE_CURRENT_BINARY_DIR}/include/freetype2"
	PARENT_SCOPE)
set(FREETYPE_LIBRARIES "${CMAKE_CURRENT_BINARY_DIR}/lib/${Freetype_LIBRARY_NAME}" PARENT_SCOPE)
