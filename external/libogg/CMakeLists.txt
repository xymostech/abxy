cmake_minimum_required(VERSION 2.8)
project(libogg)

include(ExternalProject)

# Add the autoconf compilation
ExternalProject_Add(libogg
	PREFIX ${CMAKE_CURRENT_BINARY_DIR}
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
	CONFIGURE_COMMAND
		${CMAKE_CURRENT_SOURCE_DIR}/configure
		--prefix=<INSTALL_DIR>
		--quiet
	BUILD_COMMAND ${MAKE})

# Force Vorbis to use our ogg
set(WITH_OGG "--with-ogg=${CMAKE_CURRENT_BINARY_DIR}" PARENT_SCOPE)

set(Ogg_LIBRARY_NAME "${CMAKE_SHARED_LIBRARY_PREFIX}ogg${CMAKE_SHARED_LIBRARY_SUFFIX}")

# send the required variables back up
set(Ogg_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/include" PARENT_SCOPE)
set(Ogg_LIBRARIES "${CMAKE_CURRENT_BINARY_DIR}/lib/${Ogg_LIBRARY_NAME}" PARENT_SCOPE)
