#ifndef GLUNIFORMBLOCKREF_HPP
#define GLUNIFORMBLOCKREF_HPP

#include <gamelib/GL/GL.hpp>

class GLUniformBlockRef {
	GLuint uniform_block_index;
public:
	GLUniformBlockRef();
	GLUniformBlockRef(GLuint uniform_block_index);

	void BindToBlock(GLuint program, GLuint block_binding);
};

#endif /* GLUNIFORMBLOCKREF_HPP */

