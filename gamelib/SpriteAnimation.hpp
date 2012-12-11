#ifndef SPRITEANIMATION_HPP
#define SPRITEANIMATION_HPP

#include <vector>

#include <gamelib/Sprite.hpp>

class SpriteAnimation {
	std::vector<std::shared_ptr<Sprite>> sprites;
public:
	SpriteAnimation(const std::vector<std::string> &v);
	virtual ~SpriteAnimation();

	virtual void Register(World *world);
	virtual void Draw(int sprite, Matrix4 &matrix) const;
};

#endif /* SPRITEANIMATION_HPP */

