#ifndef PRIMITIVEDATA_HPP
#define PRIMITIVEDATA_HPP

#include <string>
#include <vector>

#include <cstdint>

#include <abxy/GL/GL.hpp>

class PrimitiveData {
	struct AttribData {
		std::string name;
		bool integer_attrib;
		GLint size;
		GLenum type;
		GLboolean normalized;
		size_t pos;
	};

	std::vector<AttribData> attribs;
	std::vector<uint8_t> attrib_data;
	std::vector<unsigned int> index_data;
public:
	void AddAttrib(
		const std::string &name,
		bool integer_attrib,
		GLint size,
		GLenum type,
		GLboolean normalized,
		const std::vector<uint8_t> &data
	);

	void AddFloatAttrib(
		const std::string &name,
		GLint size,
		const std::vector<float> &data
	);

	void AddIntAttrib(
		const std::string &name,
		bool integer_attrib,
		GLint size,
		GLboolean normalized,
		const std::vector<int> &data
	);

	void AddIndices(const std::vector<unsigned int> &indices);

	friend class Primitive;
};


#endif /* PRIMITIVEDATA_HPP */

