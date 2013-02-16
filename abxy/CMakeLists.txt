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

set(ABXY_SOURCES
    "Primitive.cpp"           "Texture.cpp"
    "util/Split.cpp"          "Mouse.cpp"
    "TextEntity.cpp"          "Stage.cpp"
    "WorldStage.cpp"          "Matrix.cpp"
    "GL/GLVertexArrayRef.cpp" "GL/GLUniformBlockRef.cpp"
    "GL/GLUniformRef.cpp"     "GL/GLProgram.cpp"
    "GL/GLShader.cpp"         "GL/GLShaderRef.cpp"
    "GL/GLAttribRef.cpp"      "GL/GLProgramRef.cpp"
    "GL/GLSamplerRef.cpp"     "audio/Sound.cpp"
    "ProjectionOrtho2d.cpp"   "Sprite.cpp"
    "Projection.cpp"          "SquarePrimitive.cpp"
    "Game.cpp"                "TextureLoader.cpp"
    "ProgramLoader.cpp"       "Vector.cpp"
    "PngLoader.cpp"           "SoundLoader.cpp"
    "Exceptions.cpp"          "Entity.cpp"
    "SpriteAnimation.cpp"     "Formatter.cpp"
    "Key.cpp"                 "FontLoader.cpp"
    "FormattedTextEntity.cpp" "FormattedTextEntity2d.cpp"
    "messages/Message.cpp"    "TexturePrimitive.cpp"
    "Font.cpp"                "FileLoader.cpp"
    "App.cpp"                 "File.cpp"
    "ImageDataLoader.cpp"     "Entity2d.cpp"
    "World.cpp"
)

include("AddPrefix")
ADD_PREFIX(ABXY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}" ${ABXY_SOURCES})

add_library(abxy SHARED
    ${ABXY_SOURCES})
set_target_properties(abxy
    PROPERTIES
        SOVERSION "${version_MAJOR}"
        LINK_FLAGS -stdlib=libc++ -lc++abi -ldl
)
target_link_libraries(abxy ${EXTERNAL_LIBRARIES})

