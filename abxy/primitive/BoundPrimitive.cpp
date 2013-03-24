#include <abxy/primitive/BoundPrimitive.hpp>

BoundPrimitive::BoundPrimitive(
	std::shared_ptr<GLProgram> program,
	GLsizei num_indices,
	std::shared_ptr<GLBufferRef<GL_ARRAY_BUFFER>> vertex_buffer,
	std::shared_ptr<GLBufferRef<GL_ELEMENT_ARRAY_BUFFER>> index_buffer
)
: program(program)
, vertex_buffer(vertex_buffer)
, index_buffer(index_buffer)
, num_indices(num_indices)
{
	model_matrix_attrib_loc =
		program->GetUniformLocation("model_to_world_matrix");
}

BoundPrimitive::BoundPrimitive(BoundPrimitive &&move)
: vertex_array(std::move(move.vertex_array))
, vertex_buffer(std::move(move.vertex_buffer))
, index_buffer(std::move(move.index_buffer))
, num_indices(move.num_indices)
{ }

void BoundPrimitive::DrawAll(const Matrix4 &model_matrix) const {
	DrawAllBase(model_matrix, 0);
}

void BoundPrimitive::DrawIndices(const Matrix4 &model_matrix, GLsizei start,
                                 GLsizei count) const {
	DrawIndicesBase(model_matrix, start, count, 0);
}

void BoundPrimitive::DrawAllBase(const Matrix4 &model_matrix, int base) const {
	DrawIndicesBase(model_matrix, 0, num_indices, base);
}

void BoundPrimitive::DrawIndicesBase(const Matrix4 &model_matrix, GLsizei start,
                                     GLsizei count, GLint base) const {
	program->Use();
	vertex_array.Bind();

	InnerDraw();

	model_matrix_attrib_loc.SetMatrix4fv(
		1, GL_FALSE, model_matrix.GetData()
	);

	glDrawElementsBaseVertex(
		GL_TRIANGLES, count, GL_UNSIGNED_INT,
		reinterpret_cast<void*>(start), base
	);

	vertex_array.Unbind();
	program->Unuse();
}
