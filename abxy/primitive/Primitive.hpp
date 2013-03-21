#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

#include <vector>

#include <abxy/GL/GL.hpp>
#include <abxy/GL/GLProgram.hpp>
#include <abxy/GL/GLBufferRef.hpp>
#include <abxy/GL/GLVertexArrayRef.hpp>

#include <abxy/primitive/PrimitiveData.hpp>
#include <abxy/primitive/BoundPrimitive.hpp>

class LoadData;

class Primitive {
	std::vector<PrimitiveData::AttribData> attribs;

	std::shared_ptr<GLBufferRef<GL_ARRAY_BUFFER>> vertex_buffer;
	std::shared_ptr<GLBufferRef<GL_ELEMENT_ARRAY_BUFFER>> index_buffer;
	int num_indices;

	void SetupVertexArray(
		GLVertexArrayRef &vertex_array,
		std::shared_ptr<GLProgram> program
	);
	void SetupArrays(const PrimitiveData &data);
public:
	Primitive(const PrimitiveData &data);
	Primitive(Primitive &p) = delete;
	Primitive(Primitive &&move);
	virtual ~Primitive() {}

	template <typename T = BoundPrimitive>
	std::shared_ptr<BoundPrimitive> Bind(
		std::shared_ptr<GLProgram> program
	) {
		std::shared_ptr<T> bound_prim = std::make_shared<T>(
			num_indices, vertex_buffer, index_buffer
		);

		SetupVertexArray(bound_prim->GetVertexArray(), program);

		return std::dynamic_pointer_cast<BoundPrimitive>(bound_prim);
	}
};

#endif /* PRIMITIVE_HPP */

