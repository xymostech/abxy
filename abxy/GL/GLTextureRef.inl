#ifndef GLTEXTUREREF_INL
#define GLTEXTUREREF_INL

#include <abxy/GL/GLTextureRef.hpp>

template <GLenum type>
GLTextureRef<type>::GLTextureRef() {
	GLuint texture;
	glGenTextures(1, &texture);
	SetRef(texture);
}

template <GLenum type>
GLTextureRef<type>::~GLTextureRef() {
	glDeleteTextures(1, &GetRef());
}

template <GLenum type>
void GLTextureRef<type>::Bind() const {
	glBindTexture(type, GetRef());
}

template <GLenum type>
void GLTextureRef<type>::SetData2D(
	GLint level, GLint internal_format, GLsizei width, GLsizei height,
	GLenum format, GLenum data_type, const GLvoid *data
) {
	glTexImage2D(
		type, level, internal_format, width, height, 0, format,
		data_type, data
	);
}

template <GLenum type>
void GLTextureRef<type>::GenerateMipmap() {
	glGenerateMipmap(type);
}

#endif /* GLTEXTUREREF_INL */

