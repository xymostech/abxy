#ifndef PRIMITIVE2D_INL
#define PRIMITIVE2D_INL

#include <gamelib/Primitive2d.hpp>

void Primitive2d::SetupArrays() {
	vertex_buffer.Bind();
	vertex_buffer.SetData(vertex_data.size() * sizeof(float), vertex_data.data(), GL_STATIC_DRAW);
	vertex_buffer.Unbind();

	num_indices = index_data.size();

	index_buffer.Bind();
	index_buffer.SetData(index_data.size() * sizeof(float), index_data.data(), GL_STATIC_DRAW);
	index_buffer.Unbind();
}

void Primitive2d::SetupVertexArray() {
	vertex_array.Bind();

	vertex_buffer.Bind();

	if (use_vertex) {
		position_loc = program->GetAttribLocation("position");
		position_loc.Enable();
		position_loc.SetPointer(
			4, GL_FLOAT, GL_FALSE, 0,
			(void*)(vertex_pos * sizeof(float))
		);
	}

	if (use_color) {
		color_loc = program->GetAttribLocation("color");
		color_loc.Enable();
		color_loc.SetPointer(
			4, GL_FLOAT, GL_FALSE, 0,
			(void*)(color_pos * sizeof(float))
		);
	}

	if (use_texture) {
		texture_loc = program->GetAttribLocation("texcoord");
		texture_loc.Enable();
		texture_loc.SetPointer(
			2, GL_FLOAT, GL_FALSE, 0,
			(void*)(texture_pos * sizeof(float))
		);

		sampler_loc = program->GetUniformLocation("textureSampler");
	}

	model_matrix_loc = program->GetUniformLocation("model_to_world_matrix");

	index_buffer.Bind();

	vertex_array.Unbind();
}

void Primitive2d::SetupTexture() {
	program->Use();
	texture->BindSampler(sampler_loc);
	program->Unuse();
}

Primitive2d::Primitive2d(std::string program_name)
: program_name(program_name)
, use_vertex(false)
, use_color(false)
, use_texture(false)
{
	
}

Primitive2d &Primitive2d::AddVertices(const std::vector<float> &verts) {
	vertex_pos = vertex_data.size();
	vertex_data.insert(
		vertex_data.end(),
		verts.begin(),
		verts.end()
	);
	use_vertex = true;
	return *this;
}

Primitive2d &Primitive2d::AddColors(const std::vector<float> &colors) {
	color_pos = vertex_data.size();
	vertex_data.insert(
		vertex_data.end(),
		colors.begin(),
		colors.end()
	);
	use_color = true;
	return *this;
}

Primitive2d &Primitive2d::AddTexture(const std::vector<float> &texture) {
	texture_pos = vertex_data.size();
	vertex_data.insert(
		vertex_data.end(),
		texture.begin(),
		texture.end()
	);
	use_texture = true;
	return *this;
}

Primitive2d &Primitive2d::AddIndices(const std::vector<unsigned int> &indices) {
	index_data.insert(
		index_data.end(),
		indices.begin(),
		indices.end()
	);
	return *this;
}

Primitive2d &Primitive2d::UseTexture(std::string t_name) {
	texture_name = t_name;
	return *this;
}

void Primitive2d::Setup() {
	SetupArrays();
}

void Primitive2d::Register(World *world) {
	program = world->GetParentStage()->GetProgramLoader()->Load("standard");
	SetupVertexArray();

	if (use_texture) {
		texture = world->GetParentStage()->GetTextureLoader()->Load(texture_name);
		SetupTexture();
	}
}

void Primitive2d::Draw(Matrix4 &matrix) const {
	program->Use();
	vertex_array.Bind();

	model_matrix_loc.SetMatrix4fv(1, GL_FALSE, matrix.GetData());

	glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_INT, 0);

	vertex_array.Unbind();
	program->Unuse();
}

#endif /* PRIMITIVE2D_INL */

