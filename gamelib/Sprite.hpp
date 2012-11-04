#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <gamelib/TexturePrimitive.inl>
#include <gamelib/SquarePrimitive.inl>

class Sprite : public TexturePrimitive, public SquarePrimitive {
public:
	Sprite(std::string texture_name);

	virtual void Register(World *world);
	virtual void Draw(Matrix4 &matrix) const;
};

#endif /* SPRITE_HPP */

