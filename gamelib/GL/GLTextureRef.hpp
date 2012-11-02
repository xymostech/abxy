#ifndef GLTEXTUREREF_HPP
#define GLTEXTUREREF_HPP

#include <gamelib/GL/GL.hpp>

template <GLenum type>
class GLTextureRef {
	GLuint texture;
public:
	GLTextureRef();
	~GLTextureRef();

	void Bind() const;

	void SetData2D(GLint level, GLint internal_format, GLsizei width,
	               GLsizei height, GLenum format, GLenum data_type,
	               const GLvoid *data);

	void GenerateMipmap();
};

#include <gamelib/GL/GLTextureRef.inl>

#endif /* GLTEXTUREREF_HPP */

