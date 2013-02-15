
# Finds GLFW library
#
#  GLFW_INCLUDE_DIR - where to find GLFW.h, etc.
#  GLFW_LIBRARIES   - List of libraries when using GLFW.
#  GLFW_FOUND       - True if GLFW found.
#

if(GLFW_INCLUDE_DIR)
        # Already in cache, be silent
        set(GLFW_FIND_QUIETLY TRUE)
endif(GLFW_INCLUDE_DIR)

find_path(GLFW_INCLUDE_DIR GL/glfw.h
        /opt/local/include
        /usr/local/include
        /usr/include
)

set(GLFW_NAMES glfw)
find_library(GLFW_LIBRARY
        NAMES ${GLFW_NAMES}
        PATHS /usr/lib /usr/local/lib /opt/local/lib
)

if(GLFW_INCLUDE_DIR AND GLFW_LIBRARY)
        set(GLFW_FOUND TRUE)
        set(GLFW_LIBRARIES ${GLFW_LIBRARY})
else(GLFW_INCLUDE_DIR AND GLFW_LIBRARY)
        set(GLFW_FOUND FALSE)
        set(GLFW_LIBRARIES)
endif(GLFW_INCLUDE_DIR AND GLFW_LIBRARY)

if(GLFW_FOUND)
        if(NOT GLFW_FIND_QUIETLY)
                message(STATUS "Found GLFW: ${GLFW_LIBRARY}")
        endif(NOT GLFW_FIND_QUIETLY)
else(GLFW_FOUND)
        if(GLFW_FIND_REQUIRED)
                message(STATUS "Looked for GLFW libraries named ${GLFW_NAMES}.")
                message(STATUS "Include file detected: [${GLFW_INCLUDE_DIR}].")
                message(STATUS "Lib file detected: [${GLFW_LIBRARY}].")
                message(FATAL_ERROR "=========> Could NOT find GLFW library")
        endif(GLFW_FIND_REQUIRED)
endif(GLFW_FOUND)

mark_as_advanced(
        GLFW_LIBRARY
        GLFW_INCLUDE_DIR
)
