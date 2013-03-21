#include <abxy/primitive/Primitive.hpp>

#include <abxy/loader/ResourceLoader.hpp>
#include <abxy/loader/LoadData.hpp>

void Primitive::SetupArrays(const PrimitiveData &data) {
	vertex_buffer->Bind();
	vertex_buffer->SetData(
		data.attrib_data.size() * sizeof(float),
		data.attrib_data.data(),
		GL_STATIC_DRAW
	);
	vertex_buffer->Unbind();

	num_indices = data.index_data.size();

	index_buffer->Bind();
	index_buffer->SetData(
		data.index_data.size() * sizeof(float),
		data.index_data.data(),
		GL_STATIC_DRAW
	);
	index_buffer->Unbind();
}

void Primitive::SetupVertexArray(
	GLVertexArrayRef &vertex_array,
	std::shared_ptr<GLProgram> program
) {
	vertex_array.Bind();
	vertex_buffer->Bind();

	for (auto &attrib_data : attribs) {
		GLAttribRef attrib =
			program->GetAttribLocation(attrib_data.name);
		attrib.Enable();
		attrib.SetPointer(
			attrib_data.size, attrib_data.type,
			attrib_data.normalized, 0,
			reinterpret_cast<void*>(attrib_data.pos)
		);
	}

	index_buffer->Bind();
	vertex_array.Unbind();
}

Primitive::Primitive(const PrimitiveData &data)
: attribs(data.attribs)
, vertex_buffer(std::make_shared<GLBufferRef<GL_ARRAY_BUFFER>>())
, index_buffer(std::make_shared<GLBufferRef<GL_ELEMENT_ARRAY_BUFFER>>())
{
	SetupArrays(data);
}

Primitive::Primitive(Primitive &&move)
: attribs(std::move(move.attribs))
, vertex_buffer(std::move(move.vertex_buffer))
, index_buffer(std::move(move.index_buffer))
, num_indices(move.num_indices)
{
	
}

