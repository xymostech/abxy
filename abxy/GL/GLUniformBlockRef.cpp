#include <abxy/GL/GLUniformBlockRef.hpp>

#include <utility>

GLUniformBlockRef::GLUniformBlockRef()
: GLCopyRef<GLuint>()
{ }

GLUniformBlockRef::GLUniformBlockRef(GLuint uniform_block_index)
: GLCopyRef<GLuint>(uniform_block_index)
{ }

GLUniformBlockRef::GLUniformBlockRef(GLUniformBlockRef &copy)
: GLCopyRef<GLuint>(copy)
{ }

GLUniformBlockRef::GLUniformBlockRef(GLUniformBlockRef &&move)
: GLCopyRef<GLuint>(std::move(move))
{ }

GLUniformBlockRef &GLUniformBlockRef::operator=(const GLUniformBlockRef &copy) {
	GLCopyRef<GLuint>::operator=(copy);

	return *this;
}

GLUniformBlockRef &GLUniformBlockRef::operator=(GLUniformBlockRef &&move) {
	GLCopyRef<GLuint>::operator=(std::move(move));

	return *this;
}

void GLUniformBlockRef::BindToBlock(GLuint program, GLuint block_binding) {
	glUniformBlockBinding(program, GetRef(), block_binding);
}

