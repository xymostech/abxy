#ifndef PRIMITIVE2D_HPP
#define PRIMITIVE2D_HPP

#include <vector>

#include <gamelib/GL/GL.hpp>
#include <gamelib/GL/GLProgram.hpp>
#include <gamelib/GL/GLBufferRef.hpp>
#include <gamelib/GL/GLVertexArrayRef.hpp>
#include <gamelib/GL/GLAttribRef.hpp>
#include <gamelib/Vector.hpp>
#include <gamelib/ResourceLoader.hpp>
#include <gamelib/Matrix.hpp>

class Primitive2d {
	// Data to describe the primitive
	std::string program_name;

	int num_indices;

	int vertex_pos, color_pos, texture_pos;
	bool use_vertex, use_color, use_texture;

	std::string texture_name;

	std::vector<float> vertex_data;
	std::vector<unsigned int> index_data;

	// Stored OpenGL data
	GLBufferRef<GL_ARRAY_BUFFER> vertex_buffer;
	GLBufferRef<GL_ELEMENT_ARRAY_BUFFER> index_buffer;
	GLVertexArrayRef vertex_array;

	GLAttribRef position_loc, color_loc, texture_loc;

	GLUniformRef model_matrix_loc, sampler_loc;

	std::shared_ptr<GLProgram> program;
	std::shared_ptr<Texture> texture;

	void SetupArrays() {
		vertex_buffer.Bind();
		vertex_buffer.SetData(vertex_data.size() * sizeof(float), vertex_data.data(), GL_STATIC_DRAW);
		vertex_buffer.Unbind();

		num_indices = index_data.size();

		index_buffer.Bind();
		index_buffer.SetData(index_data.size() * sizeof(float), index_data.data(), GL_STATIC_DRAW);
		index_buffer.Unbind();
	}

	void SetupVertexArray() {
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

	void SetupTexture() {
		program->Use();
		texture->BindSampler(sampler_loc);
		program->Unuse();
	}
public:
	Primitive2d(std::string program_name)
	: program_name(program_name)
	, use_vertex(false)
	, use_color(false)
	, use_texture(false)
	{
		
	}

	Primitive2d &AddVertices(const std::vector<float> &verts) {
		vertex_pos = vertex_data.size();
		vertex_data.insert(
			vertex_data.end(),
			verts.begin(),
			verts.end()
		);
		use_vertex = true;
		return *this;
	}

	Primitive2d &AddColors(const std::vector<float> &colors) {
		color_pos = vertex_data.size();
		vertex_data.insert(
			vertex_data.end(),
			colors.begin(),
			colors.end()
		);
		use_color = true;
		return *this;
	}

	Primitive2d &AddTexture(const std::vector<float> &texture) {
		texture_pos = vertex_data.size();
		vertex_data.insert(
			vertex_data.end(),
			texture.begin(),
			texture.end()
		);
		use_texture = true;
		return *this;
	}

	Primitive2d &AddIndices(const std::vector<unsigned int> &indices) {
		index_data.insert(
			index_data.end(),
			indices.begin(),
			indices.end()
		);
		return *this;
	}

	Primitive2d &UseTexture(std::string t_name) {
		texture_name = t_name;
		return *this;
	}

	void Setup() {
		SetupArrays();
	}

	virtual void Register(World *world) {
		program = world->GetParentStage().GetResources().GetGLProgram("standard");
		SetupVertexArray();

		if (use_texture) {
			texture = world->GetParentStage().GetResources().GetTexture(texture_name);
			SetupTexture();
		}
	}

	virtual void Draw(Matrix4 &matrix) const {
		program->Use();
		vertex_array.Bind();

		model_matrix_loc.SetMatrix4fv(1, GL_FALSE, matrix.GetData());

		glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_INT, 0);

		vertex_array.Unbind();
		program->Unuse();
	}
};

#endif /* PRIMITIVE2D_HPP */

