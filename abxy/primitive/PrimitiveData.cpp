#include <abxy/primitive/PrimitiveData.hpp>

namespace {
	template <typename T>
	std::vector<uint8_t> ConvertToBytes(const std::vector<T> &data) {
		std::vector<uint8_t> byte_data;

		for (float t : data) {
			uint8_t *bytes = reinterpret_cast<uint8_t*>(&t);

			byte_data.insert(
				byte_data.end(),
				bytes, bytes+sizeof(t)
			);
		}

		return byte_data;
	}
}

void PrimitiveData::AddAttrib(
	const std::string &name,
	bool integer_attrib,
	GLint size,
	GLenum type,
	GLboolean normalized,
	const std::vector<uint8_t> &data
) {
	size_t pos = attrib_data.size();

	AttribData attrib {
		name,
		integer_attrib,
		size,
		type,
		normalized,
		pos
	};

	attrib_data.insert(attrib_data.end(), data.begin(), data.end());
	attribs.push_back(attrib);
}

void PrimitiveData::AddFloatAttrib(
	const std::string &name,
	GLint size,
	const std::vector<float> &data
) {
	AddAttrib(name, false, size, GL_FLOAT, GL_FALSE, ConvertToBytes(data));
}

void PrimitiveData::AddIntAttrib(
	const std::string &name,
	bool integer_attrib,
	GLint size,
	GLboolean normalized,
	const std::vector<int> &data
) {
	AddAttrib(
		name, integer_attrib, size, GL_INT,
		normalized, ConvertToBytes(data)
	);
}

void PrimitiveData::AddIndices(const std::vector<unsigned int> &indices) {
	index_data.insert(index_data.end(), indices.begin(), indices.end());
}
