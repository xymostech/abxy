#ifndef BOUNDPRIMITIVE_HPP
#define BOUNDPRIMITIVE_HPP

#include <vector>

#include <abxy/GL/GL.hpp>
#include <abxy/GL/GLProgram.hpp>
#include <abxy/GL/GLBufferRef.hpp>
#include <abxy/GL/GLVertexArrayRef.hpp>

class BoundPrimitive {
	GLVertexArrayRef vertex_array;
	std::shared_ptr<GLBufferRef<GL_ARRAY_BUFFER>> vertex_buffer;
	std::shared_ptr<GLBufferRef<GL_ELEMENT_ARRAY_BUFFER>> index_buffer;
	GLsizei num_indices;
protected:
	void InnerDraw() const {}

	GLVertexArrayRef &GetVertexArray() { return vertex_array; }
public:
	BoundPrimitive(
		GLsizei num_indices,
		std::shared_ptr<GLBufferRef<GL_ARRAY_BUFFER>> vertex_buffer,
		std::shared_ptr<GLBufferRef<GL_ELEMENT_ARRAY_BUFFER>> index_buffer
	);
	BoundPrimitive(BoundPrimitive &&move);

	virtual void DrawAll() const;
	virtual void DrawIndices(GLsizei start, GLsizei count) const;
	virtual void DrawAllBase(int base) const;
	virtual void DrawIndicesBase(GLsizei start, GLsizei count,
	                             GLint base) const;

	friend class Primitive;
};

#endif /* BOUNDPRIMITIVE_HPP */

