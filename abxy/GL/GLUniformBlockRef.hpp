#ifndef GLUNIFORMBLOCKREF_HPP
#define GLUNIFORMBLOCKREF_HPP

#include <abxy/GL/GL.hpp>
#include <abxy/GL/GLCopyRef.hpp>

class GLUniformBlockRef : public GLCopyRef<GLuint> {
public:
	GLUniformBlockRef();
	GLUniformBlockRef(GLuint uniform_block_index);
	GLUniformBlockRef(GLUniformBlockRef &copy);
	GLUniformBlockRef(GLUniformBlockRef &&move);

	GLUniformBlockRef &operator=(const GLUniformBlockRef &copy);
	GLUniformBlockRef &operator=(GLUniformBlockRef &&move);

	void BindToBlock(GLuint program, GLuint block_binding);
};

#endif /* GLUNIFORMBLOCKREF_HPP */

