#ifndef PRIMITIVE_INL
#define PRIMITIVE_INL

#include <gamelib/Primitive.hpp>

#include <gamelib/ResourceLoader.inl>

void Primitive::SetupArrays() {
	vertex_buffer.Bind();
	vertex_buffer.SetData(
		vertex_data.size() * sizeof(float),
		vertex_data.data(),
		GL_STATIC_DRAW
	);
	vertex_buffer.Unbind();

	vertex_data.clear();

	num_indices = index_data.size();

	index_buffer.Bind();
	index_buffer.SetData(
		index_data.size() * sizeof(float),
		index_data.data(),
		GL_STATIC_DRAW
	);
	index_buffer.Unbind();

	index_data.clear();
}

void Primitive::SetupVertexArray() {
	vertex_array.Bind();
	vertex_buffer.Bind();

	auto end = attribs.end();
	for (auto it = attribs.begin(); it != end; ++it) {
		GLAttribRef attrib = program->GetAttribLocation(it->name);
		attrib.Enable();
		attrib.SetPointer(
			it->size, GL_FLOAT, GL_FALSE, 0,
			(void*)(it->pos * sizeof(float))
		);
	}

	index_buffer.Bind();
	vertex_array.Unbind();
}

void Primitive::InnerDraw() const {
	
}

Primitive::Primitive(std::string program_name)
: program_name(program_name)
{
	
}

Primitive::~Primitive() {
	
}

void Primitive::AddAttrib(const std::string &name,
                          int size,
                          const std::vector<float> &data)
{
	AttribData attrib;

	attrib.name = name;
	attrib.pos = vertex_data.size();
	attrib.size = size;

	attribs.push_back(attrib);

	vertex_data.insert(
		vertex_data.end(),
		data.begin(),
		data.end()
	);
}

void Primitive::AddIndices(const std::vector<unsigned int> &indices) {
	index_data.insert(
		index_data.end(),
		indices.begin(),
		indices.end()
	);
}

void Primitive::Register(World *world) {
	program = world->GetParentStage()->GetProgramLoader()->Load(program_name);

	SetupVertexArray();
	SetupArrays();

	model_matrix_loc = program->GetUniformLocation("model_to_world_matrix");
}

void Primitive::DrawAll(const Matrix4 &model_matrix) const {
	DrawAllBase(model_matrix, 0);
}

void Primitive::DrawIndices(const Matrix4 &model_matrix,
                            GLsizei start, GLsizei count) const {
	DrawIndicesBase(model_matrix, start, count, 0);
}

void Primitive::DrawAllBase(const Matrix4 &model_matrix, int base) const {
	DrawIndicesBase(model_matrix, 0, num_indices, base);
}

void Primitive::DrawIndicesBase(const Matrix4 &model_matrix,
                             GLsizei start, GLsizei count,
                             GLint base) const {
	program->Use();
	vertex_array.Bind();

	InnerDraw();

	model_matrix_loc.SetMatrix4fv(1, GL_FALSE, model_matrix.GetData());

	glDrawElementsBaseVertex(
		GL_TRIANGLES, count, GL_UNSIGNED_INT,
		(void *)start, base
	);

	vertex_array.Unbind();
	program->Unuse();
}

#endif /* PRIMITIVE_INL */

