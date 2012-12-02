#ifndef SPRITE_INL
#define SPRITE_INL

#include <gamelib/Sprite.hpp>

Sprite::Sprite(std::string texture_name)
: Primitive("standard")
, TexturePrimitive("standard", texture_name)
, SquarePrimitive("standard")
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

#endif /* SPRITE_INL */

