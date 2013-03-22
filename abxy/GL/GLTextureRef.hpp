#ifndef GLTEXTUREREF_HPP
#define GLTEXTUREREF_HPP

#include <abxy/GL/GL.hpp>
#include <abxy/GL/GLCreateRef.hpp>

template <GLenum type>
class GLTextureRef : public GLCreateRef<GLuint> {
public:
	GLTextureRef();
	~GLTextureRef();

	void Bind() const;

	void SetData2D(GLint level, GLint internal_format, GLsizei width,
	               GLsizei height, GLenum format, GLenum data_type,
	               const GLvoid *data);

	void GenerateMipmap();
};

#include <abxy/GL/GLTextureRef.inl>

#endif /* GLTEXTUREREF_HPP */

