#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <string>

#include <abxy/Primitive.hpp>

class Model {
	typedef std::vector<std::string>::const_iterator token_iterator;

	class Object {
	public:
		std::string name;
		std::vector<float> verts, colors;
		std::vector<unsigned int> indices;
	};

	std::vector<Object> objects;
	std::vector<Primitive> prims;

	static Object ReadObject(token_iterator &it);
	static std::vector<float> ReadColors(token_iterator &it);
	static std::vector<float> ReadVerts(token_iterator &it);
	static std::vector<unsigned int> ReadIndices(token_iterator &it);

	static Primitive MakePrimitive(const Object &o);
	static std::vector<std::string> GetTokens(std::string file);
public:
	Model(std::string model_file);

	void OnLoad(LoadData &data);
	void OnUnload();

	void Draw(Matrix4 model_matrix) const;
};

#endif /* MODEL_HPP */

