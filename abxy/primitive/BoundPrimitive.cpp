#include <abxy/primitive/BoundPrimitive.hpp>

BoundPrimitive::BoundPrimitive(
	GLsizei num_indices,
	std::shared_ptr<GLBufferRef<GL_ARRAY_BUFFER>> vertex_buffer,
	std::shared_ptr<GLBufferRef<GL_ELEMENT_ARRAY_BUFFER>> index_buffer
)
: vertex_buffer(vertex_buffer)
, index_buffer(index_buffer)
, num_indices(num_indices)
{ }

BoundPrimitive::BoundPrimitive(BoundPrimitive &&move)
: vertex_array(std::move(move.vertex_array))
, vertex_buffer(std::move(move.vertex_buffer))
, index_buffer(std::move(move.index_buffer))
, num_indices(move.num_indices)
{ }

void BoundPrimitive::DrawAll() const {
	DrawAllBase(0);
}

void BoundPrimitive::DrawIndices(GLsizei start, GLsizei count) const {
	DrawIndicesBase(start, count, 0);
}

void BoundPrimitive::DrawAllBase(int base) const {
	DrawIndicesBase(0, num_indices, base);
}

void BoundPrimitive::DrawIndicesBase(GLsizei start, GLsizei count,
                                     GLint base) const {
	vertex_array.Bind();

	InnerDraw();

	glDrawElementsBaseVertex(
		GL_TRIANGLES, count, GL_UNSIGNED_INT,
		reinterpret_cast<void*>(start), base
	);

	vertex_array.Unbind();
}
