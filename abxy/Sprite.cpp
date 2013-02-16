#include <abxy/Sprite.hpp>

Sprite::Sprite(std::string texture_name)
: Primitive("res/standard")
, TexturePrimitive("res/standard", texture_name)
, SquarePrimitive("res/standard")
{
	float varray[] = {
		0.0, 1.0,
		1.0, 1.0,
		0.0, 0.0,
		1.0, 0.0,
	};
	std::vector<float> verts(std::begin(varray), std::end(varray));

	AddTextureCoords(verts);
}

void Sprite::Register(World *world) {
	TexturePrimitive::Register(world);
}

void Sprite::Draw(Matrix4 &matrix) const {
	TexturePrimitive::DrawAll(matrix);
}

