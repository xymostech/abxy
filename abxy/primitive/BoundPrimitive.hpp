#ifndef BOUNDPRIMITIVE_HPP
#define BOUNDPRIMITIVE_HPP

#include <vector>

#include <abxy/GL/GL.hpp>
#include <abxy/GL/GLProgram.hpp>
#include <abxy/GL/GLBufferRef.hpp>
#include <abxy/GL/GLVertexArrayRef.hpp>
#include <abxy/GL/GLUniformRef.hpp>

class BoundPrimitive {
	std::shared_ptr<GLProgram> program;
	GLVertexArrayRef vertex_array;
	std::shared_ptr<GLBufferRef<GL_ARRAY_BUFFER>> vertex_buffer;
	std::shared_ptr<GLBufferRef<GL_ELEMENT_ARRAY_BUFFER>> index_buffer;
	GLsizei num_indices;

	GLUniformRef model_matrix_attrib_loc;
protected:
	void InnerDraw() const {}

	GLVertexArrayRef &GetVertexArray() { return vertex_array; }
public:
	BoundPrimitive(
		std::shared_ptr<GLProgram> program,
		GLsizei num_indices,
		std::shared_ptr<GLBufferRef<GL_ARRAY_BUFFER>> vertex_buffer,
		std::shared_ptr<GLBufferRef<GL_ELEMENT_ARRAY_BUFFER>> index_buffer
	);
	BoundPrimitive(BoundPrimitive &&move);

	virtual void DrawAll(const Matrix4 &model_matrix) const;
	virtual void DrawIndices(const Matrix4 &model_matrix, GLsizei start,
	                         GLsizei count) const;
	virtual void DrawAllBase(const Matrix4 &model_matrix, int base) const;
	virtual void DrawIndicesBase(const Matrix4 &model_matrix, GLsizei start,
	                             GLsizei count, GLint base) const;

	friend class Primitive;
};

#endif /* BOUNDPRIMITIVE_HPP */

