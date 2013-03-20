#include <abxy/primitive/SquarePrimitive.hpp>

SquarePrimitive::SquarePrimitive(std::string program_name)
: Primitive(program_name)
{
	float varray[] = {
		-0.5, -0.5, 0.0, 1.0,
		 0.5, -0.5, 0.0, 1.0,
		-0.5,  0.5, 0.0, 1.0,
		 0.5,  0.5, 0.0, 1.0
	};
	std::vector<float> verts(std::begin(varray), std::end(varray));

	unsigned int iarray[] = {
		0, 1, 2,
		2, 1, 3
	};
	std::vector<unsigned int> indices(std::begin(iarray), std::end(iarray));

	AddAttrib("position", 4, verts);
	AddIndices(indices);
}

SquarePrimitive::~SquarePrimitive() {
	
}

