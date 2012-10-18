#ifndef GLUNIFORMBLOCKREF_HPP
#define GLUNIFORMBLOCKREF_HPP

#include <gamelib/GL/GL.hpp>

class GLUniformBlockRef {
	GLuint uniform_block_index;
public:
	GLUniformBlockRef()
	: uniform_block_index(0)
	{
		
	}

	GLUniformBlockRef(GLuint uniform_block_index)
	: uniform_block_index(uniform_block_index)
	{
		
	}

	void BindToBlock(GLuint program, GLuint block_binding) {
		glUniformBlockBinding(program, uniform_block_index, block_binding);
	}
};

#endif /* GLUNIFORMBLOCKREF_HPP */

