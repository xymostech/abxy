#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <vector>

#include <gamelib/GL/GL.hpp>
#include <gamelib/GL/GLProgram.inl>
#include <gamelib/GL/GLBufferRef.inl>
#include <gamelib/GL/GLVertexArrayRef.inl>
#include <gamelib/GL/GLAttribRef.inl>
#include <gamelib/Vector.inl>
#include <gamelib/ResourceLoader.inl>
#include <gamelib/Matrix.inl>
#include <gamelib/Texture.inl>

class Primitive {
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

	GLUniformRef model_matrix_loc, sampler_loc, use_texture_loc;

	std::shared_ptr<GLProgram> program;
	std::shared_ptr<Texture> texture;

	void SetupArrays();
	void SetupVertexArray();
	void SetupTexture();
public:
	Primitive(std::string program_name);

	Primitive &AddVertices(const std::vector<float> &verts);
	Primitive &AddColors(const std::vector<float> &colors);
	Primitive &AddTexture(const std::vector<float> &texture);
	Primitive &AddIndices(const std::vector<unsigned int> &indices);

	Primitive &UseTexture(std::string t_name);

	void Setup();
	virtual void Register(World *world);

	virtual void Draw(Matrix4 &matrix) const;
};

#endif /* PRIMITIVE_HPP */

