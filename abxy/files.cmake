set(ABXY_SOURCES
    "App.cpp"
    "Game.cpp"
    "Formatter.cpp"

    "ProjectionIdentity.cpp"
    "ProjectionOrtho2d.cpp"
    "Projection.cpp"

    "Font.cpp"
    "Texture.cpp"

    "Mouse.cpp"
    "Key.cpp"

    #"TextEntity.cpp"
    #"Stage.cpp"
    #"WorldStage.cpp"
    #"FormattedTextEntity.cpp"
    #"FormattedTextEntity2d.cpp"
    #"Entity2d.cpp"

    "Primitive.cpp"
    #"Sprite.cpp"
    #"SquarePrimitive.cpp"
    #"TexturePrimitive.cpp"
    #"SpriteAnimation.cpp"

    "GL/GLVertexArrayRef.cpp"
    "GL/GLUniformBlockRef.cpp"
    "GL/GLUniformRef.cpp"
    "GL/GLProgram.cpp"
    "GL/GLShader.cpp"
    "GL/GLShaderRef.cpp"
    "GL/GLAttribRef.cpp"
    "GL/GLProgramRef.cpp"
    "GL/GLSamplerRef.cpp"

    "util/Split.cpp"
    "util/Logger.cpp"
    "util/File.cpp"
    # "util/Path_{OS}.cpp"

    "messages/Message.cpp"

    "audio/Sound.cpp"

    "entity/Entity.cpp"
    "entity/PassthroughEntity.cpp"
    "entity/BranchEntity.cpp"
    "entity/BaseEntity.cpp"
    "entity/WorldEntity.cpp"

    "loader/TextureLoader.cpp"
    "loader/ProgramLoader.cpp"
    "loader/PngLoader.cpp"
    "loader/SoundLoader.cpp"
    "loader/FontLoader.cpp"
    "loader/FileLoader.cpp"
    "loader/ImageDataLoader.cpp"
    "loader/LoaderCache.cpp"
    "loader/ProgramLoaderCache.cpp"

    "math/Vector2.cpp"
    "math/Vector3.cpp"
    "math/Vector4.cpp"
    "math/Matrix.cpp"
)

set(ABXY_LINUX_SOURCES
    "util/Path_linux.cpp"
)

set(ABXY_MAC_SOURCES
    "util/Path_mac.cpp"
)

set(ABXY_WINDOWS_SOURCES
)
