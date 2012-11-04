#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <gamelib/TexturePrimitive.inl>

class Sprite : protected TexturePrimitive {
public:
	Sprite(std::string texture_name);

	virtual void Register(World *world);
	virtual void Draw(Matrix4 &matrix) const;
};

#endif /* SPRITE_HPP */

