#ifndef SPRITE_INL
#define SPRITE_INL

#include <gamelib/Sprite.hpp>

Sprite::Sprite(std::string texture_name)
: Primitive("standard")
, TexturePrimitive("standard", texture_name)
{
	float varray[] = {
		-0.5, -0.5, 0.0, 1.0,
		 0.5, -0.5, 0.0, 1.0,
		-0.5,  0.5, 0.0, 1.0,
		 0.5,  0.5, 0.0, 1.0
	};
	std::vector<float> verts(std::begin(varray), std::end(varray));

	float tcoordarray[] = {
		0.0, 0.0,
		1.0, 0.0,
		0.0, 1.0,
		1.0, 1.0
	};
	std::vector<float> tcoords(std::begin(tcoordarray), std::end(tcoordarray));

	unsigned int iarray[] = {
		0, 1, 2,
		2, 1, 3
	};
	std::vector<unsigned int> indices(std::begin(iarray), std::end(iarray));

	AddVertices(verts);
	AddTexture(tcoords);
	AddIndices(indices);
}

void Sprite::Register(World *world) {
	TexturePrimitive::Register(world);
}

void Sprite::Draw(Matrix4 &matrix) const {
	TexturePrimitive::DrawAll(matrix);
}

#endif /* SPRITE_INL */

