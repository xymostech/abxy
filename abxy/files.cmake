set(ABXY_SOURCES
    "App.cpp"
    "Game.cpp"
    "Formatter.cpp"

    "projection/Projection.cpp"
    "projection/ProjectionIdentity.cpp"
    "projection/ProjectionOrtho2d.cpp"
    "projection/ProjectionFrustum.cpp"

    #"Font.cpp"
    "Texture.cpp"

    "Mouse.cpp"
    "Key.cpp"

    "Model.cpp"

    #"TextEntity.cpp"
    #"Stage.cpp"
    #"WorldStage.cpp"
    #"FormattedTextEntity.cpp"
    #"FormattedTextEntity2d.cpp"
    #"Entity2d.cpp"

    "primitive/Primitive.cpp"
    "primitive/BoundPrimitive.cpp"
    "primitive/PrimitiveData.cpp"
    #"primitive/SquarePrimitive.cpp"
    #"primitive/TexturePrimitive.cpp"
    #"primitive/Sprite.cpp"
    #"primitive/SpriteAnimation.cpp"

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
    "entity/LoaderEntity.cpp"
    "entity/Entity3d.cpp"

    "loader/TextureLoader.cpp"
    "loader/ProgramLoader.cpp"
    "loader/PngLoader.cpp"
    "loader/SoundLoader.cpp"
    #"loader/FontLoader.cpp"
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
