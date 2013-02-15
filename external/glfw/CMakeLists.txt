cmake_minimum_required(VERSION 2.8)
project(glfw)

# figure out the version
set(version_MAJOR 2)
set(version_MINOR 7)
set(version_MICRO 7)
set(version_SO_MAJOR "${version_MAJOR}.${version_MINOR}")
set(version_SO_VERSION "${version_MAJOR}.${version_MINOR}.${version_MICRO}")

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

# Figure out the operating system
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(build_x11 true)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(build_cocoa true)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(build_win3d true)
endif()

include_directories("include")
link_directories("${CMAKE_CURRENT_BINARY_DIR}/lib")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

include_directories("lib")

set(LIBRARIES ${OPENGL_LIBRARIES})

set(OBJS
    "lib/enable.c"
    "lib/fullscreen.c"
    "lib/glext.c"
    "lib/image.c"
    "lib/init.c"
    "lib/input.c"
    "lib/joystick.c"
    "lib/stream.c"
    "lib/tga.c"
    "lib/thread.c"
    "lib/time.c"
    "lib/window.c"
    )

if(build_x11)
    set(OBJS ${OBJS}
        "lib/x11/x11_enable.c"
        "lib/x11/x11_fullscreen.c"
        "lib/x11/x11_glext.c"
        "lib/x11/x11_init.c"
        "lib/x11/x11_joystick.c"
        "lib/x11/x11_keysym2unicode.c"
        "lib/x11/x11_thread.c"
        "lib/x11/x11_time.c"
        "lib/x11/x11_window.c"
        )
    include_directories("lib/x11")
    add_definitions(-D_GLFW_HAS_GLXGETPROCADDRESS)
elseif(build_cocoa)
    set(OBJS ${OBJS}
        "lib/cocoa/cocoa_enable.m"
        "lib/cocoa/cocoa_fullscreen.m"
        "lib/cocoa/cocoa_glext.m"
        "lib/cocoa/cocoa_init.m"
        "lib/cocoa/cocoa_joystick.m"
        "lib/cocoa/cocoa_thread.c"
        "lib/cocoa/cocoa_time.m"
        "lib/cocoa/cocoa_window.m"
        )
    include_directories("lib/cocoa")
    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    set(LIBRARIES ${LIBRARIES} ${COCOA_LIBRARY} ${IOKIT_LIBRARY})
elseif(build_win32)
    set(OBJS ${OBJS}
        "lib/win32/win32_enable.c"
        "lib/win32/win32_fullscreen.c"
        "lib/win32/win32_glext.c"
        "lib/win32/win32_init.c"
        "lib/win32/win32_joystick.c"
        "lib/win32/win32_thread.c"
        "lib/win32/win32_time.c"
        "lib/win32/win32_window.c"
        )
    include_directories("lib/win32")
endif()

# build shared library
add_library(glfw SHARED ${OBJS})
set_target_properties(glfw
    PROPERTIES
        VERSION "${version_SO_VERSION}"
        SOVERSION "${version_SO_MAJOR}"
)
target_link_libraries(glfw ${LIBRARIES})

# build static library
add_library(glfw_static STATIC ${OBJS})

set(GLFW_LIBRARY_NAME "${CMAKE_SHARED_LIBRARY_PREFIX}glfw${CMAKE_SHARED_LIBRARY_SUFFIX}")

# tell the parent about our include and library folders
set(GLFW_LIBRARIES "${CMAKE_CURRENT_BINARY_DIR}/lib/${GLFW_LIBRARY_NAME}" PARENT_SCOPE)
set(GLFW_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/include" PARENT_SCOPE)

# copy over the include files
file(COPY "include" DESTINATION ".")
