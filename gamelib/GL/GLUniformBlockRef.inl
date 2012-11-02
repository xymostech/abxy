#ifndef GLUNIFORMBLOCKREF_INL
#define GLUNIFORMBLOCKREF_INL

#include <gamelib/GL/GLUniformBlockRef.hpp>

GLUniformBlockRef::GLUniformBlockRef()
: uniform_block_index(0)
{
	
}

GLUniformBlockRef::GLUniformBlockRef(GLuint uniform_block_index)
: uniform_block_index(uniform_block_index)
{
	
}

void GLUniformBlockRef::BindToBlock(GLuint program, GLuint block_binding) {
	glUniformBlockBinding(program, uniform_block_index, block_binding);
}

#endif /* GLUNIFORMBLOCKREF_INL */

