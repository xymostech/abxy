set(ABXY_SOURCES
    "Texture.cpp"
    "Mouse.cpp"
    "Matrix.cpp"
    "ProjectionOrtho2d.cpp"
    "Projection.cpp"
    "Game.cpp"
    "Vector.cpp"
    "Formatter.cpp"
    "Key.cpp"
    #"Font.cpp"
    "App.cpp"

    #"TextEntity.cpp"
    #"Stage.cpp"
    #"WorldStage.cpp"
    #"FormattedTextEntity.cpp"
    #"FormattedTextEntity2d.cpp"
    #"Entity2d.cpp"

    #"Sprite.cpp"
    #"Primitive.cpp"
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
    "entity/WorldEntity.cpp"

    "loader/TextureLoader.cpp"
    "loader/ProgramLoader.cpp"
    "loader/PngLoader.cpp"
    "loader/SoundLoader.cpp"
    "loader/FontLoader.cpp"
    "loader/FileLoader.cpp"
    "loader/ImageDataLoader.cpp"
)

set(ABXY_LINUX_SOURCES
    "util/Path_linux.cpp"
)

set(ABXY_MAC_SOURCES
    "util/Path_mac.cpp"
)

set(ABXY_WINDOWS_SOURCES
)
