cmake_minimum_required(VERSION 2.8)
project(glew)

# figure out some versions
set(version_MAJOR 1)
set(version_MINOR 9)
set(version_MICRO 0)
set(version_SO_MAJOR_VERSION "${version_MAJOR}.${version_MINOR}")
set(version_SO_MAJOR "${version_MAJOR}.${version_MINOR}")
set(version_SO_VERSION "${version_MAJOR}.${version_MINOR}.${version_MICRO}")

# link to our own include and lib directories
include_directories("include")
link_directories("${CMAKE_CURRENT_BINARY_DIR}/lib")

# put our outputs in the lib or bin directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

# find the needed opengl/glut stuff
find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

# build the dynamic library
add_library(GLEW SHARED "${PROJECT_SOURCE_DIR}/src/glew.c")
set_target_properties(GLEW
	PROPERTIES
		VERSION "${version_SO_VERSION}"
		SOVERSION "${version_SO_MAJOR}"
)
target_link_libraries(GLEW ${OPENGL_LIBRARIES})

# build the static library
add_library(GLEW_static STATIC "${PROJECT_SOURCE_DIR}/src/glew.c")
set_target_properties(GLEW_static
	PROPERTIES
		COMPILE_FLAGS "-DGLEW_STATIC"
)

# Build some test programs
add_executable(glewinfo "${PROJECT_SOURCE_DIR}/src/glewinfo.c")
target_link_libraries(glewinfo GLEW ${OPENGL_LIBRARIES})

set(GLEW_LIBRARY_NAME "${CMAKE_SHARED_LIBRARY_PREFIX}GLEW${CMAKE_SHARED_LIBRARY_SUFFIX}")

# tell the parent about our include and library folders
set(GLEW_LIBRARIES "${CMAKE_CURRENT_BINARY_DIR}/lib/${GLEW_LIBRARY_NAME}" PARENT_SCOPE)
set(GLEW_INCLUDE_DIRS "${CMAKE_CURRENT_BINARY_DIR}/include" PARENT_SCOPE)

# copy over the include files
file(COPY "include" DESTINATION ".")
