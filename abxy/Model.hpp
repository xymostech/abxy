#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <string>

#include <abxy/primitive/Primitive.hpp>
#include <abxy/loader/LoadData.hpp>

class Model {
	typedef std::vector<std::string>::const_iterator token_iterator;

	class Object {
	public:
		class AttribData {
		public:
			std::string name;
			std::vector<float> data;
			int size;
		};

		std::string name;
		std::vector<AttribData> attribs;
		std::vector<unsigned int> indices;
	};

	std::vector<Object> objects;
	std::vector<Primitive> prims;

	std::vector<std::shared_ptr<BoundPrimitive>> bound_prims;

	std::shared_ptr<GLProgram> program;

	static Object ReadObject(token_iterator &it);
	static Object::AttribData ReadAttrib(token_iterator &it);
	static std::vector<unsigned int> ReadIndices(token_iterator &it);

	static PrimitiveData SetupPrimitive(const Object &o);
	static std::vector<std::string> GetTokens(std::string file);
public:
	Model(std::string model_file);

	void Bind(std::shared_ptr<GLProgram> program);

	void Draw(Matrix4 model_matrix) const;
};

#endif /* MODEL_HPP */

