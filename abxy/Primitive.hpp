#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <vector>

#include <abxy/GL/GL.hpp>
#include <abxy/GL/GLProgram.hpp>
#include <abxy/GL/GLBufferRef.hpp>
#include <abxy/GL/GLVertexArrayRef.hpp>
#include <abxy/World.hpp>

struct AttribData {
	std::string name;
	size_t size;
	size_t pos;
};

class Primitive {
	// Data to describe the primitive
	std::string program_name;

	std::vector<AttribData> attribs;
	std::vector<float> vertex_data;
	std::vector<unsigned int> index_data;

	// Stored OpenGL data
	GLBufferRef<GL_ARRAY_BUFFER> vertex_buffer;
	GLBufferRef<GL_ELEMENT_ARRAY_BUFFER> index_buffer;
	GLVertexArrayRef vertex_array;

	GLUniformRef model_matrix_loc;

	int num_indices;

	void SetupVertexArray();
	void SetupArrays();
protected:
	std::shared_ptr<GLProgram> program;

	virtual void InnerDraw() const;
public:
	Primitive(std::string program_name);
	virtual ~Primitive();

	void AddAttrib(const std::string &name,
	               int size,
	               const std::vector<float> &data);
	void AddIndices(const std::vector<unsigned int> &indices);

	virtual void Register(World *world);

	virtual void DrawAll(const Matrix4 &model_matrix) const;
	virtual void DrawIndices(const Matrix4 &model_matrix,
	                         GLsizei start, GLsizei count) const;
	virtual void DrawAllBase(const Matrix4 &model_matrix, int base) const;
	virtual void DrawIndicesBase(const Matrix4 &model_matrix,
	                             GLsizei start, GLsizei count,
	                             GLint base) const;
};

#endif /* PRIMITIVE_HPP */

