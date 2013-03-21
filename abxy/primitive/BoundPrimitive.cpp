#include <abxy/primitive/BoundPrimitive.hpp>

BoundPrimitive::BoundPrimitive(GLsizei num_indices)
: num_indices(num_indices)
{ }

BoundPrimitive::BoundPrimitive(BoundPrimitive &&copy)
: vertex_array(std::move(copy.vertex_array))
, num_indices(copy.num_indices)
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
