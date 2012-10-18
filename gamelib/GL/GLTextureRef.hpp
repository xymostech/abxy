#ifndef GLTEXTUREREF_HPP
#define GLTEXTUREREF_HPP

#include <gamelib/GL/GL.hpp>

template <GLenum type>
class GLTextureRef {
	GLuint texture;
public:
	GLTextureRef() {
		glGenTextures(1, &texture);
	}

	~GLTextureRef() {
		glDeleteTextures(1, &texture);
	}

	void Bind() const {
		glBindTexture(type, texture);
	}

	void SetData2D(GLint level, GLint internal_format, GLsizei width,
	               GLsizei height, GLenum format, GLenum data_type,
	               const GLvoid *data) {
		glTexImage2D(
			type, level, internal_format, width, height, 0, format,
			data_type, data
		);
	}

	void GenerateMipmap() {
		glGenerateMipmap(type);
	}
};

#endif /* GLTEXTUREREF_HPP */

